using Coinche.Tools;
using System;
using System.Collections.Generic;
using System.Text;

namespace Coinche.GameRules.Steps
{
    /// <summary>
    /// interface of each step
    /// </summary>
    interface IStep
    {
        /// <summary>
        /// reset the step
        /// </summary>
        void Reset();

        /// <summary>
        /// prepare the players for the next step
        /// </summary>
        /// <param name="player"></param>
        /// <param name="teamContract"></param>
        /// <returns>infos to tell them what to do</returns>
        GameInfo PrepareStep(Player player, int teamContract);

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
        GameInfo DoStep(Player player, string msg, Boolean allAssets, Boolean noneAssets, CardColor colorBet, int firstPlayer);

        /// <summary>
        /// function called if it wasn't the right turn to play
        /// </summary>
        /// <param name="player"></param>
        /// <returns>a GameInfo instance to inform the player it wasn't his turn to play</returns>
        GameInfo InvalidTurn(Player player);

        /// <summary>
        /// function called when the step is over
        /// </summary>
        /// <returns>a string to tell players the step is over</returns>
        string StepOver();
    }
}
