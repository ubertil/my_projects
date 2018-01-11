/*
** graphic_bct_all_map.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:13:08 2017 Nicolas Wadel
** Last update Sun Jul  2 19:27:56 2017 Nicolas TROGNOT
*/

#include "server/server.h"

void		cmd_bct_all_map(t_server *server)
{
  t_player	*this;
  int		pos[2];
  int		i;

  this = server->players;
  while (this && this->is_graphical == 0)
    this = this->next;
  if (!this)
    return ;
  pos[1] = -1;
  while (++pos[1] < server->height)
    {
      pos[0] = -1;
      while (++pos[0] < server->width)
	{
	  i = -1;
	  dprintf(this->fd, "bct %d %d", pos[0], pos[1]);
	  while (++i < NB_ITEM)
	    dprintf(this->fd, " %d",
		    server->map.cases[pos[1]][pos[0]].content[i]);
	  dprintf(this->fd, "\n");
	}
    }
}
