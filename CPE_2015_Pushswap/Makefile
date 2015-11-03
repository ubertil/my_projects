##
## Makefile for Makefile in /home/uberti_l/rendu/CPE_2015_Pushswap
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Nov  3 10:36:58 2015 louis-emile uberti-ares
## Last update Tue Nov  3 10:42:03 2015 louis-emile uberti-ares
##

NAME	= push_swap

SRCS	= main.c \
	  trifusion.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

LIB	= -lmy -L.lib/my

CC	= gcc

CFLAGS	= -Wall

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean fclean all clean

.PHONY: clean fclean all re
