/*
** free_all2.c for free_all2 in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 13 17:51:54 2016 louis-emile uberti-ares
** Last update Fri May 20 14:20:34 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

void		free_norm(t_rtc *rtc)
{
  t_objinfo	*curr;

  while ((curr = rtc->norm) != NULL)
    {
      rtc->norm = rtc->norm->next;
      bunny_free(rtc->norm_tab[0]);
      bunny_free(curr);
    }
  bunny_free(rtc->norm_tab);
}

void		free_objtab(t_rtc *rtc)
{
  register int	i;

  i = -1;
  while (++i < rtc->nb_lines)
    bunny_free(rtc->obj[i]);
  bunny_free(rtc->obj);
}

void		free_triangles(t_triangles *old)
{
  t_triangles	*curr;

  while ((curr = old) != NULL)
    {
      old = old->next;
      if (curr->mat != NULL)
	bunny_free(curr->mat);
      bunny_free(curr->pos);
      bunny_free(curr->norm);
      bunny_free(curr->tex);
      bunny_free(curr);
    }
}
