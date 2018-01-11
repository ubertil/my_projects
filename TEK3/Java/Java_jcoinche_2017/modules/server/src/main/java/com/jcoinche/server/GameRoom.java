package com.jcoinche.server;

import com.jcoinche.protobuf.JCoincheProtocol.GameRequest;
import com.jcoinche.protobuf.JCoincheProtocol.GameResponse;
import com.jcoinche.rules.GameRules;
import io.netty.channel.Channel;

/**
 * This class represents a GameRoom which role is to let 4 players play together.
 * This let us abstract all the administration part of people joining and leaving a game.
 *
 * Once 4 players are connected to the same GameRoom, <b>a game starts</b>
 * If <b>any player</b> leaves during the game, the session is restarted for everyone in the room.
 *
 * @author uberti_l
 * @author grella_c
 * @see GameRules
 * @see GameManager
 * @version 1.0
 */
public class GameRoom {
    /**
     * Each GameRoom possesses it's own GameRules entity to manage the game once started
     */
    private GameRules rules = new GameRules();

    /**
     * The GameRoom name
     * During construction, append the room number from the list (for example FooBar<b>4</b>)
     */
    public String ROOM_NAME = "JCoincheGameRoom";

    /**
     * Present the server to connected users
     */
    public String CREATORS = "Come GRELLARD and Louis-Emile UBERTI";
    private final String asciiArt = "      _  ____ ___ ___ _   _  ____ _   _ _____\n"
            + "    | |/ ___/ _ \\_ _| \\ | |/ ___| | | | ____|\n"
            + " _  | | |  | | | | ||  \\| | |   | |_| |  _|  \n"
            + "| |_| | |__| |_| | || |\\  | |___|  _  | |___ \n"
            + " \\___/ \\____\\___/___|_| \\_|\\____|_| |_|_____|\n";

    /**
     * How many players are connected in the GameRoom
     */
    private Integer nbPlayers = 0;

    /**
     * Boolean to tell if the game is started in this room
     */
    private Boolean gameReady = false;

    /**
     * Store the socket from each player connected so we can identity them
     */
    private Channel[] players = new Channel[4];

    public GameRoom(Integer id) {
        ROOM_NAME = ROOM_NAME + id.toString();
        for (int i = 0; i < 4; ++i) {
            players[i] = null;
        }
    }

    public final Integer getNbPlayers() {
        return (nbPlayers);
    }

    public final Integer getPlayerIdx(Channel ch) {
        if (ch == null) {
            return -1;
        }
        for (int i = 0; i < 4; ++i) {
            if (players[i] != null && players[i].equals(ch)) {
                return (i);
            }
        }
        return (-1);
    }

    public final Boolean isReady() {
        return (gameReady);
    }

    /**
     * Add a player to the {@code players} entity
     *
     * If the forth player is added, launch the game
     * @param ch Represents <i>the communication channel</i> between the server and the client
     * @return
     */
    public final Boolean addPlayer(Channel ch) {
        // Room is full
        if (nbPlayers == 4)
            return false;
        int idx = -1;
        while (++idx < 4) {
            if (players[idx] == null) {
                players[idx] = ch;
                break;
            }
        }
        nbPlayers += 1;
        // Greet the new player on our gameRoom
        GameResponse.Builder builder = GameResponse.newBuilder();
        builder.setResponseCode(200).setMessage(String.format("%s\nWelcome to JCoinche Server 1.0 by %s\n[+] Connected to room %s as Player %d", asciiArt, CREATORS, ROOM_NAME, idx));
        this.writeTo(idx, builder.build());
        // Warn others players that someone connected
        builder.setResponseCode(200).setMessage(String.format("Waiting for %d more player(s)...", 4 - nbPlayers));
        broadcast(builder.build());
        // 4 players are here, let's start the game and warn the players
        if (nbPlayers == 4) {
            gameReady = true;
            builder.setResponseCode(200).setMessage("[+] All players are connected. Game will start now\n");
            broadcast(builder.build());
            rules.startGame();

            String str;
            str = rules.informEveryPlayers();
            builder = GameResponse.newBuilder();
            builder.setResponseCode(200).setMessage(str);
            broadcast(builder.build());

            str = rules.whatIsNextStep(rules.getNextStepPlayer());
            builder = GameResponse.newBuilder();
            builder.setResponseCode(200).setMessage(str);
            writeTo(rules.getNextStepPlayer(), builder.build());

        }
        return true;
    }

    public final Boolean removePlayer(int idx) {
        if (idx < 0 || idx > 4) {
            return false;
        } else {
            players[idx] = null;
            nbPlayers -= 1;
            GameResponse.Builder builder = GameResponse.newBuilder();
            builder.setResponseCode(200).setMessage(String.format("[-] Player n°%d disconnected. Game suspended\n", idx));
            broadcast(builder.build());
            gameReady = false;
            return true;
        }
    }

    /**
     * Send a message to everyone connected on the GameRoom
     *
     * @param msg Message to send
     */
    public final void broadcast(GameResponse msg) {
        for (Channel c : players) {
            if (c != null) {
                c.writeAndFlush(msg);
            }
        }
    }

    /**
     * Forward what the server received to the GameRules
     * GameRules will determine if it's currently this player turn and if his move is valid
     *
     * @param playerIdx Position of the player in our array
     * @param msg Message we received from the client
     */
    public final void forwardToGame(Integer playerIdx, GameRequest msg) {
        if (!gameReady) {
            GameResponse.Builder builder = GameResponse.newBuilder();
            builder.setResponseCode(403).setMessage(String.format("Game hasn't started yet. Please wait for %d more players\n", 4 - nbPlayers));
            writeTo(playerIdx, builder.build());
        } else {
            String str;
            GameResponse.Builder builder;

            str = rules.nextStep(playerIdx, msg.getCard());
            builder = GameResponse.newBuilder();
            builder.setResponseCode(200).setMessage(str);
            if (str.contains("End of Round"))
                broadcast(builder.build());
            else
                writeTo(playerIdx, builder.build());

            if (!str.contains("Invalid")) {
                str = rules.informEveryPlayers();
                builder = GameResponse.newBuilder();
                builder.setResponseCode(200).setMessage(str);
                broadcast(builder.build());

                str = rules.whatIsNextStep(rules.getNextStepPlayer());
                builder = GameResponse.newBuilder();
                builder.setResponseCode(200).setMessage(str);
                writeTo(rules.getNextStepPlayer(), builder.build());
            }
        }
    }

    /**
     * Send a message to a specific player (the one at {@code playerIdx})
     *
     * @param playerIdx Position of the player in our array
     * @param msg Message to send
     * @return Boolean which will tell if the player received the message
     */
    public final Boolean writeTo(int playerIdx, GameResponse msg) {
        if (playerIdx < 0 || playerIdx >= 4 || players[playerIdx] == null) {
            return false;
        } else {
            players[playerIdx].writeAndFlush(msg);
            return true;
        }
    }
}
