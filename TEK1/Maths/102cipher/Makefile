##
## Makefile for Makefile in /home/uberti_l/rendu/101pong
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Mon Nov  2 20:28:45 2015 louis-emile uberti-ares
## Last update Sat Nov 28 19:30:47 2015 Nicolas Wadel
##

NAME	= 102cipher

SRCS	= main.c \
	  encry.c \
	  decry.c \
	  super_matrice.c \
	  my_strlen.c \

OBJS	= $(SRCS:.c=.o)

CC	= gcc -lm

CFLAGS	= -Wall

MAKE	= make re

RM	= rm -rf

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
