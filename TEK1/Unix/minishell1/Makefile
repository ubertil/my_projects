##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Jan 24 20:33:54 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	mysh

SRCS		=	main.c \
			signal_handle.c \
			fork_handler.c \
			get_start.c \
			my_setenv.c \
			my_unsetenv.c \
			show_env.c \
			my_cd.c \
			find_help.c \
			do_execve.c \
			to_free.c \
			change_env_line.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

LIB		=	-lmy -Llib/my

CC		=	cc

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
ECHO		=	/bin/echo -e


CFLAGS		=	-W -Wall -Werror -Wextra -pedantic

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@cd lib/my ; make all -f Makefile
		@$(ECHO) $(BLUE)$(NAME)$(GREEN) BY UBERTI_L$(DEFAULT)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LIB) && \
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

fclean:		 clean cleanlib
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

cleanlib:
		 @cd lib/my ; make fclean -f Makefile

## Tools -----------------------------------------------------------------

re:		 cleanlib fclean all

.PHONY:		 fclean clean all re
