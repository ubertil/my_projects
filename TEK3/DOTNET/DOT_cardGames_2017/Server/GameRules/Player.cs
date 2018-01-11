using System;
using System.Collections.Generic;

namespace Coinche.GameRules
{
    /// <summary>
    /// class defining a player
    /// </summary>
    public class Player
    {
        /// <summary>
        /// id of a player
        /// </summary>
        public int id { get; private set; }

        /// <summary>
        /// cards the player have in his hand
        /// </summary>
        public List<Card> Hand { get; set; }

        /// <summary>
        /// Initialize the player from its id
        /// </summary>
        /// <param name="_id"></param>
        public Player(int _id)
        {
            id = _id;
            Hand = new List<Card>();
        }

        /// <summary>
        /// Display the player's hand
        /// </summary>
        public void DisplayHand()
        {
            Console.WriteLine("Player " + id + " :");
            int i = 0;
            foreach (Card c in Hand)
            {
                Console.WriteLine(i++ + " : " + c.Value + " of " + c.Color);
            }
        }

        /// <summary>
        /// Check if the player has the given color in his hand
        /// </summary>
        /// <param name="c"></param>
        /// <returns>true if he has it else false</returns>
        public Boolean GotColorInHand(CardColor c)
        {
            foreach (Card card in  Hand)
            {
                if (card.Color == c)
                    return (true);
            }
            return (false);
        }

        /// <summary>
        /// get the hand has a string to inform players
        /// </summary>
        /// <returns>the cards in the player's hand</returns>
        public string GetHandAsString()
        {
            string str = "Your Hand :\n";
            for (int i = 0; i < Hand.Count; i++)
            {
                str += "\t" + (i + 1) + " : " + Hand[i].Value + " of " + Hand[i].Color + "\n";
            }
            return str;
        }

        /// <summary>
        /// play a card if valid
        /// </summary>
        /// <param name="gameBoard"></param>
        /// <param name="colorBet"></param>
        /// <param name="allAssets"></param>
        /// <param name="noneAssets"></param>
        /// <param name="firstPlayer"></param>
        /// <param name="cardToPlay"></param>
        /// <returns>return the card played or null</returns>
        public Card PlayCard(Card[] gameBoard, CardColor colorBet, Boolean allAssets, Boolean noneAssets, int firstPlayer, String cardToPlay)
        {
            int choice;
            try
            {
                choice = Int32.Parse(cardToPlay) - 1;
            }
            catch (Exception e)
            {
                choice = -1;
            }

            if (choice >= 0 && choice < Hand.Count)
            {
                Card card = Hand[choice];
                cardToPlay = card.Value + " of " + card.Color;
            }
            int i = 0;
            foreach (Card c in Hand)
            {
                if (cardToPlay.Equals(c.Value + " of " + c.Color) && CardIsValid(c, gameBoard, colorBet, allAssets, noneAssets, firstPlayer))
                {
                    Card cardPlayed = Hand[i];
                    Hand.Remove(Hand[i]);
                    return (cardPlayed);
                }
                i++;
            }
            return (null);
        }

        /// <summary>
        /// check if the card to play is valid
        /// </summary>
        /// <param name="c"></param>
        /// <param name="gameBoard"></param>
        /// <param name="colorBet"></param>
        /// <param name="allAssets"></param>
        /// <param name="noneAssets"></param>
        /// <param name="firstPlayer"></param>
        /// <returns>true if valid else false</returns>
        private Boolean CardIsValid(Card c, Card[] gameBoard, CardColor colorBet, Boolean allAssets, Boolean noneAssets, int firstPlayer)
        {
            if (gameBoard[firstPlayer] == null)
                return (true);

            CardColor firstType = gameBoard[firstPlayer].Color;
            if (allAssets || noneAssets)
            {
                if (c.Color != firstType && GotColorInHand(firstType))
                    return (false);
                return (true);
            }
            else
            {
                if (c.Color == firstType)
                {
                    if (c.Color == colorBet && CardIsWeakerThanGameBoard(c, gameBoard, colorBet) && GotBetterInHand(gameBoard, colorBet))
                        return (false);
                    return (true);
                }
                else
                {
                    if (GotColorInHand(firstType))
                        return (false);
                    if (c.Color != colorBet && GotColorInHand(colorBet))
                        return (false);
                    return (true);
                }
            }
        }

        /// <summary>
        /// check if the player has a better card of the given color in hand
        /// </summary>
        /// <param name="gameBoard"></param>
        /// <param name="colorBet"></param>
        /// <returns>return true if he got better else false</returns>
        private Boolean GotBetterInHand(Card[] gameBoard, CardColor colorBet)
        {
            foreach (Card cardHand in Hand)
            {
                if (cardHand.Color == colorBet)
                {
                    Boolean better = true;
                    foreach (Card cardGameBoard in gameBoard)
                    {
                        if (cardGameBoard != null && cardGameBoard.Color == colorBet)
                        {
                            if (cardGameBoard.PowerAsset > cardHand.PowerAsset)
                                better = false;
                        }
                    }
                    if (better)
                        return (true);
                }
            }
            return (false);
        }

        /// <summary>
        /// check if the card is weaker than the ones on the board
        /// </summary>
        /// <param name="c"></param>
        /// <param name="gameBoard"></param>
        /// <param name="colorBet"></param>
        /// <returns>returns true if the card is weaker else false</returns>
        private Boolean CardIsWeakerThanGameBoard(Card c, Card[] gameBoard, CardColor colorBet)
        {
            foreach (Card gameBoardCard in gameBoard)
            {
                if (gameBoardCard != null)
                {
                    if (c.Color == colorBet)
                    {
                        if (gameBoardCard.Color == colorBet && c.PowerAsset < gameBoardCard.PowerAsset)
                            return (true);
                    }
                    else
                    {
                        if (gameBoardCard.Color == colorBet)
                            return (true);
                        else if (c.PowerNonAsset < gameBoardCard.PowerNonAsset)
                            return (true);
                    }
                }
            }
            return (false);
        }
    }
}
