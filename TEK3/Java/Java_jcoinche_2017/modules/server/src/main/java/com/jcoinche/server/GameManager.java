package com.jcoinche.server;

import com.jcoinche.protobuf.JCoincheProtocol.GameRequest;
import com.jcoinche.protobuf.JCoincheProtocol.GameResponse;

import io.netty.channel.*;
import io.netty.util.concurrent.Future;
import io.netty.handler.ssl.SslHandler;
import io.netty.util.concurrent.GenericFutureListener;

import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * This class should handle all the players connection from the server, by managing all the GameRoom entities
 * Once connected to the Server, a player is <b>guaranteed</b> to enter a GameRoom (empty or not)
 *
 * If 4 players are connected <b>simultaneously</b> to a GameRoom, the game starts for the selected GameRoom
 *
 * @author uberti_l
 * @version 1.0
 * @see io.netty.channel.ChannelInboundHandlerAdapter
 * @see Server
 */
public final class GameManager extends SimpleChannelInboundHandler<GameRequest> {
    /**
     * Logger instance from the Server to log upcomming connections
     */
    private final static Logger LOGGER = Logger.getLogger(Server.class.getName());

    /**
     * @param rooms Reprensents all the GameRoom available and handled by the GameManager
     */
    private final static List<GameRoom> rooms = new ArrayList<GameRoom>();

    /**
     * Basic constructor, creating one empty room to receive the first new connections
     */
    public GameManager() {
        if (rooms.size() == 0) {
            // Create first game room;
            rooms.add(new GameRoom(0));
        }
    }

    @Override
    public void channelActive(final ChannelHandlerContext ctx) {
        ctx.pipeline().get(SslHandler.class).handshakeFuture().addListener(
                new GenericFutureListener<Future<Channel>>() {
                    public void operationComplete(Future<Channel> future) throws Exception {
                        // Let's handle client's disconnection
                        ChannelFuture closeFuture = ctx.channel().closeFuture();
                        closeFuture.addListener(new ChannelFutureListener() {
                            @Override
                            public void operationComplete(ChannelFuture future) throws Exception {
                                for (GameRoom room : rooms) {
                                    int playerIdx = room.getPlayerIdx(future.channel());
                                    if (playerIdx != -1) {
                                        room.removePlayer(playerIdx);
                                        LOGGER.log(Level.INFO, String.format("[%s][-] Player disconnected (Room size : %d)", room.ROOM_NAME, room.getNbPlayers()));
                                        break;
                                    }
                                }
                            }
                        });
                        Boolean added = false;
                        for (GameRoom room : rooms) {
                            if (room.getNbPlayers() != 4) {
                                room.addPlayer(ctx.channel());
                                LOGGER.log(Level.INFO, String.format("[%s][+] Player connected (Room size : %d)", room.ROOM_NAME, room.getNbPlayers()));
                                added = true;
                                break;
                            }
                        }
                        if (!added) {
                            // No room left with space, create a new one
                            rooms.add(new GameRoom(rooms.size()));
                            // Add the player in the newly created room
                            rooms.get(rooms.size() - 1).addPlayer(ctx.channel());
                            LOGGER.log(Level.INFO, String.format("[+] New room created : %s", rooms.get(rooms.size() - 1).ROOM_NAME));
                            LOGGER.log(Level.INFO, String.format("[%s][+] Player connected (Room size : %d)", rooms.get(rooms.size() - 1).ROOM_NAME, rooms.get(rooms.size() - 1).getNbPlayers()));
                        }
                    }
                });
    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) {
        ctx.flush();
    }

    /**
     * Everytime the server reads a message from a player, forward it to the <i>GameRoom</i> where he belongs
     *
     * @param ctx Opened socket for this connection
     * @param msg GameRequest is the message formated using the google protobuf structures
     * @throws Exception
     */
    @Override
    public void channelRead0(ChannelHandlerContext ctx, GameRequest msg) throws Exception {
        for (GameRoom room : rooms) {
            int playerIdx = room.getPlayerIdx(ctx.channel());
            if (playerIdx != -1) {
                room.forwardToGame(playerIdx, msg);
                break;
            }
        }
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {
        ctx.close();
    }
}
