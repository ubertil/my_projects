/*
** graphic_pin.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:12:27 2017 Nicolas Wadel
** Last update Thu Jun 29 12:12:28 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_pin(t_server *server, t_player *player)
{
  t_player	*this;
  int		i;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  i = -1;
  dprintf(this->fd, "pin #%d %d %d", player->fd, player->pos_x, player->pos_y);
  while (++i < NB_ITEM)
    dprintf(this->fd, " %d", player->inventory[i]);
  dprintf(this->fd, "\n");
}
