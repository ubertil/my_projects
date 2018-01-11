package com.jcoinche.rules;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;
import static org.junit.Assert.assertNotEquals;

public class PlayerTest {
    @Test
    public void idPlayer() {
        Player p = new Player(1);

        assertEquals("check the player's id", 1, p.id);
    }

    @Test
    public void resetRoundPoints() {
        Player p = new Player(1);

        p.roundPoints = 10;
        assertEquals("check if we succesfully set the roundPoints", 10, p.roundPoints);
        p.resetRoundPoints();
        assertNotEquals("check if the resetRoundPoints worked", 10, p.roundPoints);
        assertEquals("check if the resetRoundPoints worked", 0, p.roundPoints);
    }

    @Test
    public void gotColorInHand() {
        Player p = new Player(1);

        assertNotEquals("the player has no cards in hand", true, p.GotColorInHand(Card.CardType.Heart));
        p.hand.add(new Card(Card.CardName.Ace, Card.CardType.Heart, 7));
        assertEquals("the player now have an Ace of Heart", true, p.GotColorInHand(Card.CardType.Heart));
    }
}
