##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Mon Jan  4 12:40:05 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	105torus

SRCS		=	main.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -rf

LIB		=	-lmy -Llib/my

CC		=	cc

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
ECHO		=	/bin/echo -e


##CFLAGS		=	-W -Wall -Werror -Wextra -ansi -pedantic

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)$(GREEN) BY UBERTI_L AND TROGNO_N$(DEFAULT)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN) "[SUCCESS]" $(DEFAULT)

.c.o:
		@$(CC) $(LIB) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) *~
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all

.PHONY:		 fclean clean all re
