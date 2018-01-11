package com.jcoinche.server;

import io.netty.bootstrap.ServerBootstrap;
import io.netty.channel.*;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.nio.NioServerSocketChannel;
import io.netty.handler.ssl.SslContext;
import io.netty.handler.ssl.SslContextBuilder;
import io.netty.handler.ssl.util.SelfSignedCertificate;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * This class consists of the general configuration of the network server
 * Basic configuration includes :
 * <ul>
 *     <li>Server's IP Address</li>
 *     <li>Server's PORT</li>
 *     <li>SSL Protection</li>
 *     <li>Threads and server capability</li>
 * </ul>
 *
 * A server is not supposed to be closed once launched
 * @version 1.0
 * @author uberti_l
 */
public class Server {
    private static int NB_PLAYERS = 1;
    private final static Logger LOGGER = Logger.getLogger(Server.class.getName());

    /**
     * Launch the server to start listening on <b>IP:PORT</b>
     * @throws Exception
     */
    public static void run(String ip, Integer port) throws Exception {
        SelfSignedCertificate ssc = new SelfSignedCertificate();
        SslContext sslCtx = SslContextBuilder.forServer(ssc.certificate(), ssc.privateKey()).build();
        EventLoopGroup bossGroup = new NioEventLoopGroup(1);
        EventLoopGroup workerGroup = new NioEventLoopGroup();
        try {
            ServerBootstrap b = new ServerBootstrap();
            b.group(bossGroup, workerGroup)
                    .channel(NioServerSocketChannel.class)
                    .option(ChannelOption.SO_BACKLOG, 4)
                    .childOption(ChannelOption.SO_KEEPALIVE, true)
                    .childHandler(new GameInitializer(sslCtx, NB_PLAYERS));
            LOGGER.log(Level.INFO, String.format("Server launched and listening on %s:%d", ip, port));
            b.bind(ip, port).sync().channel().closeFuture().sync();
        } finally {
            bossGroup.shutdownGracefully();
            workerGroup.shutdownGracefully();
        }
    }

    public static void main(String[] args) {
        try {
            if (args.length == 2) {
                run(args[0], Integer.parseInt(args[1]));
            } else {
                System.out.println("Usage : program IP PORT");
                System.exit(-1);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}