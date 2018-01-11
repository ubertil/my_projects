/*
** graphic_tna.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:11:45 2017 Nicolas Wadel
** Last update Thu Jun 29 12:11:46 2017 Nicolas Wadel
*/

#include "server/server.h"

void		cmd_tna(t_server *server)
{
  t_player	*this;
  t_name	*index;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  index = server->names;
  while (index)
    {
      if (index->name)
	dprintf(this->fd, "tna %s\n", index->name);
      index = index->next;
    }
}
