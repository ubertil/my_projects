##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Mar 27 01:44:24 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	libnanotekspice.a
PROG		=	nanotekspice

CREATE		=	ar rc

LIBSRCS		=	srcs/Parser/Parser.cpp \
			srcs/Controller/Controller.cpp \
			srcs/Manager.cpp \
			srcs/components/Cmp2716.cpp \
			srcs/components/Cmp4001.cpp \
			srcs/components/Cmp4008.cpp \
			srcs/components/Cmp4011.cpp \
			srcs/components/Cmp4013.cpp \
			srcs/components/Cmp4017.cpp \
			srcs/components/Cmp4030.cpp \
			srcs/components/Cmp4040.cpp \
			srcs/components/Cmp4069.cpp \
			srcs/components/Cmp4071.cpp \
			srcs/components/Cmp4081.cpp \
			srcs/components/Cmp4094.cpp \
			srcs/components/Cmp4514.cpp \
			srcs/components/Cmp4801.cpp \
			srcs/components/CmpClock.cpp \
			srcs/components/CmpTrue.cpp \
			srcs/components/CmpInput.cpp \
			srcs/components/CmpFalse.cpp \
			srcs/components/CmpOutput.cpp

NANOSRCS	=	srcs/main.cpp \
			srcs/Parser/Parser.cpp \
			srcs/Controller/Controller.cpp \
			srcs/Manager.cpp \
			srcs/components/Cmp2716.cpp \
			srcs/components/Cmp4001.cpp \
			srcs/components/Cmp4008.cpp \
			srcs/components/Cmp4011.cpp \
			srcs/components/Cmp4013.cpp \
			srcs/components/Cmp4017.cpp \
			srcs/components/Cmp4030.cpp \
			srcs/components/Cmp4040.cpp \
			srcs/components/Cmp4069.cpp \
			srcs/components/Cmp4071.cpp \
			srcs/components/Cmp4081.cpp \
			srcs/components/Cmp4094.cpp \
			srcs/components/Cmp4514.cpp \
			srcs/components/Cmp4801.cpp \
			srcs/components/CmpClock.cpp \
			srcs/components/CmpTrue.cpp \
			srcs/components/CmpInput.cpp \
			srcs/components/CmpFalse.cpp \
			srcs/components/CmpOutput.cpp \

LIBOBJS		=	$(LIBSRCS:.cpp=.o)
NANOBJS		=	$(NANOSRCS:.cpp=.o)

RM		=	rm -f

CC		=	g++

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
ECHO		=	/bin/echo -e

RUN		=	ranlib

CXXFLAGS	+=	-Wall -Werror -Wextra -std=c++14 -I./include -O3

## Compile ---------------------------------------------------------------

all:		title $(PROG) $(NAME)

title:
		@$(ECHO) "Compiled with" "$(CXXFLAGS)"
		@$(ECHO) $(BLUE)LIB$(RED)NANOTEKSPICE $(DEFAULT)

$(NAME):	$(LIBOBJS)
		@$(CREATE) $(NAME) $(LIBOBJS) && \
		 $(ECHO) $(GREEN) "[OBJS COMPILED]" $(BLUE) $(NAME) $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $(NAME)
		@ranlib $(NAME) && \
		 $(ECHO) $(GREEN) "[LIB]" $(BLUE) $(NAME) $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(RED) $(NAME)

$(PROG):	$(NANOBJS)
		@$(CC) -o $(PROG) $(NANOBJS) && \
		 $(ECHO) $(GREEN) "[PROG]" $(BLUE) $(PROG) $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $(PROG)

.c.o:
		@$(CC) $(CXXFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(NANOBJS) && $(RM) $(LIBOBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && $(RM) $(PROG) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all

.PHONY:		 fclean clean all re
