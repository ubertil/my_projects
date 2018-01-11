namespace Coinche.GameRules
{
    public enum CardColor
    {
        Heart,
        Spade,
        Diamond,
        Club
    }

    public enum CardValue
    {
        Seven = 0,
        Eight = 1,
        Nine = 2,
        Ten = 3,
        Jack = 4,
        Queen = 5,
        King = 6,
        Ace = 7
    }

    /// <summary>
    /// class defining a card
    /// </summary>
    public class Card
    {
        /// <summary>
        /// color of the card
        /// </summary>
        public CardColor Color { get; }

        /// <summary>
        /// value of the card
        /// </summary>
        public CardValue Value { get; }

        /// <summary>
        /// power of the card if its color is the asset one
        /// </summary>
        public int PowerAsset { get; }

        /// <summary>
        /// power of the card if it's not an asset
        /// </summary>
        public int PowerNonAsset { get; }

        /// <summary>
        /// points of the card if it's an asset
        /// </summary>
        public int PointsAsset { get; }

        /// <summary>
        /// points of the card if it's not an asset
        /// </summary>
        public int PointsNonAsset { get; }

        /// <summary>
        /// points of the card if all cards are assets
        /// </summary>
        public int PointsAllAssets { get; }

        /// <summary>
        /// points of the card if there is none assets
        /// </summary>
        public int PointsNoneAssets { get; }

        /// <summary>
        /// Basic constructor that initialize a card
        /// </summary>
        public Card(CardColor c, CardValue v)
        {
            Color = c;
            Value = v;

            int[] tabPowerAsset = { 0, 1, 6, 4, 7, 2, 3, 5 };
            int[] tabPowerNonAsset = { 0, 1, 2, 6, 3, 4, 5, 7 };
            int[] tabPointsAsset = { 0, 0, 3, 4, 10, 11, 14, 20 };
            int[] tabPointsNonAsset = { 0, 0, 0, 2, 3, 4, 10, 11 };
            int[] tabPointsAllAssets = { 0, 0, 2, 3, 5, 7, 9, 14 };
            int[] tabPointsNoneAssets = { 0, 0, 0, 2, 3, 4, 10, 19 };

            int num = (int)v;
            PowerAsset = tabPowerAsset[num];
            PowerNonAsset = tabPowerNonAsset[num];
            PointsAsset = tabPointsAsset[num];
            PointsNonAsset = tabPointsNonAsset[num];
            PointsAllAssets = tabPointsAllAssets[num];
            PointsNoneAssets = tabPointsNoneAssets[num];
        }
    }
}
