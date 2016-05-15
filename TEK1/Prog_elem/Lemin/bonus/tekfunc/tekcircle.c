/*
** tekcircle.c for tekcircle in /home/uberti_l/source_files/lib/my/infographie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Feb  9 19:15:19 2016 louis-emile uberti-ares
** Last update Sun Apr 24 19:46:18 2016 nicolas wadel
*/

#include "visu.h"

void			drawcircle(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_bunny_position *tmp,
				   unsigned int col)
{
  t_bunny_position	new;

  new.x = pos->x + tmp->x;
  new.y = pos->y + tmp->y;
  tekpixel(pix, &new, col);
  new.y = pos->y - tmp->y;
  tekpixel(pix, &new, col);
  new.x = pos->x + tmp->y;
  new.y = pos->y + tmp->x;
  tekpixel(pix, &new, col);
  new.y = pos->y - tmp->x;
  tekpixel(pix, &new, col);
  new.x = pos->x - tmp->x;
  new.y = pos->y + tmp->y;
  tekpixel(pix, &new, col);
  new.y = pos->y - tmp->y;
  tekpixel(pix, &new, col);
  new.x = pos->x - tmp->y;
  new.y = pos->y + tmp->x;
  tekpixel(pix, &new, col);
  new.y = pos->y - tmp->x;
  tekpixel(pix, &new, col);
}


void			tekcircle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  double radius,
				  unsigned int color)
{
  t_bunny_position	current;
  int			d;

  current.x = 0;
  current.y = (unsigned int)radius;
  d = (unsigned int)radius - 1;
  while (current.y >= current.x)
    {
      drawcircle(pix, pos, &current, color);
      if (d >= 2 * current.x)
	d -= 2 * current.x++ + 1;
      else if (d < 2 * (radius - current.y))
	d += 2 * current.y-- - 1;
      else
	d += 2 * (current.y-- - current.x++ - 1);
    }
}
