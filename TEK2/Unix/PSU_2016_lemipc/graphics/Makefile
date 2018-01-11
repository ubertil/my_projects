##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Fri Mar 31 17:45:42 2017 Lous-Emile Uberti-Ares
##

## Variables -------------------------------------------------------------

NAME		=	visualizer

SRCS		=	srcs/main.cpp

OBJS		=	$(SRCS:.cpp=.o)

RM		=	rm -f

CC		=	g++

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile Uberti and Nicolas Wadel"

LIB		=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -ldl
CXXFLAGS	+=	-W -Wall -Werror -Wextra -std=c++14 -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) "Compiled with" "$(CXXFLAGS)"
		@$(ECHO) $(GREEN)$(CONTRIBUTORS)$(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LIB) && \
		 $(ECHO) $(GREEN) "["$(NAME)" COMPILED]" $(DEFAULT)
.cpp.o:
		@$(CC) $(CXXFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
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
