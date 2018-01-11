/*
** nb_stones.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:56:14 2017 Lous-Emile Uberti-Ares
** Last update Sun Jul  2 19:08:13 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include <string.h>
#include "client/client.h"
#include "client/ia.h"
#include "common/utils/utils.h"
#include "common/incantation.h"
#include "common/resources.h"

static const t_incantation	g_incantation[NB_INCANTATION] =
  {
    {1, {1, 0, 0, 0, 0, 0}},
    {2, {1, 1, 1, 0, 0, 0}},
    {2, {2, 0, 1, 0, 2, 0}},
    {4, {1, 1, 2, 0, 1, 0}},
    {4, {1, 2, 1, 3, 0, 0}},
    {6, {1, 2, 3, 0, 1, 0}},
    {6, {2, 2, 2, 2, 2, 1}},
  };

static bool	is_enough_items(const int level,
				const int inventory[NB_ITEM - 1])
{
  int		i;

  i = -1;
  while (++i < NB_ITEM - 1)
    if (g_incantation[level].amount[i] > inventory[i])
      return (false);
  return (true);
}

bool		nb_stones(t_client *client, const char *cmd)
{
  int		i;
  int		j;
  int		inventory[NB_ITEM - 1];
  char		**args;
  char		**stones;

  i = -1;
  j = -1;
  while (++i < NB_ITEM - 1)
    inventory[i] = 0;
  args = str_to_wordtab(cmd, "[]");
  stones = str_to_wordtab((args == NULL) ? (NULL) : (args[0]), " \t,");
  free_wordtab(args);
  i = 0;
  while (stones != NULL && stones[i] != NULL && strcmp(stones[i], "food") != 0)
    if (is_nbr(stones[i++]))
      inventory[++j] = atoi(stones[i - 1]);
  look(client);
  if (is_enough_items(client->level - 1, inventory))
    client->ia->current = NB_PLAYERS;
  else
    client->ia->current = STONE_ON_TILE;
  free_wordtab(stones);
  return (true);
}
