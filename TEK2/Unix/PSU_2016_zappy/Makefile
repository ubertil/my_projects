##
## Makefile for Makefile in /home/uberti_l/source_files/lib/my
##
## Made by louis-emile uberti-ares
## Login   <uberti_l@epitech.net>
##
## Started on  Tue Dec 22 11:52:18 2015 louis-emile uberti-ares
##

## Variables -------------------------------------------------------------

CLIENT_NAME		=	zappy_ai
SERVER_NAME		=	zappy_server
GRAPHIC_NAME		=	zappy_graphic

CLIENT_SRCS		=	src/client/main.c					\
				src/common/utils/rot13.c				\
				src/common/utils/errors.c				\
				src/common/utils/is_nbr.c				\
				src/common/utils/str_to_wordtab.c			\
				src/common/utils/utils.c				\
				src/client/client.c					\
				src/client/signal.c					\
				src/client/client_loop.c				\
				src/client/move_cmd.c					\
				src/client/interaction_cmd.c				\
				src/client/action_cmd.c					\
				src/client/resources_cmd.c				\
				src/client/ia_cmd/graph.c				\
				src/client/ia_cmd/call_reinforcement.c			\
				src/client/ia_cmd/enough_food.c				\
				src/client/ia_cmd/food_on_tile.c			\
				src/client/ia_cmd/go_to_food.c				\
				src/client/ia_cmd/go_to_stone.c				\
				src/client/ia_cmd/go_to_teammate.c			\
				src/client/ia_cmd/incantation.c				\
				src/client/ia_cmd/nb_players.c				\
				src/client/ia_cmd/nb_stones.c				\
				src/client/ia_cmd/reached_destination.c			\
				src/client/ia_cmd/stone_on_tile.c			\
				src/client/ia_cmd/take_food.c				\
				src/client/ia_cmd/take_stone.c				\
				src/client/ia_cmd/team_msg.c				\
				src/client/ia_cmd/move_to.c				\
				src/client/ia_cmd/get_command.c				\
				src/client/ia_cmd/set_stones.c				\

SERVER_SRCS		=	src/server/main.c					\
				src/server/file.c					\
				src/server/map.c					\
				src/server/exec_client_commands.c			\
				src/server/release_inventory.c				\
				src/server/init_connection.c				\
				src/server/handle_connection.c				\
				src/common/utils/errors.c				\
				src/common/utils/str_to_wordtab.c			\
				src/common/utils/utils.c				\
				src/server/server.c					\
				src/server/player.c					\
				src/server/args/arg_p.c					\
				src/server/args/arg_x.c					\
				src/server/args/arg_y.c					\
				src/server/args/arg_n.c					\
				src/server/args/arg_c.c					\
				src/server/args/arg_f.c					\
				src/server/commands/cmd_broadcast.c			\
				src/server/commands/cmd_connect_nbr.c			\
				src/server/commands/cmd_eject.c				\
				src/server/commands/cmd_fork.c				\
				src/server/commands/cmd_forward.c			\
				src/server/commands/cmd_incantation.c			\
				src/server/commands/cmd_inventory.c			\
				src/server/commands/cmd_look.c				\
				src/server/commands/cmd_left.c				\
				src/server/commands/cmd_right.c				\
				src/server/commands/cmd_set.c				\
				src/server/commands/cmd_take.c				\
				src/server/exec_commands.c				\
				src/server/commands/graphic/graphic_bct_all_map.c	\
				src/server/commands/graphic/graphic_bct.c		\
				src/server/commands/graphic/graphic_drop.c		\
				src/server/commands/graphic/graphic_ebo.c		\
				src/server/commands/graphic/graphic_edi.c		\
				src/server/commands/graphic/graphic_eht.c		\
				src/server/commands/graphic/graphic_enw.c		\
				src/server/commands/graphic/graphic_msz.c		\
				src/server/commands/graphic/graphic_pbc.c		\
				src/server/commands/graphic/graphic_pdi.c		\
				src/server/commands/graphic/graphic_pdr.c		\
				src/server/commands/graphic/graphic_pex.c		\
				src/server/commands/graphic/graphic_pfk.c		\
				src/server/commands/graphic/graphic_pgt.c		\
				src/server/commands/graphic/graphic_pic.c		\
				src/server/commands/graphic/graphic_pie.c		\
				src/server/commands/graphic/graphic_pin.c		\
				src/server/commands/graphic/graphic_plv.c		\
				src/server/commands/graphic/graphic_pnw.c		\
				src/server/commands/graphic/graphic_ppo.c		\
				src/server/commands/graphic/graphic_seg.c		\
				src/server/commands/graphic/graphic_sgt.c		\
				src/server/commands/graphic/graphic_take.c		\
				src/server/commands/graphic/graphic_tna.c

GRAPHIC_SRCS		=	src/graphic/main.c					\
				src/graphic/core.c					\
				src/graphic/command_handler.c				\
				src/graphic/transaction.c				\
				src/graphic/client.c					\
				src/graphic/drawing.c					\
				src/graphic/event.c					\
				src/graphic/map.c					\
				src/graphic/player.c					\
				src/graphic/player_list.c				\
				src/graphic/teamname.c					\
				src/graphic/render_player.c				\
				src/graphic/stretch.c					\
				src/graphic/render_gui.c				\
				src/graphic/render_font.c				\
				src/graphic/info.c 					\
				src/graphic/font.c					\
				src/common/utils/utils.c				\
				src/common/utils/str_to_wordtab.c			\
				src/graphic/commands/msz.c				\
				src/graphic/commands/bct.c				\
				src/graphic/commands/pnw.c				\
				src/graphic/commands/ppo.c				\
				src/graphic/commands/tna.c				\
				src/graphic/commands/pdi.c				\
				src/graphic/commands/plv.c				\
				src/graphic/commands/pin.c				\
				src/graphic/commands/pgt.c

SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)
GRAPHIC_OBJS		=	$(GRAPHIC_SRCS:.c=.o)

RM		=	rm -f

CC		=	gcc

DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
BLUE            =       "\033[1;36m"
RED             =       "\033[0;31m"
YELLOW          =       "\033[01;33m"

ECHO            =       /bin/echo -e

CONTRIBUTORS	=	"by WTF Team"

CFLAGS		+=	-W -Wall -Werror -Wextra -I./include -D_GNU_SOURCE

## Compile ---------------------------------------------------------------

all:		title $(SERVER_NAME) $(CLIENT_NAME) $(GRAPHIC_NAME)

title:
		@$(ECHO) $(BLUE)$(NAME)
		@$(ECHO) $(RED)$(CONTRIBUTORS) $(DEFAULT)
		@$(ECHO) $(BLUE)"Compiled with" "$(CFLAGS)" $(DEFAULT)

$(CLIENT_NAME): $(CLIENT_OBJS)
		@$(CC) -o $(CLIENT_NAME) $(CLIENT_OBJS) && \
		 $(ECHO) $(GREEN) "["$(CLIENT_NAME)" COMPILED]" $(DEFAULT)

$(SERVER_NAME): $(SERVER_OBJS)
		@$(CC) -o $(SERVER_NAME) $(SERVER_OBJS) && \
		 $(ECHO) $(GREEN) "["$(SERVER_NAME)" COMPILED]" $(DEFAULT)

$(GRAPHIC_NAME): $(GRAPHIC_OBJS)
		 @$(CC) -o $(GRAPHIC_NAME) $(GRAPHIC_OBJS) -lSDL -lSDL_image -lSDL_ttf && \
		  $(ECHO) $(GREEN) "["$(GRAPHIC_NAME)" COMPILED]" $(DEFAULT)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[.o OK]" $(BLUE) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ERROR]" $(BLUE) $< $(DEFAULT)

## Cleaning ---------------------------------------------------------------

clean:
		 @$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(GRAPHIC_OBJS) && \
		  $(ECHO) $(GREEN) "[CLEAN SUCCESS]" $(DEFAULT)

fclean:		 clean
		 @$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(GRAPHIC_NAME) && \
		  $(ECHO) $(GREEN) "[FCLEAN SUCCESS]" $(DEFAULT)

## Tools -----------------------------------------------------------------

re:		 fclean all clean

.PHONY:		 fclean clean all re
