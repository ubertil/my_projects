##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Oct 20 09:15:07 2015 louis-emile uberti-ares
## Last update Mon Nov 16 21:37:23 2015 louis-emile uberti-ares
##

NAME	= libmy.a

CREATE	= ar rc

SRCS	= my_getnbr.c \
	  my_put_nbr.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall

RAN	= ranlib

RM	= rm -rf

CC	= gcc

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CREATE) $(NAME) $(OBJS)
	$(RAN) $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM) *~

fclean: clean
	@$(RM) $(NAME)

re: clean fclean all

.PHONY: fclean clean all re
