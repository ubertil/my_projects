using Coinche.GameRules;
using System;
using System.Collections.Generic;
using System.Text;

namespace Coinche.Tools
{
    /// <summary>
    /// Tes messages to send to the players and the infos to update the game
    /// </summary>
    public class GameInfo
    {
        /// <summary>
        /// Message to send to a single player
        /// </summary>
        public int PrivatePlayer { get; set; }
        public string PrivateMessage { get; set; }

        /// <summary>
        /// Message to send to every players
        /// </summary>
        public string PublicMessage { get; set; }

        /// <summary>
        /// If true go to next step
        /// </summary>
        public Boolean GoToNextStep { get; set; }

        /// <summary>
        /// If true restart the round
        /// </summary>
        public Boolean RestartRound { get; set; }

        /// <summary>
        /// If true restart the game
        /// </summary>
        public Boolean RestartGame { get; set; }

        /// <summary>
        /// If true we display the informations for the next player
        /// </summary>
        public Boolean ValidTurn { get; set; }

        /// <summary>
        /// the number of the team who got the contract
        /// </summary>
        public int teamContract { get; set; }

        /// <summary>
        /// the amount of points to make to win the contract
        /// </summary>
        public int pointsBet { get; set; }

        /// <summary>
        /// the asset color for the round
        /// </summary>
        public CardColor colorBet { get; set; }

        /// <summary>
        /// true if the team wants to play with all assets
        /// </summary>
        public Boolean allAssets { get; set; }

        /// <summary>
        /// true if the team wants to play with none assets
        /// </summary>
        public Boolean noneAssets { get; set; }

        /// <summary>
        /// true if the team wants to bet on Capot
        /// </summary>
        public Boolean Capot { get; set; }

        /// <summary>
        /// the first player of the next step
        /// </summary>
        public int newFirstPlayer { get; set; }

        /// <summary>
        /// amount of points to add to team1 for this round
        /// </summary>
        public int addRoundPointsTeam1 { get; set; }

        /// <summary>
        /// amount of points to add to team2 for this round
        /// </summary>
        public int addRoundPointsTeam2 { get; set; }

        /// <summary>
        /// score multiplier (either 1, 2 or 4)
        /// </summary>
        public int mult { get; set; }

        /// <summary>
        /// true if the first player of a team passed
        /// </summary>
        public Boolean passedCounter { get; set; }

        /// <summary>
        /// true if a player played a belotte
        /// </summary>
        public Boolean belotte { get; set; }

        /// <summary>
        /// number of the team who played the belotte
        /// </summary>
        public int teamBelotte { get; set; }

        /// <summary>
        /// points of the best announce
        /// </summary>
        public int pointAnnounce { get; set; }

        /// <summary>
        /// team of the best announce
        /// </summary>
        public int teamAnnounce { get; set; }

        /// <summary>
        /// initializes the infos
        /// </summary>
        public GameInfo()
        {
            PrivatePlayer = -1;
            PrivateMessage = null;
            PublicMessage = null;
            GoToNextStep = false;
            RestartRound = false;
            RestartGame = false;
            ValidTurn = true;

            teamContract = -1;

            newFirstPlayer = -1;
            addRoundPointsTeam1 = 0;
            addRoundPointsTeam2 = 0;
            mult = -1;
            passedCounter = false;
            belotte = false;
            teamBelotte = -1;
            Capot = false;

            pointAnnounce = -1;
            teamAnnounce = -1;
        }
    }
}
