##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Mon Apr 25 14:43:06 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	pamela.so

SRCS		=	src/main.c \
				src/clean_data.c \
				src/container_managment.c \

OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f

CC1			=	gcc
CC2			=	gcc -shared

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Louis-Emile UBERTI and Alexis PAPADIMITRIOU"

CFLAGS		+=	-I./include -fPIC

EXIST 		:=	$(shell command -v /lib/security/pamela.so 2> /dev/null)

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with $(CFLAGS)" $(DEFAULT)

check: 
		@$(ECHO) $(BLUE)"[+] Checking if $(NAME) is installed ..."
ifndef EXIST
	@$(ECHO) $(RED)"[*] $(NAME) is not installed on your system" $(DEFAULT)
	@$(ECHO) "Run 'make install' to install it"
else
	@$(ECHO) $(GREEN)"[*] $(NAME) is installed on your system" $(DEFAULT)
endif

install: 
		 @mkdir -p /lib/security
		 @cp $(NAME) /lib/security/
		 @$(ECHO) "auth	optional	/lib/security/pamela.so" >> /etc/pam.d/common-auth
		 @$(ECHO) "password	optional	/lib/security/pamela.so" >> /etc/pam.d/common-password
		 @$(ECHO) "session	optional	/lib/security/pamela.so" >> /etc/pam.d/common-session
		 @$(ECHO) "account	optional	/lib/security/pamela.so" >> /etc/pam.d/common-account
		 @$(ECHO) $(GREEN)"[+] $(NAME) successfully installed on your system" $(DEFAULT)


uninstall: 
		 @rm -f /lib/security/pamela.so
		 @sed -i '/auth	optional	\/lib\/security\/pamela.so/d' /etc/pam.d/common-auth
		 @sed -i '/password	optional	\/lib\/security\/pamela.so/d' /etc/pam.d/common-password
		 @sed -i '/session	optional	\/lib\/security\/pamela.so/d' /etc/pam.d/common-session
		 @sed -i '/account	optional	\/lib\/security\/pamela.so/d' /etc/pam.d/common-account
		 @$(ECHO) $(RED)"[-] $(NAME) successfully removed from your system" $(DEFAULT)

test:
	@$(ECHO) $(GREEN)"[+] Launching test suite ..." $(DEFAULT)
	@$(ECHO) "No test available"

$(NAME):	$(OBJS)
		@$(CC2) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN)"[$(NAME) COMPILED]" $(DEFAULT)

.c.o:
		@$(CC1) $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN)"[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED)"[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN)"[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN)"[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re check install uninstall test
