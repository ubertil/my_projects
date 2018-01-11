using Coinche.Tools;
using System;
using System.Collections.Generic;

namespace Coinche.GameRules.Steps
{
    public class Announce : IStep
    {
        string[] announces;
        int pointAnnounce;
        int teamAnnounce;
        int playerAnnounce;

        public Announce()
        {
            announces = new string[4];
        }
        /// <summary>
        /// reset the step
        /// </summary>
        void IStep.Reset()
        {
            for (int i = 0; i < announces.Length; i++)
            {
                announces[i] = null;
            }
            pointAnnounce = -1;
            teamAnnounce = -1;
            playerAnnounce = -1;
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
            infos.PublicMessage = AnnounceStatus();
            infos.PrivatePlayer = player.id;
            string str = player.GetHandAsString();
            str += "Your turn to announce :\n";
            str += "Carre + Value (Nines, Tens, Jacks, Queens, Kings, Aces)\n";
            str += "Sequence + Color (Heart, Spade, Diamond, Club) + Number of cards from the ace (3, 4, 5)\n";
            str += "Examples :\n";
            str += "\tCarre Queens\n";
            str += "\tSequence Spade 3\n";
            str += "\tNothing\n";
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
        GameInfo IStep.DoStep(Player player, string msg, Boolean allAssets, Boolean noneAssets, CardColor colorBet, int firstPlayer)
        {
            GameInfo infos = new GameInfo();

            string[] announce = IsInvalidAnnounce(player, msg);
            if (announce == null)
            {
                infos.PrivatePlayer = player.id;
                infos.PrivateMessage = "Invalid announce";
                infos.ValidTurn = false;
                return infos;
            }
            announces[player.id] = msg;
            if (isFull())
            {
                findBestAnnounce();
                infos.pointAnnounce = pointAnnounce;
                infos.teamAnnounce = teamAnnounce;
                infos.GoToNextStep = true;
            }
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
            infos.PrivateMessage = "This is not your turn to announce.";
            infos.ValidTurn = false;
            return infos;
        }

        /// <summary>
        /// function called when the step is over
        /// </summary>
        /// <returns>a string to tell players the step is over</returns>
        string IStep.StepOver()
        {
            if (teamAnnounce != -1)
                return "The team " + teamAnnounce + " made the best announcement (" + announces[playerAnnounce] + ") of " + pointAnnounce + " points\n";
            else
                return "No announce has been made\n";
        }

        private string[] IsInvalidAnnounce(Player player, string announce)
        {
            string[] strings;

            strings = announce.Split(" ");
            if (strings[0].Equals("Nothing"))
            {
                if (strings.Length != 1)
                    return null;
                return strings;
            }
            else if (strings[0].Equals("Carre"))
            {
                Boolean check = false;
                CardValue value = CardValue.Seven;
                if (strings.Length != 2)
                    return null;
                foreach (CardValue v in Enum.GetValues(typeof(CardValue)))
                {
                    if (strings[1].Equals(v.ToString()))
                    {
                        value = v;
                        check = true;
                    }
                }
                if (!check || value == CardValue.Seven || value == CardValue.Eight)
                    return null;
                if (!gotCarre(player.Hand, value))
                    return null;
                return strings;
            }
            else if (strings[0].Equals("Sequence"))
            {
                CardColor color = CardColor.Heart;
                Boolean check = false;
                int num;
                if (strings.Length != 3)
                    return null;
                foreach (CardColor c in Enum.GetValues(typeof(CardColor)))
                {
                    if (strings[1].Equals(c.ToString()))
                    {
                        color = c;
                        check = true;
                    }
                }
                if (!check)
                    return null;
                if (!strings[2].Equals("3") && !strings[2].Equals("4") &&
                    !strings[2].Equals("5"))
                    return null;
                num = Int32.Parse(strings[2]);
                if (!gotSequence(player.Hand, color, num))
                    return null;
                return strings;
            }
            return null;
        }

        Boolean isFull()
        {
            foreach (string s in announces)
            {
                if (s == null)
                    return false;
            }
            return true;
        }

        Boolean gotSequence(List<Card>cards, CardColor color, int num)
        {
            int i = 0;
            CardValue value = CardValue.Ace;
            Boolean research = true;
            while (research)
            {
                research = false;
                foreach (Card c in cards)
                {
                    if (c.Color == color && c.Value == value)
                    {
                        i++;
                        research = true;
                        value++;
                    }
                }
            }
            if (i >= num)
                return true;
            else
                return false;
        }

        Boolean gotCarre(List<Card> cards, CardValue value)
        {
            int i = 0;
            foreach (Card c in cards)
            {
                if (c.Value == value)
                    i++;
            }
            if (i == 4)
                return true;
            else
                return false;
        }

        void findBestAnnounce()
        {
            for (int i = 0; i < announces.Length;  i++)
            {
                if (!announces[i].Equals("Nothing"))
                {
                    string[] arr = announces[i].Split(" ");
                    if (pointAnnounce == -1 || getAnnouncePoints(arr) > pointAnnounce)
                    { 
                        pointAnnounce = getAnnouncePoints(arr);
                        if (i == 0 || i == 2)
                            teamAnnounce = 1;
                        else
                            teamAnnounce = 2;
                    }
                }
            }
        }

        int getAnnouncePoints(string[] arr)
        {
            if (arr[0].Equals("Carre"))
            {
                if (arr[1].Equals("Jack"))
                    return 200;
                else if (arr[1].Equals("Nine"))
                    return 150;
                else
                    return 100;
            }
            else if (arr[0].Equals("Sequence"))
            {
                if (arr[2].Equals("3"))
                    return 20;
                else if (arr[2].Equals("4"))
                    return 50;
                else if (arr[2].Equals("5"))
                    return 100;
            }
            return 0;
        }

        string AnnounceStatus()
        {
            string announceStatus = "Announces :\n";
            for (int i = 0; i < announces.Length; i++)
            {
                announceStatus += "Player " + i + " : ";
                if (announces[i] != null)
                    announceStatus += announces[i];
                else
                    announceStatus += "no announce yet";
                announceStatus += "\n";
            }
            return announceStatus;
        }
    }
}
