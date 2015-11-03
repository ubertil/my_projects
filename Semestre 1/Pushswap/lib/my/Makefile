##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Oct 20 09:15:07 2015 louis-emile uberti-ares
## Last update Tue Oct 20 09:20:06 2015 louis-emile uberti-ares
##

NAME	= libmy.a

CREATE	= ar rc

RAN	= ranlib

RM	= rm -rf

CC	= cc -c

all: $(NAME)

$(NAME):
	@$(CC) *.c
	@$(CREATE) $(NAME) *.o
	@$(RAN) $(NAME)

clean:
	@$(RM) *.o
	@$(RM) *~ *#

fclean: clean
	@$(RM) $(NAME)

re: fclean all
