namespace Coinche.Client
{
    using System;
    using DotNetty.Transport.Channels;
    using Coinche.Google.Protobuf;

    /// <summary>
    /// Game client.
    /// </summary>
    public class GameClient : SimpleChannelInboundHandler<GameResponse>
    {
        /// <summary>
        /// Display the received response from the server
        /// </summary>
        /// <param name="context">Context.</param>
        /// <param name="msg">Message.</param>
        protected override void ChannelRead0(IChannelHandlerContext context, GameResponse msg)
        {
            if (msg.ResponseCode != 200)
                Console.WriteLine("Erreur : {0}", msg.Message);
            else
                Console.WriteLine(msg.Message);
        }

        /// <summary>
        /// Print the caught exception
        /// </summary>
        /// <param name="context">Context.</param>
        /// <param name="exception">Exception.</param>
        public override void ExceptionCaught(IChannelHandlerContext context, Exception exception)
        {
            Console.WriteLine(DateTime.Now.Millisecond);
            Console.Write(exception.StackTrace);
            context.CloseAsync();
        }
    }
}