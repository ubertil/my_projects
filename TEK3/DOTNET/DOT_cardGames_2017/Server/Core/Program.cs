namespace Coinche.Server
{
    using System;
    using System.Threading.Tasks;
    using DotNetty.Transport.Bootstrapping;
    using DotNetty.Transport.Channels;
    using DotNetty.Transport.Channels.Sockets;
    using DotNetty.Codecs.Protobuf;
    using Coinche.Google.Protobuf;
    using System.Net;

    /// <summary>
    /// JCoinche Server main class
    /// </summary>
    class Program
    {
        /// <summary>
        /// Runs the server async.
        /// </summary>
        /// <returns>The server async.</returns>
        static async Task RunServerAsync(IPAddress addr, short port)
        {
            var bossGroup = new MultithreadEventLoopGroup(1);
            var workerGroup = new MultithreadEventLoopGroup();

            try
            {
                var bootstrap = new ServerBootstrap();
                bootstrap
                    .Group(bossGroup, workerGroup)
                    .Channel<TcpServerSocketChannel>()
                    .Option(ChannelOption.SoBacklog, 100)
                    .ChildOption(ChannelOption.SoKeepalive, true)
                    .ChildHandler(new ActionChannelInitializer<ISocketChannel>(channel =>
                    {
                        IChannelPipeline pipeline = channel.Pipeline;

                        pipeline.AddLast(new ProtobufVarint32FrameDecoder());
                        pipeline.AddLast(new ProtobufDecoder(GameRequest.Parser));
                        pipeline.AddLast(new ProtobufVarint32LengthFieldPrepender());
                        pipeline.AddLast(new ProtobufEncoder());
                        pipeline.AddLast(new GameManager());
                    }));
                Console.WriteLine("Server listening on {0}:{1}\nWaiting for connections...", addr.ToString(), port);    
                IChannel bootstrapChannel = await bootstrap.BindAsync(new IPEndPoint(addr, port));
                Console.ReadLine();
                await bootstrapChannel.CloseAsync();
            }
            finally
            {
                Task.WaitAll(bossGroup.ShutdownGracefullyAsync(), workerGroup.ShutdownGracefullyAsync());
            }
        }

        /// <summary>
        /// The entry point of the program, where the program control starts and ends.
        /// </summary>
        /// <param name="args">The command-line arguments.</param>
        /// <returns>The exit code that is given to the operating system after the program ends.</returns>
        static void Main(String[] args)
        {
            IPAddress addr;
            short port;

            if (args.Length != 2 || !IPAddress.TryParse(args[0], out addr) || !short.TryParse(args[1], out port))
                Console.WriteLine("USAGE : server IP_ADDR PORT");
            else
                RunServerAsync(addr, port).Wait();
        }
    }
}