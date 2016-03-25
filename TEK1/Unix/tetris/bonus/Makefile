##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Mar 20 23:41:05 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	tetris

SRCS		=	main.c \
			free_all.c \
			debug/print_help.c \
			debug/key_bindings.c \
			debug/get_options.c \
			debug/set_options.c \
			debug/debug_mode.c \
			debug/check_tetriminos.c \
			debug/draw_shape.c \
			debug/get_tetrimino.c \
			debug/setup_term.c \
			game/get_terminal_size.c \
			game/start_game.c \
			game/highscore.c \
			game/timer_handle.c \
			game/score_handle.c \
			game/add_shape_to_field.c \
			game/check_line_completed.c \
			game/check_move.c \
			game/check_put_shape.c \
			game/check_rotation.c \
			game/get_shape.c \
			game/move.c \
			game/play_tetris.c \
			game/prompt_game.c \
			game/which_tetrimino.c \
			prompt/prompt_next_tetrimino.c \
			prompt/next_box_size.c \
			prompt/escape_game.c \
			prompt/pause_screen.c \
			prompt/print_hud_tetris.c \
			prompt/game_over.c \
			music/music.c \
			tools/my_putchar.c \
			tools/my_putstr.c \
			tools/my_putstr_err.c \
			tools/my_put_nbr.c \
			tools/my_strlen.c \
			tools/my_strdup.c \
			tools/getnbr_from.c \
			tools/my_getnbr.c \
			tools/my_strcpy.c \
			tools/my_dupkey.c \
			tools/my_strcmp.c \
			tools/my_strncmp.c \
			tools/unstrict_cmp.c \
			tools/isnbr_from.c \
			tools/get_shell_line.c \
			tools/my_str_to_wordtab.c \
			tools/quick_match.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	cc

LIB		=	-lncurses \
			-L/home/$(USER)/.froot/lib \
			-L/home/$(USER)/.froot/include \
			-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
			-lsfml-system -lstdc++ -ldl -lm

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"


ECHO            =       /bin/echo -e

LINE1           =       "_____ _____ _____ ____  ___ ____ \n"
LINE2           =       "|_   _| ____|_   _|  _ \|_ _/ ___|\n"
LINE3           =       "  | | |  _|   | | | |_) || |\___ \\n"
LINE4           =       "  | | | |___  | | |  _ < | | ___) |\n"
LINE5           =       "  |_| |_____| |_| |_| \_|___|____/\n"

CFLAGS		=	-W -Wall -Werror -Wextra

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME) $(RED) BY UBERTI_L WADEL_N $(DEFAULT)
		@$(ECHO) $(GREEN)$(LINE1)$(LINE2)$(LINE3)$(LINE4)$(LINE5) \
		 $(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LIB) && \
		 $(ECHO) $(GREEN) "[SUCCESS]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) *~
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
