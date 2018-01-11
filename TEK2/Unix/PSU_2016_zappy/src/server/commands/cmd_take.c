/*
** cmd_take.c for cmd_take.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:29:06 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:29:14 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include <string.h>
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

static void	add_food_random(t_server *server)
{
  int		pos[2];

  pos[0] = rand() % server->width;
  pos[1] = rand() % server->height;
  server->map.cases[pos[1]][pos[0]].content[FOOD] += 1;
  cmd_bct(server, pos[0], pos[1]);
}

void		cmd_take(t_server *server, char *arg, const int fd)
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
    if (strcmp(arg, g_item_tab[i].item) == 0 &&
	server->map.cases[this->pos_y][this->pos_x].content[i] > 0)
      {
	dprintf(fd, "ok\n");
	--server->map.cases[this->pos_y][this->pos_x].content[i];
	(g_item_tab[i].index == FOOD) ? this->inventory[i] += 125,
	  add_food_random(server) : 0;
	++this->inventory[i];
	break ;
      }
  (i == NB_ITEM) ? dprintf(fd, "ko\n") :
    graphic_take(server, this, g_item_tab[i].index);
}
