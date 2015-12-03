/*
** tekcircle.c for tekcircle in /home/uberti_l/rendu/xorshape_2020
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Dec  3 10:22:13 2015 louis-emile uberti-ares
** Last update Thu Dec  3 11:25:19 2015 louis-emile uberti-ares
*/

#include <lapin.h>
#include "xorshape.h"

void			drawpix(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				unsigned int color)
{
  tekpixel(pix, &, color);
}

void			tekcircle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  double radius,
				  unsigned int color)
{
  double		d;
  t_bunny_position	current;

  d = radius - 1;
  current.x = pos->x;
  current.y = radius - pos->y;
  while (current.y >= current.x)
    {
      if (d >= (2 * current.x))
	{
	  d = d - (2 * current.x) + 1;
	  current.x = current.x + 1;
	}
      else if (d < 2 * (radius - current.y))
	{
	  d = d + (2 * current.y) - 1;
	  current.y = current.y - 1;
	}
      else
	{
	  d = d + 2 * (current.y - current.x - 1);
	  current.y = current.y - 1;
	  current.x = current.x + 1;
	}
    }
}
