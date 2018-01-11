/*
** cmd_broadcast.c for cmd_broadcast.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:24:31 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:25:34 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"
#include "common/utils/utils.h"

static const t_broadcast	g_tiles[9] =
  {
    {{0, 0}, 0},
    {{0, 1}, 1},
    {{1, 1}, 2},
    {{1, 0}, 3},
    {{1, -1}, 4},
    {{0, -1}, 5},
    {{-1, -1}, 6},
    {{-1, 0}, 7},
    {{-1, 1}, 8}
  };

static void	get_broadcast_vec(t_server *server, t_player *from,
				  t_player *to, int vec[2])
{
  vec[0] = to->pos_x - from->pos_x;
  vec[1] = to->pos_y - from->pos_y;
  if (ABS(vec[0]) > server->width / 2)
    vec[0] = ABS(vec[0]) != vec[0] ? server->width - ABS(vec[0]) :
      -(server->width - ABS(vec[0]));
  if (ABS(vec[1]) > server->height / 2)
    vec[1] = ABS(vec[1]) != vec[1] ? server->height - ABS(vec[1]) :
      -(server->height - ABS(vec[1]));
}

static int	get_broadcast_dir(t_player *this, int vec[2])
{
  float		slope;
  int		pos[2];
  int		i;

  pos[0] = 0;
  pos[1] = 0;
  slope = (float)(vec[1]) / (float)(vec[0]);
  if (slope >= -1 && slope <= 1 && pos[0] != vec[0])
    {
      pos[0] = vec[0] > 0 ? vec[0] - 1 : vec[0] + 1;
      pos[1] = pos[0] * slope;
    }
  else
    {
      pos[1] = vec[1] > 0 ? vec[1] - 1 : vec[1]  + 1;
      pos[0] = pos[1] * (1 / slope);
    }
  pos[0] = vec[0] - pos[0];
  pos[1] = vec[1] - pos[1];
  i = -1;
  while (++i < 9)
    if (pos[0] == g_tiles[i].pos[0] && pos[1] == g_tiles[i].pos[1])
      return ((g_tiles[i].num + (g_tiles[i].num != 0 ?
				 2 * this->direction : 0)) % 8);
  return (-1);
}

void		cmd_broadcast(t_server *server, char *arg, const int fd)
{
  t_player	*this;
  t_player	*index;
  int		vec[2];

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this)
    {
      dprintf(fd, "ko\n");
      return ;
    }
  index = server->players;
  while (index)
    {
      if (index->fd != fd)
	{
	  get_broadcast_vec(server, this, index, vec);
	  dprintf(index->fd, "message %d, %s\n", get_broadcast_dir(index, vec),
		  arg);
	}
      index = index->next;
    }
  cmd_pbc(server, this, arg);
  dprintf(fd, "ok\n");
}
