/*
** cmd_right.c for cmd_right.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:26:37 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:26:43 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"

void		cmd_right(t_server *server,
			  __attribute__((unused)) char *arg,
			  const int fd)
{
  t_player	*this;

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this)
    {
      dprintf(fd, "ko\n");
      return ;
    }
  ++this->direction;
  this->direction %= 4;
  dprintf(fd, "ok\n");
  cmd_ppo(server, this);
}
