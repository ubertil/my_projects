package com.jcoinche.rules;

/**
 * This class represents a card by defining all of its characteristics.
 *
 * A card has a value and a color.
 * The value of a card goes from the Seven to the Ace.
 * The color of a card is either Spade, Heart, Club or Diamond.
 *
 * @author uberti_l
 * @author grella_c
 * @version 1.0
 */
public class Card {
    public enum CardName {
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    }
    public enum CardType {
        Spade,
        Heart,
        Club,
        Diamond
    }
    private int tabPowerAsset[] = {0, 1, 6, 4, 7, 2, 3, 5};
    private int tabPowerNonAsset[] = {0, 1, 2, 6, 3, 4, 5, 7};
    private int tabPointsAsset[] = {0, 0, 3, 4, 10, 11, 14, 20};
    private int tabPointsNonAsset[] = {0, 0, 0, 2, 3, 4, 10, 11};
    private int tabPointsAllAssets[] = {0, 0, 2, 3, 5, 7, 9, 14};
    private int tabPointsNoneAssets[] = {0, 0, 0, 2, 3, 4, 10, 19};

    public CardName name;
    public CardType type;

    public int      powerAsset;
    public int      powerNonAsset;

    public int      pointsAsset;
    public int      pointsNonAsset;
    public int      pointsAllAssets;
    public int      pointsNoneAssets;

    /**
     * Basic constructor which initialize the characteristics of the card.
     *
     * @param _name The card value
     * @param _type The card color
     * @param num Index of the card to determine its amount of points and its power
     */
    Card(CardName _name, CardType _type, int num) {
        name = _name;
        type = _type;
        powerAsset = tabPowerAsset[num];
        powerNonAsset = tabPowerNonAsset[num];
        pointsAsset = tabPointsAsset[num];
        pointsNonAsset = tabPointsNonAsset[num];
        pointsAllAssets = tabPointsAllAssets[num];
        pointsNoneAssets = tabPointsNoneAssets[num];
    }
}
