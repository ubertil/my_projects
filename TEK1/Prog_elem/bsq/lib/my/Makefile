##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Oct 20 09:15:07 2015 louis-emile uberti-ares
## Last update Tue Nov 17 14:53:47 2015 louis-emile uberti-ares
##

NAME	= libmy.a

CREATE	= ar rc

SRCS	= my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_printf.c \
	  my_putnbr_base.c \
	  my_strlen.c \
	  my_showstr.c \
	  my_format1.c \
	  my_format2.c

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
	$(RM) $(OBJS)
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean clean all re
