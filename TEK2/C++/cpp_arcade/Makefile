##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Fri Apr  7 23:08:45 2017 Lous-Emile Uberti-Ares
##

## Variables -------------------------------------------------------------

NAME		=	arcade

SRCS		=	srcs/main.cpp \
			srcs/GameManager/GameManager.cpp \
			srcs/Menu/Menu.cpp \

OBJS		=	$(SRCS:.cpp=.o)

RM		=	rm -f

CC		=	g++

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile UBERTI and Nicolas TROGNOT"

LD_FLAGS	=	-ldl
CXXFLAGS	+=	-W -Wall -Werror -Wextra -I./include -std=c++14

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CXXFLAGS)" $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LD_FLAGS) && \
		 $(ECHO) $(GREEN) "["$(NAME)" COMPILED]" $(DEFAULT)
		cd lib/sfml/ && make
		cd lib/opengl/ && make
		cd games/snake/ && make
		cd games/pacman/ && make
		cd lib/libcaca/ && make

.cpp.o:
		@$(CC) $(CXXFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)
		cd lib/sfml/ && make clean
		cd lib/opengl/ && make clean
		cd lib/libcaca/ && make clean
		cd games/pacman/ && make clean
		cd games/snake/ && make clean

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)
		cd lib/sfml/ && make fclean
		cd lib/opengl/ && make fclean
		cd lib/libcaca/ && make fclean
		cd games/snake/ && make fclean
		cd games/pacman/ && make fclean

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
