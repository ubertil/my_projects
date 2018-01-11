namespace Coinche.Client
{
    using System;
    using System.Net;
    using System.Threading.Tasks;
    using DotNetty.Transport.Bootstrapping;
    using DotNetty.Transport.Channels;
    using DotNetty.Transport.Channels.Sockets;
    using DotNetty.Codecs.Protobuf;
    using Coinche.Google.Protobuf;

    /// <summary>
    /// Jcoinche Client Main Program
    /// </summary>
    class Program
    {
        /// <summary>
        /// Runs the client async.
        /// </summary>
        /// <returns>The client async.</returns>
        /// <param name="addr">Address.</param>
        /// <param name="port">Port.</param>
        static async Task RunClientAsync(IPAddress addr, short port)
        {
            var group = new MultithreadEventLoopGroup();

            try
            {
                var bootstrap = new Bootstrap();
                bootstrap
                    .Group(group)
                    .Channel<TcpSocketChannel>()
                    .Option(ChannelOption.TcpNodelay, true)
                    .Handler(new ActionChannelInitializer<ISocketChannel>(channel =>
                    {
                        IChannelPipeline pipeline = channel.Pipeline;

                        pipeline.AddLast(new ProtobufVarint32FrameDecoder());
                        pipeline.AddLast(new ProtobufDecoder(GameResponse.Parser));
                        pipeline.AddLast(new ProtobufVarint32LengthFieldPrepender());
                        pipeline.AddLast(new ProtobufEncoder());
                        pipeline.AddLast(new GameClient());
                    }));
                Console.WriteLine("Connecting to {0}:{1}...\n(Once connected, type 'QUIT' to leave the server)", addr, port);
                IChannel bootstrapChannel = await bootstrap.ConnectAsync(new IPEndPoint(addr, port));
                for (;;)
                {
                    string line = Console.ReadLine();
                    if (string.IsNullOrEmpty(line))
                        continue;
                    GameRequest request = new GameRequest
                    {
                        Play = line
                    };
                    if (string.Equals(line, "QUIT"))
                    {
                        await bootstrapChannel.CloseAsync();
                        break;
                    }
                    try
                    {
                        await bootstrapChannel.WriteAndFlushAsync(request);
                    }
                    catch
                    {
                    }
                }
                await bootstrapChannel.CloseAsync();
            }
            finally
            {
                group.ShutdownGracefullyAsync().Wait(100);
            }
        }

        /// <summary>
        /// The entry point of the program, where the program control starts and ends.
        /// </summary>
        /// <param name="args">The command-line arguments.</param>
        /// <returns>The exit code that is given to the operating system after the program ends.</returns>
        public static int Main(String[] args)
        {
            IPAddress addr;
            short port;

            if (args.Length != 2 || !IPAddress.TryParse(args[0], out addr) || !short.TryParse(args[1], out port))
            {
                Console.WriteLine("USAGE : client IP_ADDR PORT");
                return (-1);
            }
            try
            {
                RunClientAsync(addr, port).Wait();
            }
            catch (Exception e)
            {
                Console.WriteLine("Disconnected due to error\n{0}", e.StackTrace);
            }
            return 0;
        }
    }
}
