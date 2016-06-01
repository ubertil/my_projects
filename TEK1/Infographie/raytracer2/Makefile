##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
## Last update Sun May 22 18:02:02 2016 felix rahil
##

## Variables -------------------------------------------------------------

NAME		=	raytracer2

SRCS		=	srcs/main.c \
			srcs/free_all.c \
			srcs/free_all2.c \
			srcs/parse_args.c \
			srcs/get_normal.c \
			srcs/handle_user_options.c \
			srcs/print_help.c \
			srcs/z_buffer.c \
			srcs/norm_tab.c \
			srcs/intersect.c \
			srcs/phong_light.c \
			srcs/assemble_all_colors.c \
			srcs/subdive_triangles.c \
			srcs/dot.c \
			srcs/cross.c \
			srcs/vector.c \
			srcs/norm.c \
			srcs/move1.c \
			srcs/unused.c \
			srcs/obj/parse_obj_file.c \
			srcs/obj/add_obj_info.c \
			srcs/obj/add_obj_info2.c \
			srcs/obj/create_obj_tab.c \
			srcs/obj/reverse_obj_info.c \
			srcs/obj/get_coordinates_face.c \
			srcs/mtl/mtl_parse.c \
			srcs/mtl/add_new_material.c \
			srcs/mtl/add_mtl_info.c \
			srcs/threads/init_threads.c \
			tekfunc/tekpixel.c \
			tekfunc/set_background.c \
			tekfunc/tekpixel_alpha.c \
			tekfunc/tekray.c \
			tools/getnbr_from.c \
			tools/my_strdup.c \
			tools/my_strlen.c \
			tools/my_puterr.c \
			tools/my_putstr.c \
			tools/my_strcmp.c \
			tools/my_strcpy.c \
			tools/quick_match.c \
			tools/my_strncmp.c \
			tools/my_put_nbr.c \
			tools/my_getdouble.c \
			tools/get_shell_line.c \
			tools/is_separator.c \
			tools/my_str_to_wordtab.c \

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

CC		=	cc

LIB		=	-L/home/$(USER)/.froot/include \
			-L/home/$(USER)/.froot/lib \
			-llapin -lsfml-audio -lsfml-graphics -lsfml-window \
			-lsfml-system -lstdc++ -ldl -lm -lpthread

ERRLOG		=	errors~

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by Uberti_l , Grella_f and Rahil_f"

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
		 $(ECHO) $(GREEN) "[OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

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
