using System;
using System.Collections.Generic;

namespace Coinche.GameRules
{
    /// <summary>
    /// class defining the deck
    /// </summary>
    public class Deck
    {
        private List<Card> Cards;
        private int CurrentIdx;
        
        /// <summary>
        /// Basic constructor that creates the deck using the Card class
        /// </summary>
        public Deck()
        {
            Cards = new List<Card>();

            foreach (CardColor c in Enum.GetValues(typeof(CardColor)))
            {
                foreach (CardValue v in Enum.GetValues(typeof(CardValue)))
                {
                    Cards.Add(new Card(c, v));
                }
            }
        }

        /// <summary>
        /// Reset the deck state before dealing
        /// </summary>
        public void Reset()
        {
            CurrentIdx = 0;
        }

        /// <summary>
        /// Display the cards in the whole deck
        /// </summary>
        public void Display()
        {
            int i = 1;

            foreach (Card c in Cards)
            {
                Console.WriteLine("Card n°" + i++ + " : " + c.Value + " of " + c.Color);
            }
        }

        /// <summary>
        /// Shuffle the deck in a random order
        /// </summary>
        public void Shuffle()
        {
            List<Card> randomList = new List<Card>();
            Random r = new Random();
            int randomIndex = 0;

            while (Cards.Count > 0)
            {
                randomIndex = r.Next(0, Cards.Count);
                randomList.Add(Cards[randomIndex]);
                Cards.RemoveAt(randomIndex);
            }
            Cards = randomList;
        }

        /// <summary>
        /// Deal 8 cards to a specified player
        /// </summary>
        /// <param name="p"></param>
        public void Deal(Player p)
        {
            for (int i = 0; i < 8; i++)
            {
                p.Hand.Add(Cards[CurrentIdx++]);
            }
        }
    }
}
