##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Thu Mar 16 11:30:00 2017 félix grellard
##

## Variables -------------------------------------------------------------

NAME		=	philo

SRCS		=	srcs/main.c \
			srcs/thread_observer.c \
			srcs/handle_resources.c \
			srcs/free.c \
			srcs/wait.c \
			srcs/utils.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

DEFAULT         =       "\e[00m"
GREEN           =       "\e[0;32m"
BLUE            =       "\e[1;36m"
RED             =       "\e[0;31m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile UBERTI and Felix GRELLARD"

LD_LIBRARY_PATH	=	-Wl,-rpath=. -L. -lriceferee
LDFLAGS		=	-pthread

CFLAGS		+=	-W -Wall -Werror -Wextra -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CFLAGS)" $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LD_LIBRARY_PATH) && \
		 $(ECHO) $(GREEN) "["$(NAME)" COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
