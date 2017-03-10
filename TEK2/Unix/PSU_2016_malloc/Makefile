##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sat Feb 11 14:56:16 2017 alexis papadimitriou
##

## Variables -------------------------------------------------------------

NAME		=	libmy_malloc.so

SRCS		=	srcs/free.c \
			srcs/malloc.c \
			srcs/realloc.c \
			srcs/calloc.c \
			srcs/show_alloc_mem.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC1		=	gcc -c -fPIC -lpthread
CC2		=	gcc -shared

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"Made by papadi_a and uberti_l"

CFLAGS		+=	-W -Wall -Werror -Wextra -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) "Compiled with" "$(CFLAGS)"
		@$(ECHO) $(GREEN)$(CONTRIBUTORS)$(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC2) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN) "[.SO BUILT]" $(DEFAULT)

.c.o:
		@$(CC1) $(CFLAGS) -c $< -o $@  && \
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

re:		 fclean all clean

.PHONY:		 fclean clean all re
