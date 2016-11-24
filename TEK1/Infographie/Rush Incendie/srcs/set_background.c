/*
** set_background.c for set_background in /home/uberti_l/rendu/gfx_incendie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Dec  4 23:14:55 2015 louis-emile uberti-ares
** Last update Sat Dec  5 14:27:27 2015 louis-emile uberti-ares
*/

#include <lapin.h>
#include "flame.h"

void			set_background(t_bunny_pixelarray *pix,
				       unsigned int color)
{
  t_bunny_position	pos;

  pos.y = 0;
  pos.x = 0;
  while (pos.y != pix->clipable.buffer.height)
    {
      while (pos.x != pix->clipable.buffer.width)
	{
	  tekpixel(pix, &pos, color);
	  pos.x = pos.x + 1;
	}
      pos.x = 0;
      pos.y = pos.y + 1;
    }
}
