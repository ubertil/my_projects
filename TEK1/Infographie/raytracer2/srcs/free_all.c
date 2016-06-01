/*
** free_all.c for free_all in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May  5 19:09:41 2016 louis-emile uberti-ares
** Last update Fri May 20 14:21:19 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static void	free_mat(t_materials *old)
{
  t_materials	*curr;

  while ((curr = old) != NULL)
    {
      old = old->next;
      bunny_free(curr->name);
      bunny_free(curr);
    }
}

void		free_faces(t_faces *old)
{
  t_faces	*curr;
  int		i;

  while ((curr = old) != NULL)
    {
      i = -1;
      old = old->next;
      if (curr->mat != NULL)
	bunny_free(curr->mat);
      while (++i < curr->nb)
	bunny_free(curr->pos[i]);
      bunny_free(curr);
    }
}

void		free_objinfo(t_objinfo *old)
{
  t_objinfo	*curr;

  while ((curr = old) != NULL)
    {
      old = old->next;
      bunny_free(curr);
    }
}

void		free_all(t_rtc *rtc)
{
  free_mat(rtc->mat);
  bunny_free(rtc->scene_file);
  bunny_free(rtc);
}

int		free_tab(char **tab)
{
  register int	i;

  i = 0;
  while (tab[i] != NULL)
    bunny_free(tab[i++]);
  bunny_free(tab);
  return (0);
}
