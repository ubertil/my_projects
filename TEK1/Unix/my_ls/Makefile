##
## Makefile for Makefile in /home/uberti_l/rendu/PSU_2015_my_ls
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Wed Nov 18 10:06:39 2015 louis-emile uberti-ares
## Last update Sun Nov 29 21:28:16 2015 louis-emile uberti-ares
##

NAME	= my_ls

CC	= gcc

SRCS	= main.c \
	  my_ls.c \
	  parceur.c \
	  my_flags.c \
	  prepare_my_dir.c \
	  show_info.c \
	  my_flags2.c \
	  show_info2.c

OBJS	= $(SRCS:.c=.o)

LIB	= -lmy -Llib/my

MAKE	= make re

CFLAGS	= -Wall -Werror

RM	= rm -rf

all: $(NAME)

$(NAME):
	cd lib/my ; $(MAKE) -f Makefile
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean all clean re
