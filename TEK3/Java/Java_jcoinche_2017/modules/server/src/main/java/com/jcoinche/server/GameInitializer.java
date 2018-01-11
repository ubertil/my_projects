package com.jcoinche.server;

import io.netty.buffer.Unpooled;
import io.netty.channel.*;
import io.netty.channel.socket.SocketChannel;
import io.netty.handler.codec.protobuf.ProtobufDecoder;
import io.netty.handler.codec.protobuf.ProtobufEncoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32FrameDecoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32LengthFieldPrepender;
import io.netty.handler.ssl.SslContext;
import io.netty.util.CharsetUtil;

import com.jcoinche.protobuf.JCoincheProtocol;

/**
 * This class represents the life and execution flow of an upcomming TCP packet
 *
 * <b>Each packet</b> will go through our defined workflow from our custom pipeline, represented by layers.
 * This server implements several layers, in the order below :
 * <ul>
 *     <li>The SSL layer which will make sure that the packet is comming from a known source (the JCoincheClient here)</li>
 *     <li>4 layers of Google protobuf encode/decode so we can use the data we receive</li>
 *     <li>The GameManager which implements our business logic</li>
 * </ul>
 *
 * @see com.google.protobuf
 * @see com.jcoinche.server.Server
 * @version 1.0
 * @author uberti_l
 */
public class GameInitializer extends ChannelInitializer<SocketChannel> {

    private final SslContext sslCtx;
    private int nbPlayers;

    /**
     * Basic constructor which retrieves the ssl configuration from our server
     *
     * @param sslCtx The ssl configuration
     * @param nbPlayers
     */
    public GameInitializer(SslContext sslCtx, int nbPlayers) {
        this.sslCtx = sslCtx;
    }

    @Override
    public void initChannel(SocketChannel ch) throws Exception {
        ChannelPipeline pipeline = ch.pipeline();
        if (this.nbPlayers <= 100) {
            pipeline.addLast(sslCtx.newHandler(ch.alloc()));
            // On top of the SSL handler, add the text line codec.
            pipeline.addLast(new ProtobufVarint32FrameDecoder());
            pipeline.addLast(new ProtobufDecoder(JCoincheProtocol.GameRequest.getDefaultInstance()));
            pipeline.addLast(new ProtobufVarint32LengthFieldPrepender());
            pipeline.addLast(new ProtobufEncoder());
            pipeline.addLast(new GameManager());
        }
        else {
            // Gently say that there is no more space for extra players (queue is full)
            pipeline.addLast(new SimpleChannelInboundHandler<String>() {
                @Override
                public void channelActive(final ChannelHandlerContext ctx) {
                    ctx.writeAndFlush(Unpooled.copiedBuffer("JCoinche-Server : Game room is full. Please come back later.\r\n", CharsetUtil.UTF_8)).addListener(ChannelFutureListener.CLOSE);
                }

                @Override
                public void channelRead0(ChannelHandlerContext ctx, String msg) {
                }
            });
        }
    }
}