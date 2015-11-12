##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Oct 20 09:15:07 2015 louis-emile uberti-ares
## Last update Thu Nov 12 13:03:39 2015 louis-emile uberti-ares
##

NAME	= libmy.a

CREATE	= ar rc

SRCS	= my_putchar.c \
	  my_putstr.c \
	  my_put_nbr.c \
	  my_putnbr_base.c \
	  my_strlen.c \
	  my_showstr.c \
	  my_printf.c \
	  my_format1.c \
	  my_format2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall

RAN	= ranlib

RM	= rm -rf

CC	= cc

all: $(NAME)

$(NAME):
	cd lib/my ; $(CC) -c $(SRCS) $(CFLAGS)
	cd lib/my ; $(CREATE) $(NAME) $(OBJS)
	cd lib/my ; $(RAN) $(NAME)

clean:
	cd lib/my ; $(RM) $(OBJS)

fclean: clean
	cd lib/my ; $(RM) $(NAME)

re: fclean all clean

.PHONY: fclean clean all re
