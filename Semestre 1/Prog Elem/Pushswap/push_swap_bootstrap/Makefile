NAME		=	pimp-my-algo

CC		=	gcc
RM		=	rm -rf

SRC		=	sort_numbers.c

OBJ		=	$(SRC:.c=.o)
OBJ		+=	graphic_push_swap.o		\
			push_swap_bootstrap.o

LD_FLAGS	+=	-lSDL -lSDL_ttf
CFLAGS		+=	-Wall -Wextra

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LD_FLAGS)

all:		$(NAME)

clean:
	$(RM) sort_numbers.o

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
