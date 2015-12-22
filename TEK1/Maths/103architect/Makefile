##
## Makefile for Makefile in /home/uberti_l/rendu/103architect
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Wed Dec  9 13:24:17 2015 louis-emile uberti-ares
## Last update Tue Dec 15 17:18:42 2015 louis-emile uberti-ares
##

NAME	= 103architect

SRCS	= main.c \
	  parceur.c \
	  103architect.c \
	  delete.c

CFLAGS	= -Wall -Werror -W -Wextra -ansi -pedantic

all: $(NAME)

$(NAME):
	cc -o $(NAME) $(SRCS) -lm $(CFLAGS)

clean:
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re: fclean all clean

.PHONY: clean fclean re all
