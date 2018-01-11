using Coinche.Tools;
using System;

namespace Coinche.GameRules.Steps
{
    public class Auction : IStep
    {
        /// <summary>
        /// Variables needed when defining the contract
        /// </summary>
        private string[] bets;
        private string bestBet;
        private int lastPlayerWhoBet;

        /// <summary>
        /// Variables defining the final contract
        /// </summary>
        private int teamContract;
        private int pointsBet;
        private Boolean Capot;
        private CardColor colorBet;
        private Boolean allAssets;
        private Boolean noneAssets;

        public Auction()
        {
            bets = new string[4];
        }

        /// <summary>
        /// reset the step
        /// </summary>
        void IStep.Reset()
        {
            bestBet = null;
            for (int i = 0; i < bets.Length; i++)
                bets[i] = null;

            allAssets = false;
            noneAssets = false;
            lastPlayerWhoBet = -1;

            teamContract = -1;
            Capot = false;
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
            infos.PublicMessage = BetStatus();
            infos.PrivatePlayer = player.id;
            string str = player.GetHandAsString();
            str += "Your turn to bet :\n";
            str += "80 90 100 110 120 130 140 150 160 Capot\n";
            str += "Heart Spade Diamond Club AllAsset NoneAsset\n";
            str += "Examples :\n";
            str += "\t100 Heart\n";
            str += "\tCapot NoneAsset\n";
            str += "\tSkip\n";
            infos.PrivateMessage = str;
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
        GameInfo IStep.DoStep(Player player, string msg, Boolean allAssets, Boolean noneAssets, CardColor coloreBet, int firstPlayer)
        {
            GameInfo infos = new GameInfo();

            String[] bet = new String[2];
            if (!msg.Equals("Skip") && (bet = IsInvalidBet(msg)) == null)
            {
                infos.PrivatePlayer = player.id;
                infos.PrivateMessage = "Invalid bet";
                infos.ValidTurn = false;
                return infos;
            }

            if (!msg.Equals("Skip"))
            {
                lastPlayerWhoBet = player.id;
                bestBet = "Player " + player.id + " : " + msg;

                if (bet[0].Equals("Capot"))
                    Capot = true;
                else
                    pointsBet = Int32.Parse(bet[0]);
                if (bet[1].Equals("AllAsset"))
                {
                    allAssets = true;
                    noneAssets = false;
                }
                else if (bet[1].Equals("NoneAsset"))
                {
                    noneAssets = true;
                    allAssets = false;
                }
                else
                {
                    foreach (CardColor c in Enum.GetValues(typeof(CardColor)))
                    {
                        if (bet[1].Equals(c.ToString()))
                        {
                            colorBet = c;
                            allAssets = false;
                            noneAssets = false;
                        }
                    }
                }
            }

            if (((player.id + 1) % 4) == lastPlayerWhoBet || Capot)
            {
                if (lastPlayerWhoBet == 0 || lastPlayerWhoBet == 2)
                    teamContract = 1;
                else
                    teamContract = 2;
                infos.teamContract = teamContract;
                infos.pointsBet = pointsBet;
                infos.Capot = Capot;
                infos.colorBet = colorBet;
                infos.allAssets = allAssets;
                infos.noneAssets = noneAssets;
                infos.GoToNextStep = true;
            }

            bets[player.id] = msg;
            if (!infos.GoToNextStep)
            {
                infos.PrivatePlayer = player.id;
                infos.PrivateMessage = "Your bet : " + bets[player.id];
            }

            if (EverybodySkipped())
            {
                infos.PublicMessage = "Everybody skipped, restarting the round.";
                infos.RestartRound = true;
                return infos;
            }
            return infos;
        }

        private string[] IsInvalidBet(string bet)
        {
            String[] strings;

            strings = bet.Split(" ");
            if (strings.Length != 2)
                return null;
            try
            {
                if (!strings[0].Equals("Capot"))
                {
                    int nb = Int32.Parse(strings[0]);
                    Boolean check = false;
                    for (int i = 80; i <= 160; i += 10)
                    {
                        if (nb == i)
                            check = true;
                    }
                    if (!check || nb <= pointsBet)
                        return null;
                }
            }
            catch (Exception e)
            {
                return null;
            }
            if (strings[1].Equals("AllAsset") || strings[1].Equals("NoneAsset"))
                return strings;
            foreach (CardColor c in Enum.GetValues(typeof(CardColor)))
            {
                if (strings[1].Equals(c.ToString()))
                    return strings;
            }
            return null;
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
            infos.PrivateMessage = "This is not your turn to bet.";
            infos.ValidTurn = false;
            return infos;
        }

        /// <summary>
        /// function called when the step is over
        /// </summary>
        /// <returns>a string to tell players the step is over</returns>
        string IStep.StepOver()
        {
            string stringAsset;
            if (allAssets)
                stringAsset = "All Assets";
            else if (noneAssets)
                stringAsset = "None Assets";
            else
                stringAsset = "asset at " + colorBet.ToString();
            string str = "\n" + BetStatus();
            str += "\nThe Team " + teamContract + " (players " + ((teamContract == 1) ? 0 : 1) + " and " + ((teamContract == 1) ? 2 : 3) + ") needs to make " + getPoints() + " with ";
            str += stringAsset;
            str += "\n";
            return str;
        }

        string getPoints()
        {
            string str;
            if (Capot)
                str = "Capot";
            else
                str = "at least " + pointsBet + " points";
            return str;
        }

        string BetStatus()
        {
            string betsStatus = "Bets :\n";
            for (int i = 0; i < bets.Length; i++)
            {
                betsStatus += "Player " + i + " : ";
                if (bets[i] != null)
                    betsStatus += bets[i];
                else
                    betsStatus += "no bet yet";
                betsStatus += "\n";
            }
            return betsStatus;
        }

        Boolean EverybodySkipped()
        {
            foreach (string bet in bets)
            {
                if (bet == null || !bet.Equals("Skip"))
                    return false;
            }
            return true;
        }
    }
}
