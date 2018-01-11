namespace Coinche.Server
{
    using System;
    using Coinche.Google.Protobuf;
    using DotNetty.Transport.Channels;
    using System.Collections.Generic;
    using Coinche.GameRules;
    using global::Coinche.Tools;

    /// <summary> 
    /// This class represents a GameRoom which role is to let 4 players play together. 
    /// This let us abstract all the administration part of people joining and leaving a game. 
    /// Once 4 players are connected to the same GameRoom, <b>a game starts</b> 
    /// If<b>any player</b> leaves during the game, the session is restarted for everyone in the room. 
    /// </summary> 
    public class GameRoom
    {
        /// <summary> 
        /// The name of the room. 
        /// During construction, append the room number from the list (for example JCoincheGameRoom<b>1</b>) 
        /// </summary> 
        public string RoomName { get; } = "JCoincheGameRoom";

        /// <summary> 
        /// Present the server to connected users 
        /// </summary> 
        private const string Creators = "Come GRELLARD and Louis-Emile UBERTI";

        /// <summary> 
        /// The ASCII art. 
        /// </summary> 
        private const string AsciiArt = @"   ____ ___ ___ _ _  ____ _   _ _____ 
 / ___/ _ \_ _| \ | |/ ___| | | | ____|
| |  | | | | ||  \| | |   | |_| |  _|  
| |__| |_| | || |\  | |___|  _  | |___ 
 \____\___/___|_| \_|\____|_| |_|_____|";
        
        /// <summary> 
        /// The nb players. 
        /// </summary> 
        public int NbPlayers { get; set; } = 0;

        /// <summary> 
        /// Tells if the game is ready. 
        /// </summary> 
        public bool GameReady { get; set; } = false;

        /// <summary> 
        /// The players. 
        /// </summary> 
        private List<IChannelHandlerContext> Players = new List<IChannelHandlerContext>();

        private GameRules Rules;

        /// <summary> 
        /// Initializes a new instance of the <see cref="T:Jcoinche.Server.GameRoom"/> class. 
        /// </summary> 
        /// <param name="id">Identifier.</param> 
        public GameRoom(int id)
        {
            this.RoomName += id.ToString();
            for (int i = 0; i < 4; ++i)
                Players.Add(null);
            Rules = new GameRules();
        }

        /// <summary> 
        /// Gets the index of the player. 
        /// </summary> 
        /// <returns>The player index.</returns> 
        /// <param name="ctx">Ctx</param> 
        public int GetPlayerIdx(IChannelHandlerContext ctx)
        {
            if (ctx == null)
                return -1;
            for (int i = 0; i < 4; ++i)
                if (this.Players[i] != null && Players[i] == ctx)
                    return (i);
            return (-1);
        }

        /// <summary> 
        /// Add a player to the players entity 
        /// If the forth player is added, launch the game 
        /// <returns><c>true</c>, if player was added, <c>false</c> otherwise.</returns> 
        /// <param name="ctx">IChannelHandlerContext</param> 
        /// </summary> 
        public bool AddPlayer(IChannelHandlerContext ctx)
        {
            // Room is full 
            if (this.NbPlayers == 4)
                return false;
            int idx = -1;
            while (++idx < 4)
            {
                if (this.Players[idx] == null)
                {
                    this.Players[idx] = ctx;
                    break;
                }
            }
            this.NbPlayers += 1;
            // Greet the new player on our gameRoom 
            GameResponse response = new GameResponse
            {
                Message = String.Format("{0}\nWelcome to JCoinche Server 1.0 by {1}\n\n[+] Connected to room {2} as Player {3}", AsciiArt, Creators, RoomName, idx),
                ResponseCode = 200
            };
            this.WriteTo(idx, response);
            // Warn others players that someone connected 
            response.Message = String.Format(String.Format("Waiting for {0} more player(s)...", 4 - this.NbPlayers));
            this.Broadcast(response);
            // 4 players are here, let's start the game and warn the players 
            if (this.NbPlayers == 4)
            {
                this.GameReady = true;
                response.Message = "[+] All players are connected. Game will start now";
                this.Broadcast(response);
                this.Rules.LaunchGame();
                this.SendInfosToPlayers(this.Rules.PrepareNextStep());
            }
            return true;
        }

        private void SendInfosToPlayers(GameInfo infos)
        {
            if (infos.PublicMessage != null)
            {
                GameResponse response = new GameResponse
                {
                    Message = infos.PublicMessage,
                    ResponseCode = 200
                };
                this.Broadcast(response);
            }
            if (infos.PrivateMessage != null)
            {
                GameResponse response = new GameResponse
                {
                    Message = infos.PrivateMessage,
                    ResponseCode = 200
                };
                this.WriteTo(infos.PrivatePlayer, response);
            }
        }

        /// <summary> 
        /// Removes the player. 
        /// </summary> 
        /// <returns><c>true</c>, if player was removed, <c>false</c> otherwise.</returns> 
        /// <param name="idx">Index.</param> 
        public bool RemovePlayer(int idx)
        {
            if (idx < 0 || idx > 4)
                return false;
            else
            {
                this.Players[idx] = null;
                this.NbPlayers -= 1;
                GameResponse response = new GameResponse
                {
                    Message = String.Format("[-] Player n°{0} disconnected. Game suspended", idx),
                    ResponseCode = 200
                };
                this.Broadcast(response);
                this.GameReady = false;
                return true;
            }
        }

        /// <summary> 
        /// Broadcast the specified msg from the protobuf  
        /// </summary> 
        /// <param name="msg">Message.</param> 
        public void Broadcast(GameResponse msg)
        {
            for (int i = 0; i < 4; ++i)
                this.WriteTo(i, msg);
        }

        /// <summary> 
        /// Forward what the server received to the GameRules 
        /// GameRules will determine if it's currently this player turn and if his move is valid 
        /// </summary> 
        /// <param name="playerIdx">Player index.</param> 
        /// <param name="request">Messag from the player.</param> 
        public void ForwardToGame(int playerIdx, GameRequest request)
        {
            if (!this.GameReady)
            {
                GameResponse response = new GameResponse
                {
                    Message = String.Format("Game hasn't started yet. Please wait for {0} more players", 4 - NbPlayers),
                    ResponseCode = 403
                };
                this.WriteTo(playerIdx, response);
            }
            else
            {
                // Forward to GameRules 
                GameInfo playInfo;
                playInfo = Rules.Play(playerIdx, request.Play);
                SendInfosToPlayers(playInfo);
                if (playInfo.ValidTurn)
                    SendInfosToPlayers(Rules.PrepareNextStep());
            }
        }

        /// <summary> 
        /// Send a message to a specific player (the one at <code>playerIdx</code>) 
        /// <returns><c>true</c>, if message was send, <c>false</c> otherwise.</returns> 
        /// <param name="playerIdx">Player idx</param> 
        /// <param name="msg">Message to send</param> 
        /// </summary> 
        public bool WriteTo(int playerIdx, GameResponse msg)
        {
            if (playerIdx < 0 || playerIdx >= 4 || this.Players[playerIdx] == null)
                return false;
            else
            {
                this.Players[playerIdx].WriteAndFlushAsync(msg);
                return true;
            }
        }
    }
}