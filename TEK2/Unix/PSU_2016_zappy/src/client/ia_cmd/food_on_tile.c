/*
** food_on_tile.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:48:50 2017 Lous-Emile Uberti-Ares
** Last update Wed Jun 28 13:49:29 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include <string.h>
#include "client/client.h"
#include "client/ia.h"

bool		food_on_tile(t_client *client, const char *cmd)
{
  int		i;
  int		j;
  char		*to_find;

  i = 0;
  j = 0;
  to_find = strdup("food");
  while (cmd[++i] != '\0' && cmd[i] != ',')
    {
      if (cmd[i] == to_find[j])
	j++;
      if (to_find[j] == '\0')
	break;
    }
  if (to_find[j] == '\0')
    client->ia->current = TAKE_FOOD;
  else
    client->ia->current = GO_TO_FOOD;
  free(to_find);
  return (true);
}
