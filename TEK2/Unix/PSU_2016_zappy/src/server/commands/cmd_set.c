/*
** cmd_set.c for cmd_set.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:27:40 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:27:46 2017 Nicolas TROGNOT
*/

#include <string.h>
#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"

static const t_item	g_item_tab[NB_ITEM] =
  {
    {LINEMATE, "linemate"},
    {DERAUMERE, "deraumere"},
    {SIBUR, "sibur"},
    {MENDIANE, "mendiane"},
    {PHIRAS, "phiras"},
    {THYSTAME, "thystame"},
    {FOOD, "food"}
  };

void		cmd_set(t_server *server, char *arg, const int fd)
{
  t_player	*this;
  int		i;

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this || !arg)
    {
      dprintf(fd, "ko\n");
      return ;
    }
  i = -1;
  while (++i < NB_ITEM)
    if (strcmp(arg, g_item_tab[i].item) == 0 && this->inventory[i] > 0)
      {
	dprintf(fd, "ok\n");
	++server->map.cases[this->pos_y][this->pos_x].content[i];
	this->inventory[i] -= (enum e_item)i == FOOD ? 126 : 1;
	cmd_bct(server, this->pos_x, this->pos_y);
	break ;
      }
  if (this->inventory[FOOD] <= 0)
    close_connection(server, this->fd, this->elem_in_socket_array);
  if (i == NB_ITEM)
    dprintf(fd, "ko\n");
}
