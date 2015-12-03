##
## Makefile for Makefile in /home/uberti_l/rendu/CPE_2015_bsq
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Mon Nov 30 09:38:02 2015 louis-emile uberti-ares
## Last update Tue Dec  1 11:12:33 2015 louis-emile uberti-ares
##

NAME	= bsq

SRCS	= main.c \
	  prepare_my_map.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

CFLAGS	= -Wall -Werror -pedantic -ansi

CC	= gcc

LIB	= -Llib/my -lmy

MAKE	= make re

all: $(NAME)

$(NAME):
	 cd lib/my ; $(MAKE) -f Makefile
	 $(CC) -c $(SRCS) $(CFLAGS)
	 $(CC) -o $(NAME) $(OBJS) $(LIB) $(CFLAGS)

clean:
	$(RM) *~
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean all clean re
