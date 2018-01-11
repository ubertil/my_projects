package com.jcoinche.client;

import com.jcoinche.protobuf.JCoincheProtocol.GameResponse;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.SimpleChannelInboundHandler;

/**
 * This class reads on the client's socket and displays the response from the server
 * Nothing fancy
 *
 * @see io.netty.channel.SimpleChannelInboundHandler
 * @version 1.0
 * @author uberti_l
 */
public class GameClient extends SimpleChannelInboundHandler<GameResponse> {

    @Override
    public void channelRead0(ChannelHandlerContext ctx, GameResponse msg) {
        if (msg.getResponseCode() != 200) {
            System.out.print(String.format("Error : %s", msg.getMessage()));
        } else {
            System.out.println(msg.getMessage());
        }
    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) {
        ctx.flush();
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {
        cause.printStackTrace();
        ctx.close();
    }
}