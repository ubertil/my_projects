package com.jcoinche.rules;

import org.junit.Test;

import static org.junit.Assert.*;

public class DeckTest {
    @Test
    public void shuffleDeck() {
        Deck d = new Deck();
        int previous = 0;

        for (Card c : d.deck) {
            if (c.pointsAllAssets < previous)
                fail("The deck is unordered");
            previous = c.pointsAllAssets;
        }
        d.shuffleDeck();
        boolean ordered = true;
        for (Card c : d.deck) {
            if (c.pointsAllAssets < previous)
                ordered = false;
            previous = c.pointsAllAssets;
        }
        if (ordered)
            fail("The deck is ordered");
    }

    @Test
    public void deal() {
        Deck d = new Deck();
        Player p = new Player(1);
        assertEquals("check the number of cards in the deck before the deal", 0, d.idx);
        d.deal(p);
        assertNotEquals("check the number of cards in the deck after the deal", 0, d.idx);
    }
}