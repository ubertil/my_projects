package com.jcoinche.rules;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * This class represents a player
 *
 * A player has an id a hand (list of cards) and it stocks its points for the current round.
 *
 * @author uberti_l
 * @author grella_c
 * @see Card
 * @version 1.0
 */
public class Player {
    public int          id;
    public List<Card>   hand;
    public int          roundPoints;

    /**
     * Basic constructor that initializes the player from its index.
     */
    Player(int _id) {
        id = _id;
        hand = new ArrayList<>();
        resetRoundPoints();
    }

    /**
     * check if a player can play a certain card
     * if it can it plays it
     * else the player will try again
     */
    public Card playCard(Card[] gameBoard, Card.CardType colorBet, boolean allAssets, boolean noneAssets, int firstPlayer, String cardToPlay) {
        int choice;
        try {
            choice = Integer.parseInt(cardToPlay) - 1;
        } catch (NumberFormatException e) {
            choice = -1;
        }

        if (choice >= 0 && choice < hand.size()) {
            Card card = hand.get(choice);
            cardToPlay = card.name + " of " + card.type;
        }
        int i = 0;
        for (Card c : hand) {
            if (cardToPlay.equals(c.name + " of " + c.type) && cardIsValid(c, gameBoard, colorBet, allAssets, noneAssets, firstPlayer)) {
                Card cardPlayed = hand.get(i);
                hand.remove(i);
                return (cardPlayed);
            }
            i++;
        }
        return (null);
    }

    /**
     * check if a card is valid to be played
     */
    private boolean cardIsValid(Card c, Card[] gameBoard, Card.CardType colorBet, boolean allAssets, boolean noneAssets, int firstPlayer) {
        if (gameBoard[firstPlayer] == null)
            return (true);

        Card.CardType firstType = gameBoard[firstPlayer].type;
        if (allAssets || noneAssets) {
            if (c.type != firstType && GotColorInHand(firstType))
                return (false);
            return (true);
        }
        else {
            if (c.type == firstType) {
                if (c.type == colorBet && CardIsWeakerThanGameBoard(c, gameBoard, colorBet) && GotBetterInHand(gameBoard, colorBet))
                    return (false);
                return (true);
            } else {
                if (GotColorInHand(firstType))
                    return (false);
                if (c.type != colorBet && GotColorInHand(colorBet))
                    return (false);
                return (true);
            }
        }
    }

    /**
     * check if the player has a certain color in hand.
     */
    public boolean GotColorInHand(Card.CardType type) {
        for (Card c :  hand) {
            if (c.type == type)
                return (true);
        }
        return (false);
    }

    /**
     * check if the player has a better asset in hand.
     */
    private boolean GotBetterInHand(Card[] gameBoard, Card.CardType colorBet) {
        for (Card cardHand : hand) {
            if (cardHand.type == colorBet) {
                boolean better = true;
                for (Card cardGameBoard : gameBoard) {
                    if (cardGameBoard != null && cardGameBoard.type == colorBet) {
                        if (cardGameBoard.powerAsset > cardHand.powerAsset)
                            better = false;
                    }
                }
                if (better)
                    return (true);
            }
        }
        return (false);
    }

    /**
     * check if the player has a more powerful in hand than there is on the board
     */
    private boolean CardIsWeakerThanGameBoard(Card c, Card[] gameBoard, Card.CardType colorBet) {
        for (Card gameBoardCard : gameBoard) {
            if (gameBoardCard != null) {
                if (c.type == colorBet) {
                    if (gameBoardCard.type == colorBet && c.powerAsset < gameBoardCard.powerAsset)
                        return (true);
                } else {
                    if (gameBoardCard.type == colorBet)
                        return (true);
                    else if (c.powerNonAsset < gameBoardCard.powerNonAsset)
                        return (true);
                }
            }
        }
        return (false);
    }

    /**
     * reset the round's points of a player
     */
    public void resetRoundPoints() {
        roundPoints = 0;
    }

    /**
     * return the cards in hand as a string
     */
    public String showHand () {
        String str = "Your hand\n";
        int i = 1;

        for (Card c : hand) {
            str += i + ": " + c.name + " of " + c.type + "\n";
            i++;
        }
        return str;
    }

}
