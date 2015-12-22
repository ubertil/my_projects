## Makefile for Makefile in /home/uberti_l/rendu/CPE_2015_bsq
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Mon Nov 30 09:38:02 2015 louis-emile uberti-ares
## Last update Mon Dec 21 20:31:31 2015 louis-emile uberti-ares
##

NAME	= bsq

SRCS	= main.c \
	  free_all.c \
	  get_matrix.c \
	  my_core.c \
	  prepare_file.c \
	  display_square.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

CFLAGS	= -Wall -Werror -Wextra -W -pedantic -ansi

CC	= cc

LIB	= -Llib/my -lmy

MAKE	= make re

all: $(NAME)

$(NAME):$(OBJS)
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
