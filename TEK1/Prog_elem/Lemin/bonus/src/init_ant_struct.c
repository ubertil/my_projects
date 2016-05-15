/*
** init_ant_struct for init_ant_struct.c in /home/grella_c/rendu/CPE_2015_Lemin/bonus
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Sat Apr 23 16:30:58 2016 come grellard
** Last update Sun Apr 24 15:01:27 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "visu.h"

t_bunny_position	find_start_pos(t_visu *visu)
{
  t_pos			*tmp;
  t_bunny_position	pos;

  tmp = visu->rooms;
  while (tmp->nb != 1)
    tmp = tmp->next;
  pos = tmp->posxy;
  return (pos);
}

int			init_ant_struct(t_visu *visu)
{
  t_bunny_position	start_pos;
  int			i;

  i = 0;
  start_pos = find_start_pos(visu);
  if ((visu->ants = malloc(sizeof(t_ants) * visu->nb_ants)) == NULL)
    return (-1);
  while (i < visu->nb_ants)
    {
      visu->ants[i].current = start_pos;
      visu->ants[i].dest = start_pos;
      visu->ants[i].idx = 0;
      if ((visu->ants[i].way = malloc(sizeof(t_bunny_position))) == NULL)
	return (-1);
      visu->ants[i].way[0] = visu->ants[i].dest;
      visu->ants[i].len = 1;
      i += 1;
    }
  return (0);
}
