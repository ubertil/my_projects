/*
** blit_alpha.c for blit_alpha in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Apr 22 15:07:26 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:34:32 2016 louis-emile uberti-ares
*/

#include "visu.h"

void			blit_alpha(t_bunny_pixelarray *dest,
				   t_bunny_pixelarray *src,
				   t_bunny_position *pos)
{
  t_bunny_position	p;
  t_bunny_position	final;
  t_color		c;

  p.y = src->clipable.clip_y_position;
  while (p.y < src->clipable.clip_height +
	 src->clipable.clip_y_position)
    {
      p.x = src->clipable.clip_x_position;
      while (p.x < src->clipable.clip_x_position +
	     src->clipable.clip_width)
	{
	  c = get_pixel(src, &p);
	  final.x = pos->x + p.x - src->clipable.clip_x_position;
	  final.y = pos->y + p.y - src->clipable.clip_y_position;
	  if (c.full != 0xFFFF00FF)
	    tekpixel_alpha(dest, &final, &c);
	  p.x += 1;
	}
      p.y += 1;
    }
}
