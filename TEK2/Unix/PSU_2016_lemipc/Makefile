##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Apr  2 11:49:53 2017 Lous-Emile Uberti-Ares
##

## Variables -------------------------------------------------------------

NAME		=	lemipc

SRCS		=	srcs/main.c \
			srcs/msg.c \
			srcs/map.c \
			srcs/free.c \
			srcs/ia_mode_random.c \
			srcs/ia_mode_target.c \
			srcs/utils.c \
			srcs/handle_args.c \
			srcs/semlock.c \
			srcs/signal.c \
			srcs/winner.c \

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

DEFAULT         =       "\e[00m"
GREEN           =       "\e[0;32m"
BLUE            =       "\e[1;36m"
RED             =       "\e[0;31m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile UBERTI and Nicolas WADEL"

CFLAGS		+=	-W -Wall -Werror -Wextra -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

man:
		sudo cp doc/lemipc.1.in /usr/share/man/man1/

gfx:
		cd graphics && make
		cp graphics/visualizer .

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CFLAGS)" $(DEFAULT)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) && \
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

manclean:
		sudo rm -f /usr/share/man/man1/lemipc.1.in

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re man manclean gfx
