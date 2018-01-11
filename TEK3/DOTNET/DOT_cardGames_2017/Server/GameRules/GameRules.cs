using Coinche.Tools;
using System;
using System.Collections.Generic;
using System.Linq;
using Coinche.GameRules.Steps;

namespace Coinche.GameRules
{
    /// <summary>
    /// class representing the game rules
    /// </summary>
    public class GameRules
    {
        /// <summary>
        /// Instancies of the classes we need in our games
        /// </summary>
        private List<Player> Players;
        private Deck GameDeck;
        private Steps.Steps RoundSteps;

        /// <summary>
        /// Variables that we need to reset between two games
        /// </summary>
        private int GamePointsTeam1;
        private int GamePointsTeam2;
        
        /// <summary>
        /// Variables that we need to reset between two rounds
        /// </summary>
        private int RoundPointsTeam1;
        private int RoundPointsTeam2;
        private int RoundFirstPlayer;
        private int CurrentPlayer;

        /// <summary>
        /// Auction variables defining the contract
        /// </summary>
        private int teamContract;
        private int pointsBet;
        private Boolean Capot;
        private CardColor colorBet;
        private Boolean allAssets;
        private Boolean noneAssets;
        private int mult;
        private Boolean belotte;
        private int teamBelotte;
        private int teamAnnounce;
        private int pointAnnounce;

        /// <summary>
        /// simple constructor that initializes the game rules
        /// </summary>
        public GameRules()
        {
            GameDeck = new Deck();
            Players = new List<Player>
            {
                new Player(0),
                new Player(1),
                new Player(2),
                new Player(3)
            };
            RoundSteps = new Steps.Steps();
        }

        /// <summary>
        /// launch a game
        /// </summary>
        /// <returns>a GameInfo instance to tell all the players a game is now starting</returns>
        public GameInfo LaunchGame()
        {
            ResetGame();
            ResetRound();
            GameInfo infos = new GameInfo();
            infos.PublicMessage = "\n\tNew Game !!!\n";
            return infos;
        }

        /// <summary>
        /// reset the game variables before starting it
        /// </summary>
        private void ResetGame()
        {
            GamePointsTeam1 = 0;
            GamePointsTeam2 = 0;
            RoundFirstPlayer = GetRandomNumber(0, 3);
        }

        /// <summary>
        /// reset the round variables before starting it
        /// </summary>
        private void ResetRound()
        {
            GameDeck.Reset();
            GameDeck.Shuffle();
            foreach (Player p in Players)
            {
                p.Hand.Clear();
                GameDeck.Deal(p);
            }
            RoundPointsTeam1 = 0;
            RoundPointsTeam2 = 0;
            RoundFirstPlayer = (RoundFirstPlayer + 1) % 4;
            CurrentPlayer = RoundFirstPlayer;
            RoundSteps.Reset();
            mult = 1;
            belotte = false;
            Capot = false;
            pointAnnounce = -1;
            teamAnnounce = -1;
        }

        /// <summary>
        /// get a random number betwenn min and max (both included)
        /// </summary>
        /// <param name="min"></param>
        /// <param name="max"></param>
        /// <returns>the random number generated</returns>
        private int GetRandomNumber(int min, int max)
        {
            Random rand = new Random();
            return (rand.Next(min, max + 1));
        }

        /// <summary>
        /// function called when a player send a message to the server
        /// check if it is his turn to play then forward his message to the steps
        /// </summary>
        /// <param name="player"></param>
        /// <param name="msg"></param>
        /// <returns>a GameInfo instance to tell the players what is going on at this time of the game</returns>
        public GameInfo Play(int player, string msg)
        {
            if (CurrentPlayer != player)
                return RoundSteps.InvalidTurn(Players.ElementAt(player));
            GameInfo infos =  RoundSteps.DoNextStep(Players.ElementAt(player), msg, allAssets, noneAssets, colorBet, RoundFirstPlayer);
            RoundPointsTeam1 += infos.addRoundPointsTeam1;
            RoundPointsTeam2 += infos.addRoundPointsTeam2;
            if (infos.teamContract != -1)
            {
                teamContract = infos.teamContract;
                pointsBet = infos.pointsBet;
                colorBet = infos.colorBet;
                allAssets = infos.allAssets;
                noneAssets = infos.noneAssets;
            }
            if (infos.Capot)
                Capot = true;
            if (infos.mult != -1)
                mult = infos.mult;
            if (infos.teamAnnounce != -1)
            {
                teamAnnounce = infos.teamAnnounce;
                pointAnnounce = infos.pointAnnounce;
            }
            if (infos.RestartRound)
            {
                if (RoundPointsTeam1 != 0 && RoundPointsTeam2 != 0)
                    infos.PublicMessage += RoundIsOver();
                ResetRound();
            }
            if (GamePointsTeam1 > 701 || GamePointsTeam2 > 701)
            {
                infos.PublicMessage += GameIsOver();
                LaunchGame();
            }
            if (!belotte && infos.belotte && infos.teamBelotte != -1)
            {
                belotte = true;
                teamBelotte = infos.teamBelotte;
                if (infos.teamBelotte == 1)
                    RoundPointsTeam1 += 20;
                else
                    RoundPointsTeam2 += 20;
            }
            if (infos.ValidTurn)
                CurrentPlayer = (CurrentPlayer + 1) % Players.Count;
            if (infos.GoToNextStep)
                CurrentPlayer = RoundFirstPlayer;
            if (!infos.GoToNextStep && infos.newFirstPlayer != -1)
                CurrentPlayer = infos.newFirstPlayer;
            if (RoundSteps.CurrentStep == Step.Counter)
            {
                if (teamContract == 1)
                {
                    if (mult == 1)
                        CurrentPlayer = 1;
                    else
                        CurrentPlayer = 0;
                }
                else
                {
                    if (mult == 1)
                        CurrentPlayer = 0;
                    else
                        CurrentPlayer = 1;
                }
                if (infos.passedCounter)
                    CurrentPlayer += 2;
            }
            return infos;
        }

        private string RoundIsOver()
        {
            int announce;
            if (pointAnnounce == -1)
                announce = 0;
            else
                announce = pointAnnounce;
            if (teamContract == 1)
            {
                if (RoundPointsTeam1 >= pointsBet)
                    GamePointsTeam1 += (pointsBet + announce) * mult;
                else
                    GamePointsTeam2 += (162 + pointsBet + announce) * mult;
            }
            else
            {
                if (RoundPointsTeam2 >= pointsBet)
                    GamePointsTeam2 += (pointsBet + announce) * mult;
                else
                    GamePointsTeam1 += (162 + pointsBet + announce) * mult;
            }
            string str = "\nEnd of Round\n";
            str += "Round Score :\n";
            str += "\tTeam 1 " + RoundPointsTeam1 + " points.\n";
            str += "\tTeam 2 " + RoundPointsTeam2 + " points.\n\n";
            str += "Total Score :\n";
            str += "\tTeam 1 " + GamePointsTeam1 + " points.\n";
            str += "\tTeam 2 " + GamePointsTeam2 + " points.\n";
            return str;
        }

        /// <summary>
        /// get the final status of the game when it is over
        /// </summary>
        /// <returns>the infos of the game as a string</returns>
        private string GameIsOver()
        {
            string str = "\nEnd of Game :\n";

            str += "Team 1 : " + GamePointsTeam1 + "\n";
            str += "Team 2 : " + GamePointsTeam2 + "\n";

            if (GamePointsTeam1 > GamePointsTeam2)
                str += "\n\tTeam 1 won the game!\n";
            else if (GamePointsTeam2 > GamePointsTeam1)
                str += "\n\tTeam 2 won the game!\n";
            else
                str += "\n\tDraw\n";
            return str;
        }

        /// <summary>
        /// get the infos of the next step to inform the next player of what he can do
        /// </summary>
        /// <returns>a GameInfo instance to inform the players</returns>
        public GameInfo PrepareNextStep()
        {
            return RoundSteps.PrepareNextStep(Players.ElementAt(CurrentPlayer), teamContract);
        }
    }
}
