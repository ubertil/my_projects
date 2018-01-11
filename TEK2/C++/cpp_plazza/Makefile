##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sat Apr 29 17:03:51 2017 Lous-Emile Uberti-Ares
##

## Variables -------------------------------------------------------------

NAME		=	plazza

SRCS		=	srcs/main.cpp \
			srcs/Core.cpp \
			srcs/Network/Client.cpp \
			srcs/Network/Server.cpp \
			srcs/Process/ProcessManager.cpp \
			srcs/Process/Process.cpp \
			srcs/Process/Fork.cpp \
			srcs/Thread/Pool.cpp \
			srcs/UI/UI.cpp \

OBJS		=	$(SRCS:.cpp=.o)

RM		=	rm -f

CC		=	g++

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile UBERTI and Alexis Papadimitriou"

LD_FLAGS	=	-lpthread
CXXFLAGS	+=	-W -Wall -Werror -Wextra -I./include -std=c++14

## Compile ---------------------------------------------------------------

all:		title $(NAME)

ui:		CXXFLAGS += -DUSE_UI
ui:		all

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CXXFLAGS)" $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LD_FLAGS) && \
		 $(ECHO) $(GREEN) "["$(NAME)" COMPILED]" $(DEFAULT)

.cpp.o:
		@$(CC) $(CXXFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(OBJS) srcs/UI/UI.o && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
