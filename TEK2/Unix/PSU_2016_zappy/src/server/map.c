/*
** map.c for map.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:19:53 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:42:17 2017 Nicolas TROGNOT
*/

#include <time.h>
#include <stdlib.h>
#include "server/server.h"

static const t_mineral	g_min_occur[] =
  {
    {{0, 24}, THYSTAME},
    {{25, 179}, PHIRAS},
    {{180, 309}, MENDIANE},
    {{310, 564}, SIBUR},
    {{565, 769}, DERAUMERE},
    {{770, 999}, LINEMATE},
  };

static enum e_item	get_mineral(int rand)
{
  int			value;
  int			i;

  value = rand % 1000;
  i = -1;
  while (++i < NB_ITEM - 1)
    if (value >= g_min_occur[i].odd[0] && value <= g_min_occur[i].odd[1])
      {
	value = g_min_occur[i].item;
	break ;
      }
  return (value);
}

static void	generate_material(t_server *server)
{
  int		nb_to_generate;
  int		actual;
  int		pos[2];

  srand(time(NULL));
  nb_to_generate = (int)((float)server->width * (float)server->height * 1.5);
  actual = -1;
  while (++actual < nb_to_generate)
    {
      pos[0] = rand() % server->width;
      pos[1] = rand() % server->height;
      server->map.cases[pos[1]][pos[0]].content[get_mineral(rand())] += 1;
    }
}

static void	generate_food(t_server *server)
{
  int		nb_to_generate;
  int		pos[2];
  int		actual;

  actual = -1;
  nb_to_generate = server->width * server->height;
  nb_to_generate /= 2;
  while (++actual < nb_to_generate)
    {
      pos[0] = rand() % server->width;
      pos[1] = rand() % server->height;
      server->map.cases[pos[1]][pos[0]].content[FOOD] += 1;
    }
}

static void	make_map_clean(t_server *server)
{
  int		pos[2];
  int		i;

  pos[1] = -1;
  while (++pos[1] < server->height)
    {
      pos[0] = -1;
      while (++pos[0] < server->width)
	{
	  i = -1;
	  while (++i < NB_ITEM)
	    server->map.cases[pos[1]][pos[0]].content[i] = 0;
	}
    }
}

int		build_map(t_server *server)
{
  int		height;

  if ((server->map.cases = malloc(sizeof(t_case *) * server->height)) == NULL)
    return (1);
  height = -1;
  while (++height < server->height)
    if ((server->map.cases[height] =
	 malloc(sizeof(t_case) * server->width)) == NULL)
      return (1);
  make_map_clean(server);
  generate_material(server);
  generate_food(server);
  return (0);
}
