/*
** server.h for server.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:06:40 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:06:47 2017 Nicolas TROGNOT
*/

#ifndef SERVER_H_
# define SERVER_H_
# include <time.h>
# include "common/resources.h"
# include "common/directions.h"
# include "server/map.h"
# include "server/player.h"
# include "server/connection.h"

typedef struct		s_name
{
  char			*name;
  struct s_name		*next;
}			t_name;

typedef struct		s_command_def
{
  char			*cmd;
  int			cost;
}			t_command_def;

typedef struct		s_server
{
  size_t		time;
  size_t		prev_time;
  int			port;
  int			width;
  int			height;
  t_name		*names;
  int			client_nb;
  int			freq;
  int			freq_used;
  clock_t		beg;
  t_map			map;
  t_player		*players;
  t_connection		conn;
}			t_server;

void			load_default_values(t_server *server);
int			init_server(t_server *server);
void			exec_command(t_server *server, t_player *player,
				     char *to_find, int cmd_idx);
void			free_server(t_server *server);
void			exec_clients_command(t_server *server);
void			release_inventory(t_server *server, t_player *player);

#endif /* !SERVER_H_ */
