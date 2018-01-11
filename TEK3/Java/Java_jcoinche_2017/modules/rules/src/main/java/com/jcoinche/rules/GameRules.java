package com.jcoinche.rules;

/**
 * This class represents all of the game rules of the coinche game
 *
 * This class contains the deck, the list of the players, the game board and so on
 * It also manage the execution of a game by starting the rounds and counting the points of each team
 *
 * @author uberti_l
 * @author grella_c
 * @see Deck
 * @see Card
 * @see Player
 * @version 1.0
 */
public class GameRules {
    private Deck            deck;
    private Player          players[];
    private int             totalPtsTeam1; // joueurs 0 et 2
    private int             totalPtsTeam2; // joueurs 1 et 3
    private Card            gameBoard[];
    private int             firstPlayer;
    private int             playerPlaying;
    private int             playerBetting;
    private int             lastPlayerBet;
    private int             numTrick;

    private String[]        bets;
    private String          bestBet;
    private int             teamContract;
    private int             pointsBet;
    private Card.CardType   colorBet;
    private boolean         allAssets;
    private boolean         noneAssets;
    private boolean         auctionOver;
    private boolean         auctionJustOver;


    /**
     * The constructor set the variables that we use in all of our games and
     * that we doesn't need to reset for each game.
     */
    public GameRules() {
        deck = new Deck();
        gameBoard = new Card[4];
        players = new Player[4];
        bets = new String[4];
        for (int i = 0; i < players.length; i++) {
            players[i] = new Player(i);
        }
    }

    /**
     * Reset the teams points and the index of the first player before a new game.
     */
    private void initGame() {
        firstPlayer = 0;
        totalPtsTeam1 = 0;
        totalPtsTeam2 = 0;
    }

    /**
     * Init the game and launch the rounds until one team wins.
     */
    public void startGame() {
        initGame();
        initRound();
    }


    /**
     * Return a string to send to all of the players when the game is over
     */
    private String endGame() {
        int winnerTeam;

        String str = "\n\nEND OF GAME\n\n";
        if (totalPtsTeam1 > totalPtsTeam2)
            winnerTeam = 1;
        else
            winnerTeam = 2;
        str += "Team " + winnerTeam + " won the game !!\n\n";
        return str;
    }

    /**
     * Reset the players hands and the contract to reach
     */
    private void initRound() {
        auctionOver = false;
        auctionJustOver = false;
        playerPlaying = firstPlayer;
        playerBetting = firstPlayer;
        lastPlayerBet = firstPlayer;
        bestBet = "";
        numTrick = 1;

        allAssets = false;
        noneAssets = false;

        pointsBet = 0;
        colorBet = Card.CardType.Heart;
        teamContract = 1;

        deck.shuffleDeck();
        for (Player p : players) {
            p.resetRoundPoints();
            deck.deal(p);
        }

        for (int i = 0; i < bets.length; i++) {
            bets[i] = null;
        }
    }

    private String endRound() {
        int teamRoundPoints1 = displayTeamRoundPoints(1);
        int teamRoundPoints2 = displayTeamRoundPoints(2);
        updateTeamsTotalPoints();

        String str = "\nEnd of Round\n";
        str += "Round Score :\n";
        str += "\tTeam 1 " + teamRoundPoints1 + " points.\n";
        str += "\tTeam 2 " + teamRoundPoints2 + " points.\n\n";
        str += "Total Score :\n";
        str += "\tTeam 1 " + totalPtsTeam1 + " points.\n";
        str += "\tTeam 2 " + totalPtsTeam2 + " points.\n";
        return str;
    }

    /**
     * The best player win the trick and all of its points.
     */
    private void collectTrick(int numRound) {
        Card bestCard = null;
        int bestPlayer = -1;
        int player = 0;

        for (Card c : gameBoard) {
            if (bestCard == null) {
                bestCard = c;
                bestPlayer = player;
            }
            else {
                if (allAssets) {
                    if (c.type == bestCard.type && c.powerAsset > bestCard.powerAsset) {
                        bestCard = c;
                        bestPlayer = player;
                    }
                }
                else if (noneAssets) {
                    if (c.type == bestCard.type && c.powerNonAsset > bestCard.powerNonAsset) {
                        bestCard = c;
                        bestPlayer = player;
                    }
                }
                else {
                    if ((c.type == colorBet) && ((bestCard.type != colorBet) || (c.powerAsset > bestCard.powerAsset))) {
                        bestCard = c;
                        bestPlayer = player;
                    }
                    else if ((c.type != colorBet) && (bestCard.type != colorBet) && (c.type == bestCard.type) && (c.powerNonAsset > bestCard.powerNonAsset)) {
                        bestCard = c;
                        bestPlayer = player;
                    }
                }
            }
            player++;
        }
        players[bestPlayer].roundPoints += countRoundPoints(numRound);
        firstPlayer = bestPlayer;
    }

    /**
     * Count the points of the trick.
     */
    private int countRoundPoints(int numRound) {
        int roundPoints = 0;
        for (Card c : gameBoard) {
            if (allAssets) {
                roundPoints += c.pointsAllAssets;
            } else if (noneAssets) {
                roundPoints += c.pointsNoneAssets;
            } else {
                if (c.type == colorBet) {
                    roundPoints += c.pointsAsset;
                } else {
                    roundPoints += c.pointsNonAsset;
                }
            }
        }
        if (numRound == 8) {
            roundPoints += 10;
        }
        return (roundPoints);
    }

    /**
     * Return the points a team made during the last round.
     */
    private int displayTeamRoundPoints(int team) {
        int teamPoints;
        teamPoints = ((team == 1) ? (players[0].roundPoints + players[2].roundPoints) : (players[1].roundPoints + players[3].roundPoints));
        return teamPoints;
    }

    /**
     * Update the points of each team after a round.
     */
    private void updateTeamsTotalPoints() {
        int roundPtsTeam1 = players[0].roundPoints + players[2].roundPoints;
        int roundPtsTeam2 = players[1].roundPoints + players[3].roundPoints;

        if (teamContract == 1) {
            if (roundPtsTeam1 >= pointsBet)
                totalPtsTeam1 += pointsBet;
            else
                totalPtsTeam2 += pointsBet;

        }
        else {
            if (roundPtsTeam2 >= pointsBet)
                totalPtsTeam2 += pointsBet;
            else
                totalPtsTeam1 += pointsBet;
        }
    }

    /**
     * Return a string that indicates the player if his bet was valid or not.
     */
    private String playAuction(int playerIdx, String msg) {
        if (playerIdx != playerBetting)
            return "Invalid : This is not your turn to bet";

        String[] bet = new String[2];
        if (!msg.equals("Skip") && (bet = isInvalidBet(msg)) == null) {
            return "Invalid bet";
        }

        if (!msg.equals("Skip")) {
            lastPlayerBet = playerBetting;
            bestBet = "Player " + playerIdx + " : " + msg;

            pointsBet = Integer.parseInt(bet[0]);
            if (bet[1].equals("AllAsset")) {
                allAssets = true;
                noneAssets = false;
            }
            else if (bet[1].equals("NoneAsset")) {
                noneAssets = true;
                allAssets = false;
            }
            else {
                for (Card.CardType t : Card.CardType.values()) {
                    if (bet[1].equals(t.toString())) {
                        colorBet = t;
                        allAssets = false;
                        noneAssets = false;
                    }
                }
            }
        }

        if ((playerBetting = (playerBetting + 1) % 4) == lastPlayerBet) {
            if (bestBet.equals(""))
                initRound();
            else {
                if (lastPlayerBet == 0 || lastPlayerBet == 2)
                    teamContract = 1;
                else
                    teamContract = 2;
                auctionOver = true;
                auctionJustOver = true;
            }
        }

        bets[playerIdx] = msg;
        return "Your bet : " + bets[playerIdx];
    }

    private String[] isInvalidBet(String bet) {
        String[] strings;

        strings = bet.split(" ");
        if (strings.length != 2)
            return null;
        try {
            int nb = Integer.parseInt(strings[0]);
            boolean check = false;
            for (int i = 80; i <= 160; i += 10) {
                if (nb == i)
                    check = true;
            }
            if (!check || nb <= pointsBet)
                return null;
        } catch (NumberFormatException e) {
            return null;
        }
        if (strings[1].equals("AllAsset") || strings[1].equals("NoneAsset"))
            return strings;
        for (Card.CardType t : Card.CardType.values()) {
            if (strings[1].equals(t.toString()))
                return strings;
        }
        return null;
    }

    /**
     * Return a string that indicates the player if his play was valid or not.
     */
    private String playCard(int playerIdx, String msg) {
        if (playerIdx != playerPlaying)
            return "Invalid : This is not your turn to play";
        gameBoard[playerIdx] = players[playerIdx].playCard(gameBoard, colorBet, allAssets, noneAssets, firstPlayer, msg);
        if (gameBoard[playerIdx] == null)
            return "Invalid card.";
        playerPlaying = (playerPlaying + 1) % 4;
        if (playerPlaying == firstPlayer) {
            collectTrick(numTrick);
            if (numTrick == 8) {
                String str = "You played : " + gameBoard[playerIdx].name + " of " + gameBoard[playerIdx].type + "\n\n";
                str += informRound();
                str += endRound();
                initRound();
                if (totalPtsTeam1 > 701 || totalPtsTeam2 > 701) {
                    str += endGame();
                    startGame();
                }
                return str;
            }
            numTrick++;
        }
        return "You played : " + gameBoard[playerIdx].name + " of " + gameBoard[playerIdx].type;
    }

    /**
     * Return a string relative to the next step of the game
     */
    public String nextStep(int playerIdx, String msg) {
        if (!auctionOver) {
            return playAuction(playerIdx, msg);
        } else
            return playCard(playerIdx, msg);
    }

    /**
     * Return a string to tell the next player what he can do
     */
    public String whatIsNextStep(int playerIdx) {
        if (!auctionOver) {
            String str = "Your turn to bet :\n";
            str += "80 90 100 110 120 130 140 150 160\n";
            str += "Heart Spade Diamond Club AllAsset NoneAsset\n";
            str += "Examples :\n";
            str += "\t100 Heart\n";
            str += "\t110 NoneAsset\n";
            str += "\tSkip";
            return str;
        } else
            return players[playerIdx].showHand();
    }

    /**
     * Return the index of the next player
     */
    public int getNextStepPlayer() {
        if (!auctionOver) {
            return playerBetting;
        } else
            return playerPlaying;
    }

    /**
     * Return a string to send to all of the players
     */
    public String informEveryPlayers() {
        if (!auctionOver)
            return informAuction();
        else
            return informRound();
    }

    /**
     * Return a string to inform the players on the current auction status
     */
    private String informAuction() {
        String str = "Bets\n";
        for (int i = 0; i < bets.length; ++i) {
            if (bets[i] == null)
                str += "\tPlayer " + i + " : no bet yet";
            else
                str += "\tPlayer " + i + " : " + bets[i];
            str += "\n";
        }
        return str;
    }

    /**
     * Return a string to inform the players on the current trick status
     */
    private String informRound() {
        String str = "";

        if (auctionJustOver) {
            auctionJustOver = false;
            str += informAuction();
            str += "\n\n";
            str += "The Team " + teamContract + " needs to make at least " + pointsBet + " points with ";
            str += getStringAsset();
            str += "\n\n";
        }

        // si le pli est fini, on vide le plateau de jeu et on informe les joueurs du gagnant
        boolean check = true;
        for (Card c : gameBoard) {
            if (c == null) {
                check = false;
            }
        }
        if (check) {
            str += getBoardAsString();
            str += "\nPlayer " + firstPlayer + " win the trick\n\n";
            for (int i = 0; i < gameBoard.length; i++) {
                gameBoard[i] = null;
            }
            playerPlaying = firstPlayer;
        }

        str += getBoardAsString();
        return str;
    }

    private String getStringAsset() {
        if (allAssets) {
            return "All Assets";
        } else if (noneAssets) {
            return "None Assets";
        } else {
            return "asset at " + colorBet.toString();
        }
    }

    /**
     * Return the game board as a string so we can send it to the players
     */
    private String getBoardAsString() {
        String str = "";

        str += "Game Board\n";
        int i = firstPlayer;
        for (int j = 0; j < players.length; j++) {
            str += "Card played by Player " + i + " : ";
            if (gameBoard[i] == null)
                str += "nothing yet";
            else
                str += gameBoard[i].name + " of " + gameBoard[i].type;
            str += "\n";
            i = (i + 1) % 4;
        }
        return str;
    }
}


