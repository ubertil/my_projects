##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Fri May 27 17:19:17 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME1		=	tournoi/solver
NAME2		=	largeur/solver
NAME3		=	profondeur/solver
NAME4		=	astar/solver
NAME5		=	generateur/generateur

TOOLS		=	tools/my_putstr.c \
			tools/my_strlen.c \
			tools/my_getnbr.c \
			tools/my_str_to_wordtab.c

SRCS1		=	tournoi/tournoi.c \
			tournoi/maze_checker.c \
			tournoi/struct_handler.c \
			tournoi/solver.c \
			tournoi/free_all.c \
			tournoi/display_maze.c \
			tournoi/fill_result.c \
			tournoi/best_node.c \
			tournoi/utils.c \
			tournoi/list_handler.c \
			tournoi/get_cost.c \
			tournoi/get_cost_bis.c \
			$(TOOLS)

SRCS2		=	largeur/largeur.c \
			largeur/maze_checker.c \
			largeur/free_all.c \
			largeur/struct_handler.c \
			largeur/solver.c \
			largeur/display_maze.c \
			largeur/compare.c \
			largeur/utils.c \
			$(TOOLS)

SRCS3		=	profondeur/profondeur.c \
			profondeur/maze_checker.c \
			profondeur/struct_handler.c \
			profondeur/solver.c \
			profondeur/free_all.c \
			profondeur/display_maze.c \
			$(TOOLS)

SRCS4		=	astar/astar.c \
			astar/free_all.c \
			astar/maze_checker.c \
			astar/struct_handler.c \
			astar/solver.c \
			astar/display_maze.c \
			astar/fill_result.c \
			astar/best_node.c \
			astar/utils.c \
			astar/list_handler.c \
			astar/get_cost.c \
			astar/get_cost_bis.c \
			$(TOOLS)

SRCS5		=	generateur/srcs/generateur.c \
			generateur/srcs/free_all.c \
			generateur/srcs/struct_handler.c \
			generateur/srcs/display_maze.c \
			generateur/srcs/protected.c \
			generateur/srcs/fill.c \
			generateur/srcs/check_args.c \
			$(TOOLS)

OBJS1		=	$(SRCS1:.c=.o)
OBJS2		=	$(SRCS2:.c=.o)
OBJS3		=	$(SRCS3:.c=.o)
OBJS4		=	$(SRCS4:.c=.o)
OBJS5		=	$(SRCS5:.c=.o)

RM		=	rm -f

CC		=	cc

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by TROGNO_N and UBERTI_L"

CFLAGS		+=	-W -Wall -Werror -Wextra -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

title:
		@$(ECHO) $(RED)"L'Etoile de Dante"$(DEFAULT)
		@$(ECHO) $(BLUE)"$(CONTRIBUTORS)"
		@$(ECHO) "Compiled with" "$(CFLAGS)" $(DEFAULT)


$(NAME1):	$(OBJS1)
		@$(CC) -o $(NAME1) $(OBJS1) && \
		 $(ECHO) $(GREEN) "[TOURNOI COMPILED]" $(DEFAULT)


$(NAME2):	$(OBJS2)
		@$(CC) -o $(NAME2) $(OBJS2) && \
		 $(ECHO) $(GREEN) "[LARGEUR COMPILED]" $(DEFAULT)

$(NAME3):	$(OBJS3)
		@$(CC) -o $(NAME3) $(OBJS3) && \
		 $(ECHO) $(GREEN) "[PROFONDEUR COMPILED]" $(DEFAULT)

$(NAME4):	$(OBJS4)
		@$(CC) -o $(NAME4) $(OBJS4) && \
		 $(ECHO) $(GREEN) "[ASTAR COMPILED]" $(DEFAULT)

$(NAME5):	$(OBJS5)
		@$(CC) -o $(NAME5) $(OBJS5) && \
		 $(ECHO) $(GREEN) "[GENERATEUR COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) $(OBJS1)
		 @$(RM) $(OBJS2)
		 @$(RM) $(OBJS3)
		 @$(RM) $(OBJS4)
		 @$(RM) $(OBJS5) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME1)
		 @$(RM) $(NAME2)
		 @$(RM) $(NAME3)
		 @$(RM) $(NAME4)
		 @$(RM) $(NAME5) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
