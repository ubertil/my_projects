## Makefile for Makefile in /home/uberti_l/rendu/CPE_2015_Pushswap
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Nov  3 10:36:58 2015 louis-emile uberti-ares
## Last update Thu Nov 19 14:41:11 2015 louis-emile uberti-ares
##

NAME	= push_swap

SRCS	= pushswap.c \
	  my_instructions.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

MAKE	= make re

LIB	= -lmy -Llib/my

CC	= gcc

CFLAGS	= -Wall -pedantic -Wextra -Werror

all: $(NAME)

$(NAME):
	cd lib/my ; $(MAKE) -f Makefile
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	cd lib/my ; make clean -f Makefile
	$(RM) *~
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: clean fclean all re
