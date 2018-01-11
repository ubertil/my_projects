package com.jcoinche.client;

import com.jcoinche.protobuf.JCoincheProtocol;
import com.jcoinche.protobuf.JCoincheProtocol.GameRequest;

import io.netty.bootstrap.Bootstrap;
import io.netty.channel.*;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioSocketChannel;
import io.netty.handler.codec.protobuf.ProtobufDecoder;
import io.netty.handler.codec.protobuf.ProtobufEncoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32FrameDecoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32LengthFieldPrepender;
import io.netty.handler.ssl.SslContext;
import io.netty.handler.ssl.SslContextBuilder;
import io.netty.handler.ssl.util.InsecureTrustManagerFactory;

import java.util.Scanner;

/**
 * This class consists of the general configuration of the network client
 * Basic configuration includes :
 * <ul>
 *     <li>Server's IP Address</li>
 *     <li>Server's PORT</li>
 *     <li>SSL Protection</li>
 *     <li>TCP configuration</li>
 * </ul>
 *
 * Also defines how packets will be handled and encoded through our pipeline (mostly using google protobuf)
 * Then, starts to read on the standard Input to retrieve data typed by the client
 *
 * @see com.google.protobuf
 * @version 1.0
 * @author uberti_l
 */
public final class Client {
    private static void run(String host, Integer port) throws Exception {
        final SslContext sslCtx = SslContextBuilder.forClient().trustManager(InsecureTrustManagerFactory.INSTANCE).build();
        EventLoopGroup group = new NioEventLoopGroup();
        try {
            Bootstrap b = new Bootstrap();
            b.group(group)
                    .channel(NioSocketChannel.class)
                    .option(ChannelOption.TCP_NODELAY, true)
                    .handler(new ChannelInitializer<SocketChannel>() {
                        @Override
                        public void initChannel(SocketChannel ch) throws Exception {
                            ChannelPipeline p = ch.pipeline();
                            p.addLast(sslCtx.newHandler(ch.alloc(), host, port));
                            p.addLast(new ProtobufVarint32FrameDecoder());
                            p.addLast(new ProtobufDecoder(JCoincheProtocol.GameResponse.getDefaultInstance()));
                            p.addLast(new ProtobufVarint32LengthFieldPrepender());
                            p.addLast(new ProtobufEncoder());
                            p.addLast(new GameClient());
                        }
                    });
            System.out.println(String.format("Connecting to %s:%d...\n(Once connected, type 'QUIT' to leave the server)", host, port));
            Channel ch = b.connect(host, port).sync().channel();
            Scanner scanner = new Scanner(System.in);
            while (scanner.hasNext()) {
                GameRequest.Builder builder = GameRequest.newBuilder();
                String cmd = scanner.nextLine();
                if (cmd.equals("QUIT")) {
                    System.out.println("Disconnecting from the server...");
                    ch.close();
                    group.shutdownGracefully();
                    break;
                } else {
                    builder.setCard(cmd);
                    ch.writeAndFlush(builder.build());
                }
            }
        } finally {
            group.shutdownGracefully();
        }
    }

    public static void main(String[] args) {
        try {
            if (args.length == 2) {
                run(args[0], Integer.parseInt(args[1]));
            } else {
                System.out.println("Usage : program SERVER_IP SERVER_PORT");
                System.exit(-1);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}