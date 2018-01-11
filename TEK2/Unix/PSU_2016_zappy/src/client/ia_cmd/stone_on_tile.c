/*
** stone_on_tile.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 14:02:28 2017 Lous-Emile Uberti-Ares
** Last update Sun Jul  2 19:55:34 2017 grella_c
*/

#include <stdlib.h>
#include <string.h>
#include "client/client.h"
#include "client/ia.h"
#include "common/utils/utils.h"

static const char	*g_stones[NB_ITEM - 1] =
  {
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
  };

void		maybe_go_to_stone(t_client *client)
{
  if (client->ia->current != GO_TO_STONE)
    {
      client->ia->current = GO_TO_STONE;
      client->ia->func[client->ia->current](client, NULL);
    }
}

bool		stone_on_tile(t_client *client, const char *cmd)
{
  int		i;
  int		j;
  char		**args;
  char		**stones;

  i = -1;
  args = str_to_wordtab(cmd, "[,]");
  stones = str_to_wordtab((args != NULL) ? (args[0]) : (NULL), " \t");
  free_wordtab(args);
  while (stones != NULL && stones[++i] != NULL)
    {
      j = -1;
      while (++j < NB_ITEM - 1)
	if (strstr(stones[i], g_stones[j]))
	  {
	    client->ia->current = TAKE_STONE;
	    client->ia->func[client->ia->current](client, stones[i]);
	    free_wordtab(stones);
	    return (true);
	  }
    }
  free_wordtab(stones);
  maybe_go_to_stone(client);
  return (true);
}
