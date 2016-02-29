##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Feb 28 22:06:45 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	bin/sudoki-bi

SRCS		=	sources/main.c \
			sources/check_grids.c \
			sources/print_grids.c \
			sources/sudoku_core.c \
			sources/checker.c \
			sources/check_map.c \
			sources/get_grids_from_terminal.c \
			sources/check_line.c \
			sources/check_column.c \
			sources/check_block.c \
			sources/sudoku_solver.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	cc

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CFLAGS		=	-W -Wall -Werror -Wextra -pedantic

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME) $(RED) BY UBERTI_L WADEL_N $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN) "[SUCCESS]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) *~ && $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(OBJS)
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
