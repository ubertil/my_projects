/*
** graphic_pic.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:12:32 2017 Nicolas Wadel
** Last update Thu Jun 29 12:12:33 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_pic(t_server *server, t_player *player)
{
  t_player	*this;
  t_player	*index;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  dprintf(this->fd, "pic %d %d %d #%d", player->pos_x, player->pos_y,
	  player->level, player->fd);
  index = server->players;
  while (index)
    {
      if (index->pos_x == player->pos_x && index->pos_y == player->pos_y &&
	  player->level == index->level && index->fd != player->fd)
	dprintf(this->fd, " #%d", index->fd);
      index = index->next;
    }
  dprintf(this->fd, "\n");
}
