/*
** release_inventory.c for release_inventory.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:20:15 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:20:20 2017 Nicolas TROGNOT
*/

#include "server/server.h"
#include "server/commands.h"
#include "common/resources.h"

void	release_inventory(t_server *server, t_player *player)
{
  int	i;

  i = -1;
  while (i++ < NB_ITEM)
    while (player->inventory[i] > (i == FOOD) ? 125 : 0)
      {
	++server->map.cases[player->pos_y][player->pos_x].content[i];
	player->inventory[i] -= (i == FOOD) ? 126 : 1;
	cmd_bct(server, player->pos_x, player->pos_y);
      }
}
