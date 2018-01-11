/*
** graphic_pie.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
**
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Thu Jun 29 12:13:51 2017 Nicolas Wadel
** Last update Sun Jul  2 18:54:12 2017 Nicolas TROGNOT
*/

#include "server/server.h"

void		cmd_pie(t_server *server, t_player *player)
{
  t_player	*this;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  dprintf(this->fd, "pie %d %d %d\n", player->pos_x, player->pos_y,
	  player->level);
}
