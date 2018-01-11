/*
** graphic_eht.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:13:26 2017 Nicolas Wadel
** Last update Thu Jun 29 12:13:28 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_eht(t_server *server, t_player *egg)
{
  t_player	*this;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  dprintf(this->fd, "eht #%d\n", egg->fd);
}
