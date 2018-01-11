namespace Coinche.Server
{ 
    using System; 
    using System.Collections.Generic; 
    using Coinche.Tools; 
    using Coinche.Google.Protobuf; 
    using DotNetty.Transport.Channels; 
 
    /// <summary> 
    /// Class to handle new connections comming from different clients 
    ///  
    /// This is only the TCPLayer, the business logic is implemented through the GameRoom object which possesses the rules 
    /// </summary> 
    public class GameManager : SimpleChannelInboundHandler<GameRequest> 
    { 
        /// <summary> 
        /// Gets a value indicating whether this <see cref="T:Jcoinche.Server.GameServer"/> is sharable. 
        /// </summary> 
        /// <value><c>true</c> if is sharable; otherwise, <c>false</c>.</value> 
        public override bool IsSharable => true; 
 
        /// <summary> 
        /// GameRoom where 4 players are gathered 
        /// </summary> 
        private static volatile List<GameRoom> Rooms = new List<GameRoom>(); 
 
        /// <summary> 
        /// Gets the logger. 
        /// </summary> 
        /// <value>The logger.</value> 
        private static Logger Logger = new Logger(); 
 
        /// <summary> 
        /// Initializes a new instance of the <see cref="T:Jcoinche.Server"/> class. 
        ///  
        /// Server is launched and listening on addr:port 
        /// </summary> 
        public GameManager() 
        { 
            if (Rooms.Count == 0) 
                Rooms.Add(new GameRoom(1));
        } 
 
        /// <summary> 
        /// First method when a player connects to the server 
        /// Direct him to the first gameroom available 
        /// </summary> 
        /// <param name="context">Context.</param> 
        public override void ChannelActive(IChannelHandlerContext context) 
        { 
            bool added = false;

            lock (this)
            {
                foreach (GameRoom room in Rooms)
                {
                    if (room.NbPlayers != 4)
                    {
                        room.AddPlayer(context);
                        Logger.Info(String.Format("[{0}][+] Player connected [{1}] (Room size : {2})", room.RoomName, context.Channel.RemoteAddress, room.NbPlayers));
                        added = true;
                        break;
                    }
                }
                if (!added)
                {
                    // No room left with space, create a new one 
                    Rooms.Add(new GameRoom(Rooms.Count + 1));
                    // Add the player in the newly created room 
                    Rooms[Rooms.Count - 1].AddPlayer(context);
                    Logger.Info(String.Format("[+] New room created : {0}", Rooms[Rooms.Count - 1].RoomName));
                    Logger.Info(String.Format("[{0}][+] Player connected (Room size : {1})", Rooms[Rooms.Count - 1].RoomName,
                                              Rooms[Rooms.Count - 1].NbPlayers));
                }
            }
        }

        /// <summary>
        /// Disconnects someone from our server
        /// </summary>
        /// <param name="context">Context.</param>
        public override void ChannelInactive(IChannelHandlerContext context)
        {
            foreach (GameRoom room in Rooms)
            {
                int playerIdx = room.GetPlayerIdx(context);
                if (playerIdx != -1)
                {
                    room.RemovePlayer(playerIdx);
                    Logger.Info(String.Format("[{0}][-] Player disconnected (Room size : {1})", room.RoomName, room.NbPlayers));
                    break;
                }
            }
        }
 
        /// <summary> 
        /// Read incomming message and send it to the corresponding GameRoom 
        /// </summary> 
        /// <param name="context">Context.</param> 
        /// <param name="message">Message.</param> 
        protected override void ChannelRead0(IChannelHandlerContext context, GameRequest message) 
        { 
            foreach (GameRoom room in Rooms) 
            { 
                int playerIdx = room.GetPlayerIdx(context); 
                if (playerIdx != -1) 
                { 
                    room.ForwardToGame(playerIdx, message); 
                    break; 
                } 
            } 
        } 
 
        /// <summary> 
        /// Flush the socket 
        /// </summary> 
        /// <param name="context">Context.</param> 
        public override void ChannelReadComplete(IChannelHandlerContext context) => context.Flush(); 
 
        /// <summary> 
        /// Get the exception and log it 
        /// </summary> 
        /// <param name="context">Context.</param> 
        /// <param name="exception">Exception.</param> 
        public override void ExceptionCaught(IChannelHandlerContext context, Exception exception) 
        { 
            Console.WriteLine("{0}", exception.StackTrace); 
            Logger.Fatal(exception.ToString()); 
            context.CloseAsync(); 
        } 
    } 
}