/*
** set_background.c for set_background in /home/uberti_l/rendu/gfx_incendie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Dec  4 23:14:55 2015 louis-emile uberti-ares
** Last update Sun May 15 14:23:55 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

void			set_background(t_bunny_pixelarray *pix,
				       unsigned int color)
{
  t_bunny_position	pos;
  t_color		background;

  pos.y = 0;
  pos.x = 0;
  background.full = color;
  while (pos.y < pix->clipable.buffer.height)
    {
      while (pos.x < pix->clipable.buffer.width)
	{
	  tekpixel(pix, &pos, background);
	  pos.x = pos.x + 1;
	}
      pos.x = 0;
      pos.y = pos.y + 1;
    }
}
