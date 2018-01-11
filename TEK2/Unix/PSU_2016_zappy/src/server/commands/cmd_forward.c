/*
** cmd_forward.c for cmd_forward.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:27:08 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:27:13 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"

const t_move	g_move[4] =
  {
    {NORTH, {0, -1}},
    {EAST, {1, 0}},
    {SOUTH, {0, 1}},
    {WEST, {-1, 0}}
  };

void		cmd_forward(t_server *server,
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
  this->pos_x = (this->pos_x + g_move[this->direction].move[0])
    % server->width;
  this->pos_y = (this->pos_y + g_move[this->direction].move[1])
    % server->height;
  if (this->pos_x < 0)
    this->pos_x = server->width - 1;
  if (this->pos_y < 0)
    this->pos_y = server->height - 1;
  dprintf(fd, "ok\n");
  cmd_ppo(server, this);
}
