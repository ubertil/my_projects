/*
** player.h for player.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:06:26 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:06:33 2017 Nicolas TROGNOT
*/

#ifndef PLAYER_H_
# define PLAYER_H_
# include <stdio.h>
# include "common/resources.h"
# include "common/directions.h"

typedef struct		s_server t_server;

typedef struct		s_command
{
  char			*cmd;
  int			cost;
  size_t		beg;
}			t_command;

typedef struct		s_player
{
  int			*elem_in_socket_array;
  enum e_direction	direction;
  int			pos_x;
  int			pos_y;
  int			fd;
  FILE			*file;
  int			level;
  int			inventory[NB_ITEM];
  int			command_idx;
  t_command		commands[10];
  char			*team_name;
  char			is_graphical;
  char			is_egg;
  char			is_incanting;
  struct s_player	*next;
}			t_player;

char			add_player(t_server *server, int fd);
char			confirm_player(t_server *server, char *team_name,
				       int fd);

#endif /* !PLAYER_H_ */
