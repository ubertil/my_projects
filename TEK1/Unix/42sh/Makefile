##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Jun  5 23:42:04 2016 alexis papadimitriou
##

## Variables -------------------------------------------------------------

NAME		=	42sh

SRCS		=	src/main.c \
			src/free_all.c \
			src/aff_prompt.c \
			src/tokens/tokens.c \
			src/signals.c \
			src/append_path.c \
			src/get_tab_env.c \
			src/alias.c \
			src/alias_command.c \
			src/lexer/init_tree.c \
			src/lexer/new_command.c \
			src/sanitize/error_check.c \
			src/sanitize/sanitize.c \
			src/sanitize/ambigious_checker.c \
			src/env/copy_env.c \
			src/env/free_env.c \
			src/env/my_unsetenv.c \
			src/env/my_setenv.c \
			src/env/my_env.c \
			src/env/my_getenv.c \
			src/env/get_env_variables.c \
			src/parser/init_parsing_tab.c \
			src/parser/do_execve.c \
			src/parser/open_token_fd.c \
			src/parser/special_token.c \
			src/parser/parser.c \
			src/parser/glob_wildcard.c \
			src/parser/find_globings.c \
			src/builtins/source_bashrc.c \
			src/builtins/builtins.c \
			src/builtins/my_echo.c \
			src/builtins/my_cd.c \
			src/builtins/my_exit.c \
			src/history/create_history_file.c \
			src/tools/my_concat.c \
			src/tools/get_shell_line.c \
			src/tools/my_getnbr.c \
			src/tools/my_str_to_wordtab.c \
			src/tools/is_separator.c \
			src/tools/args_size.c \
			src/tools/my_put_nbr.c \
			src/tools/my_putstr.c \
			src/tools/is_space.c \
			src/tools/match.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e
HISTORY		=	.42sh_history

CONTRIBUTORS	=	"by papadi_a, grella_c, rahil_f, uberti_l && trogno_n"

CFLAGS		+=	-W -Wall -Werror -Wextra -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CFLAGS)" $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) && \
		 $(ECHO) $(GREEN) "[BINARY COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(OBJS)
		 @$(RM) $(HISTORY) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
