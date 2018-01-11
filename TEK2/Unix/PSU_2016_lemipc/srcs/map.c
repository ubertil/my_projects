/*
** map.c.c for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/map.c.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. mars 29 17:56:36 2017 Louis-Emile Uberti-Arès
** Last update Sat Apr  1 21:55:36 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "lemipc.h"

static inline int	find_duplicate(const t_team *team, const int to_find,
				       const int spotted_x,
				       const int spotted_y)
{
  int			x;
  int			y;

  y = -1;
  while (++y < MAP_Y)
    {
      x = -1;
      while (++x < MAP_X)
	if (team->shared->map[y][x] == to_find && x != spotted_x &&
	    y != spotted_y)
	  return (1);
    }
  return (0);
}

int		can_start(const t_team *team)
{
  int		x;
  int		y;
  int		f1;
  int		f2;

  y = -1;
  f1 = -1;
  f2 = -1;
  while (++y < MAP_Y)
    {
      x = -1;
      while (++x < MAP_X)
	{
	  if (team->shared->map[y][x] != -1 &&
	      find_duplicate(team, team->shared->map[y][x], x, y) == 1)
	    {
	      if (f1 == -1)
		f1 = team->shared->map[y][x];
	      else if (f1 != team->shared->map[y][x] && f2 == -1)
		f2 = team->shared->map[y][x];
	    }
	}
    }
  return ((f1 != -1 && f2 != -1) ? (1) : (0));
}

void		display_map(const t_team *team)
{
  int		x;
  int		y;

  y = -1;
  if (team->status == ADMIN)
    {
      usleep(SLEEP_FPS);
      dprintf(1, "\033c");
      while (++y < MAP_Y)
	{
	  x = -1;
	  while (++x < MAP_X)
	    {
	      if (team->shared->map[y][x] == -1)
		dprintf(1, MAP_PATTERN, PADDING, ' ');
	      else
		dprintf(1, "%d%*c", team->shared->map[y][x], PADDING, ' ');
	    }
	  putchar('\n');
	}
    }
}

void		place_randomly(t_team *team)
{
  int		placed;
  int		x;
  int		y;

  placed = 0;
  srand(time(NULL));
  while (placed == 0)
    {
      x = rand() % MAP_X;
      y = rand() % MAP_Y;
      if (team->shared->map[y][x] == -1)
	{
	  team->shared->map[y][x] = team->team_number;
	  team->current_y = y;
	  team->current_x = x;
	  placed = 1;
	}
    }
}

int		create_map(t_team *team)
{
  int		x;
  int		y;

  y = -1;
  while (++y < MAP_Y)
    {
      x = -1;
      while (++x < MAP_X)
	team->shared->map[y][x] = -1;
    }
  team->shared->nb_connected = 1;
  return (0);
}
