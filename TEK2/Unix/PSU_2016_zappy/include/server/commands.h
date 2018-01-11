/*
** commands.h for commands.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:04:33 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:00:41 2017 Nicolas TROGNOT
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_
# define NB_COMMANDS 12
# include "server.h"
# include "common/directions.h"
# include "common/incantation.h"

typedef struct		s_broadcast
{
  int			pos[2];
  int			num;
}			t_broadcast;

typedef struct		s_move
{
  enum e_direction	dir;
  int			move[2];
}			t_move;

typedef struct		s_commands_ptr
{
  char			*cmd;
  void			(*func)(t_server *server, char *arg, const int fd);
}			t_commands_ptr;

typedef struct		s_graphic_cmd
{
  char			*cmd;
  void			(*func)(t_server *server, char *arg, const int fd);
}			t_graphic_cmd;

extern const t_move	g_move[4];

void			cmd_forward(t_server *server, char *arg, const int fd);
void			cmd_right(t_server *server, char *arg, const int fd);
void			cmd_left(t_server *server, char *arg, const int fd);
void			cmd_look(t_server *server, char *arg, const int fd);
void			cmd_inventory(t_server *server, char *arg,
				      const int fd);
void			cmd_broadcast(t_server *server, char *arg,
				      const int fd);
void			cmd_connect_nbr(t_server *server, char *arg,
					const int fd);
void			cmd_fork(t_server *server, char *arg, const int fd);
void			cmd_eject(t_server *server, char *arg, const int fd);
void			cmd_take(t_server *server, char *arg, const int fd);
void			cmd_set(t_server *server, char *arg, const int fd);
void			cmd_incantation(t_server *server, char *arg,
					const int fd);
void			check_incantation(t_server *server, const int fd);
void			cmd_msz(t_server *server);
void			cmd_bct(t_server *server, const int pos_x,
				const int pos_y);
void			cmd_bct_all_map(t_server *server);
void			cmd_tna(t_server *server);
void			cmd_pnw(t_server *server, t_player *new);
void			cmd_ppo(t_server *server, t_player *player);
void			cmd_plv(t_server *server, t_player *player);
void			cmd_pin(t_server *server, t_player *player);
void			cmd_pex(t_server *server, t_player *player);
void			cmd_pbc(t_server *server, t_player *player,
				char *message);
void			cmd_pic(t_server *server, t_player *player);
void			cmd_pie(t_server *server, t_player *player);
void			cmd_pfk(t_server *server, t_player *player);
void			cmd_pdr(t_server *server, t_player *player,
				const enum e_item drop);
void			cmd_pgt(t_server *server, t_player *player,
				const enum e_item take);
void			cmd_pdi(t_server *server, t_player *player);
void			cmd_enw(t_server *server, t_player *egg, int fd);
void			cmd_eht(t_server *server, t_player *egg);
void			cmd_ebo(t_server *server, t_player *egg);
void			cmd_edi(t_server *server, t_player *egg);
void			cmd_sgt(t_server *server);
void			cmd_seg(t_server *server, char *winner);
void			graphic_take(t_server *server, t_player *player,
				     enum e_item resource);
void			graphic_drop(t_server *server, t_player *player,
				     enum e_item resource);

#endif /* !COMMANDS_H_ */
