/*
** cmd_inventory.c for cmd_inventory.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:26:16 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:26:29 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"
#include "common/resources.h"

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

void		cmd_inventory(t_server *server,
			      __attribute__((unused)) char *arg,
			      const int fd)
{
  t_player	*this;
  int		i;

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this)
    {
      dprintf(fd, "ko\n");
      return ;
    }
  i = 0;
  dprintf(fd, "[");
  while (i < NB_ITEM)
    {
      if (i != 0)
	dprintf(fd, " ");
      dprintf(fd, "%s %d", g_item_tab[i].item, this->inventory[i]);
      ++i;
      if (i != NB_ITEM)
	dprintf(fd, ",");
    }
  dprintf(fd, "]\n");
}
