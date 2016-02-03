##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Tue Feb  2 16:59:40 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME1		=	minitalk_server
NAME2		=	minitalk_client

SRCS1		=	server/main.c \
			tools/my_power_it.c \
			tools/my_putchar.c \
			tools/my_put_nbr.c \
			tools/my_putstr.c

SRCS2		=	client/main.c \
			client/ascii_to_binary.c \
			tools/my_getnbr.c \
			tools/my_power_it.c \
			tools/my_putchar.c \
			tools/my_putstr_err.c

OBJS1		=	$(SRCS1:.c=.o)
OBJS2		=	$(SRCS2:.c=.o)

RM		=	rm -f

CC		=	cc

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
ECHO		=	/bin/echo -e


CFLAGS		=	-W -Wall -Werror -Wextra -pedantic

## Compile ---------------------------------------------------------------

all:		title1 $(NAME1) title2 $(NAME2)

title1:
		@$(ECHO) $(BLUE)$(NAME1)$(GREEN) BY UBERTI_L$(DEFAULT)

title2:
		@$(ECHO) $(BLUE)$(NAME2)$(GREEN) BY UBERTI_L$(DEFAULT)

$(NAME1):	$(OBJS1)
		@$(CC) -o $(NAME1) $(OBJS1) && \
		 $(ECHO) $(GREEN) "[SUCCESS]" $(DEFAULT)
		@mv minitalk_server server/server

$(NAME2):	$(OBJS2)
		@$(CC) -o $(NAME2) $(OBJS2) && \
		 $(ECHO) $(GREEN) "[SUCCESS]" $(DEFAULT)
		@mv minitalk_client client/client

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) *~
		 @$(RM) tools/*~
		 @$(RM) client/*~
		 @$(RM) server/*~
		 @$(RM) $(OBJS1)
		 @$(RM) $(OBJS2) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) server/server
		 @$(RM) client/client && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)


## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
