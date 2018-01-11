/*
** graphic_pnw.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:12:09 2017 Nicolas Wadel
** Last update Thu Jun 29 12:12:10 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_pnw(t_server *server, t_player *new)
{
  t_player	*this;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  dprintf(this->fd, "pnw #%d %d %d %d %d %s\n", new->fd, new->pos_x,
	  new->pos_y, new->direction, new->level, new->team_name);
}
