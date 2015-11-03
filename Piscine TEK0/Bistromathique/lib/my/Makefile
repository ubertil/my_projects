##
## Makefile for Makefile in /home/uberti_l/rendu/Piscine_C_J10
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Fri Oct  9 09:44:11 2015 louis-emile uberti-ares
## Last update Sat Oct 31 17:48:51 2015 louis-emile uberti-ares
##

SRC	= my_aff_params.c \
	  my_find_prime_sup.c \
	  my_getnbr.c \
	  my_isneg.c \
	  my_is_prime.c \
	  my_power_rec.c \
	  my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_rev_params.c \
	  my_revstr.c \
	  my_showmem.c \
	  my_showstr.c \
	  my_show_wordtab.c \
	  my_sort_int_tab.c \
	  my_square_root.c \
	  my_strcapitalize.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_strdup.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_strlcat.c \
	  my_strlen.c \
	  my_strlowcase.c \
	  my_strncat.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_strupcase.c \
	  my_swap.c \
	  sum_params.c \

NAME	= libmy.a

RM	= rm -rf

CC	= cc -c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 ar rc $(NAME) $(OBJ)
	 ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean clean all

.PHONY = all clean fclean re
