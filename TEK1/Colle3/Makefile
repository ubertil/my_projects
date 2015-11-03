##
## Makefile for Makefile in /home/uberti_l/rendu/Piscine_C_evalexpr
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Oct 20 09:25:02 2015 louis-emile uberti-ares
## Last update Sat Oct 24 19:54:47 2015 louis-emile uberti-ares
##

NAME	= colle3

SRC	= colle1-1.c \
	  colle1-2.c \
	  colle1-3.c \
	  colle1-4.c \
	  colle1-5.c \
	  colle-commune.c \
	  colle3.c \

LIB	= -lmy -L./lib/my

RM	= rm -rf

CC	= cc

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(SRC) $(LIB)

clean:
	@$(RM) *~ *#

fclean:
	@$(RM) $(NAME)

re: fclean all clean
