/*
** create_obj_tab.c for create_obj_tab in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May  6 15:48:10 2016 louis-emile uberti-ares
** Last update Fri May 20 15:11:17 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static int	check_pos_idx(const int max, const double pos[3])
{
  if ((pos[0] > max) || (pos[1] > max) || (pos[2] > max))
    return (-1);
  return (0);
}

int		create_obj_tab(t_rtc *rtc)
{
  t_objinfo	*peak;
  register int	i;

  i = 0;
  rtc->peak = reverse_obj_info(rtc->peak);
  peak = rtc->peak;
  if ((rtc->obj =
       bunny_malloc(sizeof(double *) * (rtc->nb_lines + 1))) == NULL)
    return (my_puterr(MALLOC_ERR));
  while (peak)
    {
      if (((rtc->obj[i] = bunny_malloc(sizeof(double) * 3)) == NULL) ||
	  (check_pos_idx(rtc->nb_lines, peak->pos) == -1))
	return (-1);
      rtc->obj[i][0] = peak->pos[0];
      rtc->obj[i][1] = peak->pos[1];
      rtc->obj[i][2] = peak->pos[2];
      ++i;
      peak = peak->next;
    }
  free_objinfo(rtc->peak);
  rtc->peak = NULL;
  return (0);
}
