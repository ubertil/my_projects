/*
** graphic_pdr.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:12:43 2017 Nicolas Wadel
** Last update Thu Jun 29 12:12:45 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_pdr(t_server *server, t_player *player,
			const enum e_item drop)
{
  t_player	*this;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  dprintf(this->fd, "pdr #%d %d\n", player->fd, drop);
}
