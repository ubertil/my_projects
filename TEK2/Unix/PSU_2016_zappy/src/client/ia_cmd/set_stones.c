#include <stdlib.h>
#include <string.h>
#include "client/ia.h"
#include "client/client.h"
#include "common/incantation.h"
#include "common/resources.h"
#include "common/utils/utils.h"

static const t_item		g_stones[NB_ITEM - 1] =
  {
    {LINEMATE, "linemate"},
    {DERAUMERE, "deraumere"},
    {SIBUR, "sibur"},
    {MENDIANE, "mendiane"},
    {PHIRAS, "phiras"},
    {THYSTAME, "thystame"}
  };

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

int		nb_stone_on_tile(const char *look_str, const char *stone)
{
  int		i;
  int		nb;
  char		**tiles;
  char		**items;

  i = -1;
  nb = 0;
  tiles = str_to_wordtab(look_str, "[,]");
  if (tab_len(tiles) < 1)
    {
      printf("PROBLEME\n");
      return (-1);
    }
  items = str_to_wordtab(tiles[0], " \t");
  free_wordtab(tiles);
  while (items != NULL && items[++i] != NULL)
    {
      if (strcmp(items[i], stone) == 0)
	++nb;
    }
  free_wordtab(items);
  return (nb);
}

void		adjust_nb_stones(t_client *client, int amount[NB_ITEM - 1])
{
  int		i;
  char		*input;

  i = 0;
  while (i < NB_ITEM - 1)
    {
      if (amount[i] == g_incantation[client->level - 1].amount[i])
	++i;
      else if (amount[i] > g_incantation[client->level - 1].amount[i])
	{
	  amount[i]--;
	  take_object(client, g_stones[i].item);
	  input = get_command(client, NULL);
	  if (input)
	    free(input);
	}
      else
	{
	  amount[i]++;
	  set_object(client, g_stones[i].item);
	  input = get_command(client, NULL);
	  if (input)
	    free(input);
	}
    }
}

bool		set_stones(t_client *client, UNUSED const char *cmd)
{
  char		*look_str;
  int		amount[NB_ITEM - 1];
  int		i;

  look_str = get_command(client, look);
  i = -1;
  while (++i < NB_ITEM - 1)
    amount[i] = nb_stone_on_tile(look_str, g_stones[i].item);
  free(look_str);
  adjust_nb_stones(client, amount);
  client->ia->current = INCANTATION;
  client->ia->func[client->ia->current](client, NULL);
  return (true);
}
