##
## Makefile for Makefile in /home/uberti_l/rendu/PSU_2015_my_select
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Mon Nov 30 20:59:07 2015 louis-emile uberti-ares
## Last update Wed Dec  2 16:34:31 2015 louis-emile uberti-ares
##

NAME	= my_select

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

CC	= gcc

LIB	= -lncurses -lmy -Llib/my

MAKE	= make re

CFLAGS	= -Wall -Werror -pedantic -ansi

all: $(NAME)

$(NAME):
	cd lib/my ; $(MAKE) -f Makefile
	@$(CC) -c $(SRCS) $(CFLAGS)
	@$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	@$(RM) *~
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean re all clean
