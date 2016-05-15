##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun Apr 24 13:05:38 2016 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

NAME		=	visu

SRCS		=	src/main.c \
			src/free_all.c \
			src/check_args.c \
			src/check_room.c \
			src/recup_rooms.c \
			src/create_link.c \
			src/get_rooms_link.c \
			src/get_nbr_ants.c \
			src/show_all_rooms.c \
			src/move_all_ants.c \
			src/find_room.c \
			src/load_ant.c \
			src/load_screen.c \
			src/music.c \
			src/show_all_links.c \
			src/get_all_moves.c \
			src/init_ant_struct.c \
			src/get_ant_positions.c \
			src/make_ants_move.c \
			tekfunc/tekpixel.c \
			tekfunc/tekline.c \
			tekfunc/tekcircle.c \
			tekfunc/tekpixel_alpha.c \
			tekfunc/blit_alpha.c \
			tekfunc/get_color.c \
			tekfunc/set_background.c \
			tools/my_strdup.c \
			tools/my_strlen.c \
			tools/get_next_line.c \
			tools/my_str_to_wordtab.c \
			tools/my_hard_getnbr.c \
			tools/my_strcmp.c \
			tools/my_getnbr.c \
			tools/my_putstr.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	cc

LIB		=	-L/home/$(USER)/.froot/include \
			-L/home/$(USER)/.froot/lib \
			-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
			-lsfml-system -lstdc++ -ldl -lm

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Grella_c, Wadel_n, Trogno_n and Uberti_l"

CFLAGS		+=	-W -Wall -Werror -I./include

## Compile ---------------------------------------------------------------

all:		title $(NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CFLAGS)"$(DEFAULT)


$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LIB) && \
		 $(ECHO) $(GREEN) "[BINARY COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(LIB) $(CFLAGS) -c $< -o $@ 2>> $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[.o ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(ERRLOG)
		 @$(RM) $(OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
