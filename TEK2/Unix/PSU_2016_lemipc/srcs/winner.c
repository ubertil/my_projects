/*
** winner.c for winner in /home/uberti_l/rendu/Unix/PSU_2016_lemipc
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Apr  1 15:05:01 2017 Lous-Emile Uberti-Ares
** Last update Sat Apr  1 16:41:19 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include "lemipc.h"

int		winner(const t_team *team)
{
  int		x;
  int		y;
  int		found;

  y = -1;
  found = -1;
  while (++y < MAP_Y)
    {
      x = -1;
      while (++x < MAP_X)
	{
	  if (team->shared->map[y][x] != -1)
	    {
	      if (found == -1)
		found = team->shared->map[y][x];
	      else if (found != -1 && team->shared->map[y][x] != found)
		return (0);
	    }
	}
    }
  if (team->status == ADMIN)
    dprintf(1, WINNER, found);
  return (1);
}
