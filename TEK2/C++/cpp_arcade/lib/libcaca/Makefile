##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Fri Apr  7 15:55:10 2017 Lous-Emile Uberti-Ares
##

## Variables -------------------------------------------------------------

NAME		=	lib_arcade_libcaca.so

SRCS		=	srcs/Libcaca.cpp

OBJS		=	$(SRCS:.cpp=.o)

RM		=	rm -f

CC1		=	g++
CC2		=	g++ -shared

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile Uberti and Nicolas Trognot"

LIB		=	-lcaca -ldl
CXXFLAGS	+=	-W -Wall -Werror -Wextra -std=c++14 -I./include -fPIC

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) "Compiled with" "$(CXXFLAGS)"
		@$(ECHO) $(GREEN)$(CONTRIBUTORS)$(DEFAULT)

$(NAME):	$(OBJS)
		@$(CC2) -o $(NAME) $(OBJS) $(LIB) && \
		 $(ECHO) $(GREEN) "["$(NAME)" BUILT]" $(DEFAULT)
		cp lib_arcade_libcaca.so ../

.cpp.o:
		@$(CC1) $(CXXFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)
		rm -f ../lib_arcade_libcaca.so

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
