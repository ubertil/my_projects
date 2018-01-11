using Coinche;
using Coinche.GameRules;
using Coinche.GameRules.Steps;
using Coinche.Tools;
using System;
using System.Collections.Generic;
using System.Text;

namespace Server.GameRules.Steps
{
    /// <summary>
    /// class representing the tricks step
    /// </summary>
    public class Counter : IStep
    {
        /// <summary>
        /// string representing the status of the counter (Coinche or Surcoinche)
        /// </summary>
        private string WhatDoYouWant;

        /// <summary>
        /// score multipicator (1, 2 or 4)
        /// </summary>
        private int mult;

        /// <summary>
        /// reset the step
        /// </summary>
        void IStep.Reset()
        {
            WhatDoYouWant = "Coinche";
            mult = 1;
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
            infos.PublicMessage = "The Contract is for the team " + teamContract + " (players " + ((teamContract == 1) ? 0 : 1) + " and " + ((teamContract == 1) ? 2 : 3) + ")\n";
            infos.PublicMessage += "Asking the player " + player.id + " if he wants to " + WhatDoYouWant;
            infos.PrivatePlayer = player.id;
            infos.PrivateMessage = "Do you want to " + WhatDoYouWant + " ?\n\tYes\n\tNo\n";
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
            if (msg.Equals("Yes"))
            {
                if (WhatDoYouWant.Equals("Coinche"))
                {
                    mult = 2;
                    WhatDoYouWant = "Surcoinche";
                }
                else
                {
                    mult = 4;
                    infos.GoToNextStep = true;
                }
            }
            else if (msg.Equals("No"))
            {
                if (player.id == 2 || player.id == 3)
                    infos.GoToNextStep = true;
                infos.passedCounter = true;
            }
            else
            {
                infos.PrivatePlayer = player.id;
                infos.PrivateMessage = "Invalid response";
                infos.ValidTurn = false;
                return infos;
            }
            infos.PublicMessage = "Player " + player.id + " said " + msg + "\n";
            infos.mult = mult;
            return infos;
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
            infos.PrivateMessage = "This is not your turn to counter.";
            infos.ValidTurn = false;
            return infos;
        }

        /// <summary>
        /// function called when the step is over
        /// </summary>
        /// <returns>a string to tell players the step is over</returns>
        string IStep.StepOver()
        {
            if (mult == 2)
                return "The contract has been Coinched\n";
            else if (mult == 4)
                return "The contract has been Coinched and Surcoinched\n";
            else
                return "The contract hasn't been Coinched\n";
        }
    }
}
