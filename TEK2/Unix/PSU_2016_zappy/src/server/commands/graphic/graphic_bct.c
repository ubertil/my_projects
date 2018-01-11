/*
** graphic_bct.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:13:17 2017 Nicolas Wadel
** Last update Thu Jun 29 12:13:18 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_bct(t_server *server, const int pos_x, const int pos_y)
{
  t_player	*this;
  int		i;

  i = -1;
  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  dprintf(this->fd, "bct %d %d", pos_x, pos_y);
  while (++i < NB_ITEM)
    dprintf(this->fd, " %d", server->map.cases[pos_y][pos_x].content[i]);
  dprintf(this->fd, "\n");
}
