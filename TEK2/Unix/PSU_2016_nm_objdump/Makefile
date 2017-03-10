##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Feb 26 21:54:24 2017 Lous-Emile Uberti-Ares
##

## Variables -------------------------------------------------------------

NMNAME		=	my_nm
DUMPNAME	=	my_objdump

NMSRCS		=	srcs/nm/main.c \
			srcs/nm/my_nm.c \
			srcs/nm/get_symbol.c \
			srcs/nm/organize.c \
			srcs/tools/open_file.c \

DUMPSRCS	=	srcs/objdump/main.c \
			srcs/objdump/my_objdump.c \
			srcs/objdump/get_flags.c \
			srcs/objdump/get_machine.c \
			srcs/objdump/get_sections.c \
			srcs/objdump/is_required.c \
			srcs/objdump/get_width.c \
			srcs/tools/open_file.c \

NMOBJS		=	$(NMSRCS:.c=.o)
DUMPOBJS	=	$(DUMPSRCS:.c=.o)

RM		=	rm -rf

CC		=	gcc

DEFAULT         =       "\e[00m"
GREEN           =       "\e[0;32m"
BLUE            =       "\e[1;36m"
RED             =       "\e[0;31m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile UBERTI"

CFLAGS		+=	-W -Wall -Werror -Wextra -O3 -I./include

## Compile ---------------------------------------------------------------

all:		title nm objdump

title:
		@$(ECHO) $(BLUE)$(NMNAME) AND $(DUMPNAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CFLAGS)" $(DEFAULT)


nm:		title $(NMOBJS)
		@$(CC) -o $(NMNAME) $(NMOBJS) && \
		 $(ECHO) $(GREEN) "[MY_NM COMPILED]" $(DEFAULT)

objdump:	title $(DUMPOBJS)
		@$(CC) -o $(DUMPNAME) $(DUMPOBJS) && \
		 $(ECHO) $(GREEN) "[MY_OBJDUMP COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(NMOBJS) && $(RM) $(DUMPOBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NMNAME) && $(RM) $(DUMPNAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
