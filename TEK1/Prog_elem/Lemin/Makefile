##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Apr 24 16:17:19 2016 nicolas trognot
##

## Variables -------------------------------------------------------------

NAME		=	lem_in

SRCS		=	tools/get_next_line.c \
			tools/my_puterr.c \
			tools/my_strdup.c \
			tools/my_strlen.c \
			tools/my_putstr.c \
			tools/my_putnbr.c \
			tools/my_str_to_wordtab.c \
			tools/isnbr.c \
			tools/my_hard_getnbr.c \
			tools/my_strcmp.c \
			srcs/main.c \
			srcs/check_args.c \
			srcs/get_nbr_ants.c \
			srcs/recup_rooms.c \
			srcs/free_all.c \
			srcs/create_matrix.c \
			srcs/find_room.c \
			srcs/get_rooms_link.c \
			srcs/check_room.c \
			srcs/algo/launch_algorithm.c \
			srcs/algo/algo.c \
			srcs/algo/stock_results.c \
			srcs/algo/sort_results.c \
			srcs/algo/sanitize_result.c \
			srcs/algo/launch_feeder.c

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

CONTRIBUTORS	=	"by Grella_c, Wadel_n, Trogno_n and Uberti_l"

CFLAGS		+=	-W -Wall -Werror -Wextra -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" " $(CFLAGS)" $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN) "[BINARY COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[.o ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
