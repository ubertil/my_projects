/*
** graphic_enw.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:12:52 2017 Nicolas Wadel
** Last update Thu Jun 29 12:12:54 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_enw(t_server *server, t_player *egg, int fd)
{
  t_player	*this;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  dprintf(this->fd, "enw #%d #%d %d %d\n", egg->fd, fd, egg->pos_x,
	  egg->pos_y);
}
