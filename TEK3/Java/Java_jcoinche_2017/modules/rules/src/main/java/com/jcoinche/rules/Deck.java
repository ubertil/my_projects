package com.jcoinche.rules;

import java.util.ArrayList;
import java.util.List;
import static java.util.Collections.shuffle;

/**
 * This class represents the deck we use for the coinche
 *
 * A deck is composed of 32 cards (8 per color from the Seven to the Ace)
 *
 * @author uberti_l
 * @author grella_c
 * @see Card
 * @version 1.0
 */
public class Deck {
    /**
     * the list of the deck's cards
     */
    public List<Card>  deck;
    /**
     * the index from where we deal the cards
     */
    public int         idx;

    /**
     * Basic constructor that initialize the deck.
     */
    Deck() {
        deck = new ArrayList<>();
        idx = 0;

        int num = 0;
        for (Card.CardName name : Card.CardName.values()) {
            for (Card.CardType type : Card.CardType.values()) {
                deck.add(new Card(name, type, num));
            }
            num++;
        }
    }

    /**
     * shuffle the deck before dealing it.
     */
    public void shuffleDeck() {
        shuffle(deck);
        idx = 0;
    }

    /**
     * deal 8 cards to the player p
     */
    public void deal(Player p) {
        p.hand.clear();
        for (int i = 0; i < 8; i++) {
            p.hand.add(deck.get(idx++));
        }
    }
}
