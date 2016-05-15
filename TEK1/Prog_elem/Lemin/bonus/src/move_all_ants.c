/*
** move_all_ants.c for move_all_ants in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 21 21:41:29 2016 louis-emile uberti-ares
** Last update Sun Apr 24 15:08:23 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "visu.h"

int			realloc_way(t_visu *visu, int i)
{
  t_bunny_position	*tmp;
  int			idx;

  idx = 0;
  if ((tmp = malloc(sizeof(t_bunny_position) *
		    (visu->ants[i].len + 1))) == NULL)
    return (-1);
  while (idx < visu->ants[i].len)
    {
      tmp[idx] = visu->ants[i].way[idx];
      idx += 1;
    }
  visu->ants[i].way = tmp;
  visu->ants[i].len += 1;
  return (0);
}

int			move_2(t_visu *visu, double pente,
			       t_bunny_position *pos, int i)
{
  t_bunny_position	current;

  current = pos[0];
  while (current.y != pos[1].y)
    {
      (pos[1].y > pos[0].y) ? (current.y += 1) : (current.y -= 1);
      current.x = pos[0].x + ((current.y - pos[0].y) * (1 / pente));
      visu->ants[i].way[visu->ants[i].idx].x = current.x - 40;
      visu->ants[i].way[visu->ants[i].idx].y = current.y - 45;
      visu->ants[i].idx += 1;
      if (realloc_way(visu, i) == -1)
	return (-1);
    }
  return (0);
}

int			move_1(t_visu *visu, double pente,
			       t_bunny_position *pos, int i)
{
  t_bunny_position	current;

  current = pos[0];
  while (current.x != pos[1].x)
    {
      (pos[1].x > pos[0].x) ? (current.x += 1) : (current.x -= 1);
      current.y = pos[0].y + ((current.x - pos[0].x) * pente);
      visu->ants[i].way[visu->ants[i].idx].x = current.x - 40;
      visu->ants[i].way[visu->ants[i].idx].y = current.y - 45;
      visu->ants[i].idx += 1;
      if (realloc_way(visu, i) == -1)
	return (-1);
    }
  return (0);
}

int			tekant(t_visu *visu, t_bunny_position *pos, int i)
{
  float			pente;

  pente = get_pente(pos);
  if ((pente >= -1) && (pente <= 1))
    {
      if (move_1(visu, pente, pos, i) == -1)
	return (-1);
    }
  else
    if (move_2(visu, pente, pos, i) == -1)
      return (-1);
  return (0);
}

int			move_all_ants(t_visu *visu)
{
  char			*line;
  char			**tab;
  int			i;

  i = 0;
  if (visu->mem != NULL)
    {
      line = my_strdup(visu->mem);
      visu->mem = NULL;
    }
  else if ((line = get_next_line(0)) == NULL)
    return (-1);
  if ((tab = my_str_to_wordtab(line)) == NULL)
    return (-1);
  free(line);
  while (tab[i] != NULL)
    if (get_ant_positions(visu, tab[i++]) == -1)
      {
	free_args(tab);
	return (-1);
      }
  free_args(tab);
  make_ants_move(visu);
  return (0);
}
