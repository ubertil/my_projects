##
## Makefile for Makefile in /home/uberti_l/rendu/Piscine_C_bistromathique
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Wed Oct 28 12:33:59 2015 louis-emile uberti-ares
## Last update Sun Nov  1 20:43:56 2015 louis-emile uberti-ares
##

NAME	= calc

SRCS	= bistromathique.c \
	  is_expr_valid.c \
	  get_expr.c \
	  tools.c \
	  infin_add.c \
	  my_div.c \
	  tools_div.c \
	  my_mult.c \
	  mult_return.c \
	  eval_expr.c \
	  my_mod.c \

OBJS	= $(SRCS:.c=.o)

LIB	= -lmy -L./lib/my

CC	= gcc

CFLAGS	= -Wall

RM	= rm -rf

MAKE	= make re

all: $(NAME)

$(NAME):
	cd lib/my ; $(MAKE) -f Makefile
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
