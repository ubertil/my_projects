using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Coinche.GameRules
{
    /// <summary>
    /// class representing the board
    /// </summary>
    public class Board
    {
        /// <summary>
        /// array of the cards on the board (null if there is no card)
        /// </summary>
        public Card[] CardsPlayed { get; set; }

        /// <summary>
        /// simple constructor
        /// </summary>
        public Board()
        {
            CardsPlayed = new Card[4];
        }

        /// <summary>
        /// clear the board
        /// </summary>
        public void Reset()
        {
            for (int i = 0; i < CardsPlayed.Length; i++)
                CardsPlayed[i] = null;
        }

        /// <summary>
        /// get the board status as a string
        /// </summary>
        /// <returns>the cards on the board</returns>
        public string BoardStatus()
        {
            string str = "Board :\n";
            for (int i = 0; i < CardsPlayed.Length;  i++)
            {
                str += "Player " + i + " : ";
                if (CardsPlayed[i] != null)
                {
                    str += CardsPlayed[i].Value.ToString() + " of " + CardsPlayed[i].Color.ToString();
                }
                else
                {
                    str += "nothing yet";
                }
                str += "\n";
            }
            return str;
        }

        /// <summary>
        /// check if the board is full
        /// </summary>
        /// <returns>true if its full else false</returns>
        public Boolean IsFull()
        {
            foreach (Card c in CardsPlayed)
            {
                if (c == null)
                    return false;
            }
            return true;
        }
    }
}
