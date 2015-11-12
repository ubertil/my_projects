##
## Makefile for Makefile in /home/uberti_l/rendu/101pong
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Mon Nov  2 20:28:45 2015 louis-emile uberti-ares
## Last update Wed Nov  4 15:40:52 2015 louis-emile uberti-ares
##

NAME	= 101pong

SRCS	= 101pong.c \
	  main.c

OBJS	= $(SRCS:.c=.o)

LIB	= -lmy -L./lib/my -lm

CC	= gcc

CFLAGS	= -Wall

MAKE	= make re

RM	= rm -rf

all: $(NAME)

$(NAME):
	cd lib/my ; $(MAKE) -f Makefile
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
