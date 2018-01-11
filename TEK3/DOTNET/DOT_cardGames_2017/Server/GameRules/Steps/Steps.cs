using Coinche.Tools;
using Server.GameRules.Steps;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Coinche.GameRules.Steps
{
    public enum Step
    {
        Auction = 0,
        Counter = 1,
        Announce = 2,
        Tricks = 3
    }

    /// <summary>
    /// class in which there is all the steps of the game
    /// </summary>
    public class Steps
    {
        /// <summary>
        /// the current step
        /// </summary>
        public Step CurrentStep { get; set; }

        /// <summary>
        /// list of all the steps
        /// </summary>
        private List<IStep> RoundSteps;

        /// <summary>
        /// simple constructor
        /// </summary>
        public Steps()
        {
            RoundSteps = new List<IStep>
            {
                new Auction(),
                new Counter(),
                new Announce(),
                new Tricks()
            };
        }

        /// <summary>
        /// reinitialize the steps for a new round
        /// </summary>
        public void Reset()
        {
            CurrentStep = Step.Auction;
            foreach (IStep s in RoundSteps)
            {
                s.Reset();
            }
        }

        /// <summary>
        /// get the infos for the next step
        /// </summary>
        /// <param name="player"></param>
        /// <param name="teamContract"></param>
        /// <returns>a GameInfo instance to inform the players of the next step</returns>
        public GameInfo PrepareNextStep(Player player, int teamContract)
        {
            return RoundSteps.ElementAt((int)CurrentStep).PrepareStep(player, teamContract);
        }

        /// <summary>
        /// send the message a player wants to play to the current step
        /// </summary>
        /// <param name="player"></param>
        /// <param name="msg"></param>
        /// <param name="allAssets"></param>
        /// <param name="noneAssets"></param>
        /// <param name="colorBet"></param>
        /// <param name="firstPlayer"></param>
        /// <returns>a GameInfo instance to inform the players of what has been played</returns>
        public GameInfo DoNextStep(Player player, string msg, Boolean allAssets, Boolean noneAssets, CardColor colorBet, int firstPlayer)
        {
            GameInfo infos = RoundSteps.ElementAt((int)CurrentStep).DoStep(player, msg, allAssets, noneAssets, colorBet, firstPlayer);
            if (infos.GoToNextStep)
            {
                infos.PublicMessage += RoundSteps.ElementAt((int)CurrentStep).StepOver();
                CurrentStep++;
            }
            return infos;
        }

        /// <summary>
        /// function called if it wasn't the right turn to play
        /// </summary>
        /// <param name="player"></param>
        /// <returns>a GameInfo instance to inform the player it wasn't his turn to play</returns>
        public GameInfo InvalidTurn(Player player)
        {
            return RoundSteps.ElementAt((int)CurrentStep).InvalidTurn(player);
        }
    }
}
