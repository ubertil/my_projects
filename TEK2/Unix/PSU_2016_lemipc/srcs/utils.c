/*
** utils.c for utils in /home/uberti_l/rendu/Unix/PSU_2016_lemipc
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Apr  1 21:17:07 2017 Lous-Emile Uberti-Ares
** Last update Sat Apr  1 21:18:38 2017 Lous-Emile Uberti-Ares
*/

#include "lemipc.h"

int		get_surroundings(const t_team *team, int *ennemy,
				 const int x, const int y)
{
  if ((x < 0 || x >= MAP_X) || (y < 0 || y >= MAP_Y))
    {
      *ennemy = -1;
      return (0);
    }
  else
    *ennemy = team->shared->map[y][x];
  return (1);
}

int		is_dead(const t_team *team)
{
  int		i;
  int		j;
  int		map[8];

  i = 0;
  if (team->status == ADMIN && team->live == DEAD)
    return (0);
  get_surroundings(team, &map[0], team->current_x - 1, team->current_y);
  get_surroundings(team, &map[1], team->current_x - 1, team->current_y - 1);
  get_surroundings(team, &map[2], team->current_x, team->current_y - 1);
  get_surroundings(team, &map[3], team->current_x + 1, team->current_y - 1);
  get_surroundings(team, &map[4], team->current_x + 1, team->current_y);
  get_surroundings(team, &map[5], team->current_x + 1, team->current_y + 1);
  get_surroundings(team, &map[6], team->current_x, team->current_y + 1);
  get_surroundings(team, &map[7], team->current_x - 1, team->current_y + 1);
  while (i < 8)
    {
      j = i + 1;
      while (j++ < 8)
	if (map[i] != -1 && map[j] != -1 && map[i] != team->team_number &&
	    map[j] != team->team_number && map[i] == map[j])
	  return (1);
      ++i;
    }
  return (0);
}
