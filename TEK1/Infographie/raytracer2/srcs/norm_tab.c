/*
** norm_tab.c for norm_tab in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 13 15:09:12 2016 louis-emile uberti-ares
** Last update Fri May 20 14:26:52 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static int	norm_size(t_rtc *rtc)
{
  register int	size;
  t_objinfo	*norm;

  size = 0;
  norm = rtc->norm;
  while (norm)
    {
      ++size;
      norm = norm->next;
    }
  return (size);
}

int		norm_tab(t_rtc *rtc)
{
  register int	idx;
  t_objinfo	*norm;

  norm = rtc->norm;
  if ((rtc->norm_tab =
       bunny_malloc(sizeof(double *) * norm_size(rtc))) == NULL)
    return (-1);
  idx = 0;
  while (norm)
    {
      if ((rtc->norm_tab[idx] = bunny_malloc(sizeof(double) * 3)) == NULL)
	return (-1);
      rtc->norm_tab[idx][0] = norm->pos[0];
      rtc->norm_tab[idx][1] = norm->pos[1];
      rtc->norm_tab[idx][2] = norm->pos[2];
      ++idx;
      norm = norm->next;
    }
  return (get_all_triangles(rtc));
}
