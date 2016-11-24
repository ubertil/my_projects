##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Jul  3 13:31:54 2016 Louis-Emile Uberti
##

## Variables -------------------------------------------------------------

NAME		=	fire

SRCS		=	srcs/flame.c \
				srcs/free_all.c \
				srcs/get_gradient.c \
				srcs/set_background.c \
				srcs/tekgetpixel.c \
				srcs/tekpixel.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

LIB		=	-L/Users/uberti_l/.froot/include \
			-L/Users/uberti_l/.froot/lib \
			-framework OpenGL \
			-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
			-lsfml-system -lstdc++ -ldl -lm -lpthread

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Uberti_l"

CFLAGS		+=	-W -Wall -Werror -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CFLAGS)"$(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LIB) && \
		 $(ECHO) $(GREEN) "[BINARY COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

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
