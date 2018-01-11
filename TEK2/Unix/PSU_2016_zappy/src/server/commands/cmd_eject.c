/*
** cmd_eject.c for cmd_eject.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:27:58 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:28:09 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"

void		cmd_eject(t_server *server,
			  __attribute__((unused)) char *arg,
			  const int fd)
{
  t_player	*index;
  t_player	*this;
  int		i;

  i = 0;
  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  index = server->players;
  cmd_pex(server, this);
  while (index)
    {
      if (index->pos_x == this->pos_x && index->pos_y == this->pos_y
	  && index->fd != fd)
	{
	  index->pos_x += g_move[this->direction].move[0];
	  index->pos_y += g_move[this->direction].move[1];
	  dprintf(index->fd, "eject: %d\n", (((index->direction - 2 + 4) % 4)
					     * 2 + 1) % 8);
	  cmd_ppo(server, index);
	  ++i;
	}
      index = index->next;
    }
  (i != 0) ? dprintf(fd, "ko\n") : dprintf(fd, "ok\n");
}
