##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Oct 20 09:15:07 2015 louis-emile uberti-ares
## Last update Tue Dec 15 15:13:20 2015 louis-emile uberti-ares
##

NAME	= libmy.a

CREATE	= ar rc

SRCS	= my_putchar.c \
	  my_putstr_err.c \
	  my_putstr.c \
	  my_getnbr.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -W -Wall -ansi -pedantic -Wextra

RAN	= ranlib

RM	= rm -rf

CC	= gcc

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CREATE) $(NAME) $(OBJS)
	$(RAN) $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean clean all re
