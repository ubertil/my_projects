/*
** cmd_connect_nbr.c for cmd_connect_nbr.c  in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:26:54 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:26:59 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include <string.h>
#include "server/server.h"
#include "server/commands.h"

void		cmd_connect_nbr(t_server *server,
				__attribute__((unused)) char *arg,
				const int fd)
{
  t_player	*this;
  t_player	*index;
  int		count;

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this)
    {
      dprintf(fd, "ko\n");
      return ;
    }
  index = server->players;
  count = 0;
  while (index)
    {
      if (this->team_name && index->team_name &&
	  !strcmp(this->team_name, index->team_name))
	++count;
      index = index->next;
    }
  dprintf(fd, "%d\n", server->client_nb - count);
}
