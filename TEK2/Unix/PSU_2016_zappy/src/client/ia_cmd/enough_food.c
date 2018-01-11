/*
** enough_food.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:47:25 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 14:21:12 2017 Lous-Emile Uberti-Ares
*/

#include <string.h>
#include <stdlib.h>
#include "client/client.h"
#include "client/ia.h"
#include "common/utils/utils.h"

bool		enough_food(t_client *client, UNUSED const char *cmd)
{
  int		nb_food;
  int		i;
  char		**tab;
  char		*input;

  input = get_command(client, get_inventory);
  if ((tab = str_to_wordtab(input, " ,")) == NULL)
    return (false);
  if (input)
    free(input);
  i = 0;
  while (tab[i] != NULL && strcmp(tab[i], "food") != 0)
    i++;
  nb_food = atoi(tab[i + 1]);
  free_wordtab(tab);
  if (nb_food < MIN_FOOD)
    client->ia->current = FOOD_ON_TILE;
  else
    client->ia->current = TEAM_MSG;
  return (client->ia->func[client->ia->current](client, NULL));
}
