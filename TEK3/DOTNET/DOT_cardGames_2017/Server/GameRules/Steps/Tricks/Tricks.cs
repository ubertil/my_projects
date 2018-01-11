using Coinche.Tools;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Coinche.GameRules.Steps
{
    /// <summary>
    /// class representing the tricks step
    /// </summary>
    public class Tricks : IStep
    {
        /// <summary>
        /// game board
        /// </summary>
        private Board GameBoard;

        /// <summary>
        /// the number of the current trick
        /// </summary>
        private int TrickIndex;

        /// <summary>
        /// the index of the first player of the trick
        /// </summary>
        private int First;

        /// <summary>
        /// true if a player played a belotte
        /// </summary>
        private Boolean belotte;

        /// <summary>
        /// index of the player who played the belotte
        /// </summary>
        private int belotte_player;
        
        /// <summary>
        /// simple constructor
        /// </summary>
        public Tricks()
        {
            GameBoard = new Board();
        }

        /// <summary>
        /// reset the step
        /// </summary>
        void IStep.Reset()
        {
            GameBoard.Reset();
            TrickIndex = 1;
            First = -1;
            belotte = false;
            belotte_player = -1;
        }

        /// <summary>
        /// prepare the players for the next step
        /// </summary>
        /// <param name="player"></param>
        /// <param name="teamContract"></param>
        /// <returns>infos to tell them what to do</returns>
        GameInfo IStep.PrepareStep(Player player, int teamContract)
        {
            GameInfo infos = new GameInfo();
            infos.PublicMessage = GameBoard.BoardStatus();
            infos.PrivatePlayer = player.id;
            infos.PrivateMessage = player.GetHandAsString();
            return infos;
        }

        /// <summary>
        /// rules of the current step applied with the players messages
        /// </summary>
        /// <param name="player"></param>
        /// <param name="msg"></param>
        /// <param name="allAssets"></param>
        /// <param name="noneAssets"></param>
        /// <param name="colorBet"></param>
        /// <param name="firstPlayer"></param>
        /// <returns>a GameInfo instance to tell players what happened</returns>
        GameInfo IStep.DoStep(Player player, string msg, Boolean allAssets, Boolean noneAssets, CardColor colorBet, int firstPlayer)
        {
            GameInfo infos = new GameInfo();
            if (First == -1)
                First = player.id;
            GameBoard.CardsPlayed[player.id] = player.PlayCard(GameBoard.CardsPlayed, colorBet, allAssets, noneAssets, First, msg);
            if (GameBoard.CardsPlayed[player.id] == null)
            {
                infos.PrivatePlayer = player.id;
                infos.PrivateMessage = "Invalid card";
                infos.ValidTurn = false;
                return infos;
            }
            infos.PrivatePlayer = player.id;
            infos.PublicMessage = BelotteRebelotte(player, allAssets, noneAssets, colorBet, GameBoard.CardsPlayed[player.id]);
            infos.PrivateMessage +=  "You played : " + GameBoard.CardsPlayed[player.id].Value + " of " + GameBoard.CardsPlayed[player.id].Color;
            if (GameBoard.IsFull())
            {
                infos = CollectTrick(infos, TrickIndex, allAssets, noneAssets, colorBet);
                infos.PrivatePlayer = player.id;
                infos.PrivateMessage = "You played : " + GameBoard.CardsPlayed[player.id].Value + " of " + GameBoard.CardsPlayed[player.id].Color;
                string endTrick = GameBoard.BoardStatus();
                endTrick += "\nPlayer " + infos.newFirstPlayer + " win the trick\n\n";
                First = infos.newFirstPlayer;
                infos.PublicMessage = BelotteRebelotte(player, allAssets, noneAssets, colorBet, GameBoard.CardsPlayed[player.id]) + endTrick;
                GameBoard.Reset();
                if (TrickIndex == 8)
                    infos.RestartRound = true;
                TrickIndex++;
            }
            infos.belotte = belotte;
            if (player.id == 0 || player.id == 2)
                infos.teamBelotte = 1;
            else
                infos.teamBelotte = 2;
            return infos;
        }

        private string BelotteRebelotte(Player player, Boolean allAssets, Boolean noneAssets, CardColor colorBet, Card cardPlayed)
        {
            if (allAssets || noneAssets)
                return "";
            Boolean queen = false;
            Boolean king = false;
            foreach (Card c in player.Hand)
            {
                if (c.Value == CardValue.Queen && c.Color == colorBet)
                    queen = true;
                else if (c.Value == CardValue.King && c.Color == colorBet)
                    king = true;
            }
            if (cardPlayed.Color == colorBet)
            {
                if (cardPlayed.Value == CardValue.Queen)
                    queen = true;
                if (cardPlayed.Value == CardValue.King)
                    king = true;
                if (belotte && (queen || king))
                    return "Rebelotte\n";
            }

            if (queen && king && cardPlayed.Color == colorBet && (cardPlayed.Value == CardValue.Queen || cardPlayed.Value == CardValue.King))
            {    
                belotte = true;
                belotte_player = player.id;
                return "Belotte\n";
            }
            return "";
        }

        private GameInfo CollectTrick(GameInfo infos, int TrickIndex, Boolean allAssets, Boolean noneAssets, CardColor colorBet)
        {
            Card bestCard = null;
            int bestPlayer = -1;
            int player = 0;

            foreach (Card c in GameBoard.CardsPlayed)
            {
                if (bestCard == null)
                {
                    bestCard = c;
                    bestPlayer = player;
                }
                else
                {
                    if (allAssets)
                        {
                        if (c.Color == bestCard.Color && c.PowerAsset > bestCard.PowerAsset) {
                            bestCard = c;
                            bestPlayer = player;
                        }
                    }
                    else if (noneAssets) {
                        if (c.Value == bestCard.Value && c.PowerNonAsset > bestCard.PowerNonAsset) {
                            bestCard = c;
                            bestPlayer = player;
                        }
                    }
                    else
                    {
                        if ((c.Color == colorBet) && ((bestCard.Color != colorBet) || (c.PowerAsset > bestCard.PowerAsset)))
                        {
                            bestCard = c;
                            bestPlayer = player;
                        }
                        else if ((c.Color != colorBet) && (bestCard.Color != colorBet) && (c.Value == bestCard.Value) && (c.PowerNonAsset > bestCard.PowerNonAsset))
                        {
                            bestCard = c;
                            bestPlayer = player;
                        }
                    }
                }
                player++;
            }
            infos.addRoundPointsTeam1 += CountRoundPoints(TrickIndex, allAssets, noneAssets, colorBet, 1);
            infos.addRoundPointsTeam2 += CountRoundPoints(TrickIndex, allAssets, noneAssets, colorBet, 2);
            infos.newFirstPlayer = bestPlayer;
            return infos;
        }

        private int CountRoundPoints(int numRound, Boolean allAssets, Boolean noneAssets, CardColor colorBet, int team)
        {
            int roundPoints = 0;
            for (int i = 0; i < GameBoard.CardsPlayed.Length; i++)
            {
                Card c = GameBoard.CardsPlayed[i];
                if ((team == 1 && (i == 0 || i == 2)) ||
                    (team == 2 && (i == 1 || i == 3)))
                if (allAssets)
                {
                    roundPoints += c.PointsAllAssets;
                }
                else if (noneAssets)
                {
                    roundPoints += c.PointsNoneAssets;
                }
                else
                {
                    if (c.Color == colorBet)
                    {
                        roundPoints += c.PointsAsset;
                    }
                    else
                    {
                        roundPoints += c.PointsNonAsset;
                    }
                }
            }
            if (numRound == 8)
            {
                roundPoints += 10;
            }
            return (roundPoints);
        }

        /// <summary>
        /// function called if it wasn't the right turn to play
        /// </summary>
        /// <param name="player"></param>
        /// <returns>a GameInfo instance to inform the player it wasn't his turn to play</returns>
        GameInfo IStep.InvalidTurn(Player player)
        {
            GameInfo infos = new GameInfo();
            infos.PrivatePlayer = player.id;
            infos.PrivateMessage = "This is not your turn to play.";
            infos.ValidTurn = false;
            return infos;
        }

        /// <summary>
        /// function called when the step is over
        /// </summary>
        /// <returns>a string to tell players the step is over</returns>
        string IStep.StepOver()
        {
            return "";
        }
    }
}
