NAME	= explosion

SRCS	= flame.c \
	  tekpixel.c \
	  free_all.c \
	  set_background.c \
	  get_gradient.c \
	  tekgetpixel.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -rf

CC	= gcc

CFLAGS	= -W -Wall -Werror -ansi -pedantic -Wextra

LIB	= -L/home/$(USER)/.froot/lib -llapin

LAPIN	= -lsfml-audio -lsfml-graphics -lsfml-window \
	  -lsfml-system -lstdc++ -ldl -lm

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(CFLAGS) $(LIB) $(LAPIN)
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(LAPIN)

clean:
	$(RM) *~
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean clean all re
