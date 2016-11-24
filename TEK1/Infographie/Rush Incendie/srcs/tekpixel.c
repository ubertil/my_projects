/*
** tekpixel.c for tekpixel in /home/uberti_l/rendu/gfx_incendie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Dec  4 23:15:08 2015 louis-emile uberti-ares
** Last update Fri Dec  4 23:15:10 2015 louis-emile uberti-ares
*/

#include "flame.h"
#include <lapin.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*my_putpixel;

  my_putpixel = (unsigned int *)pix->pixels;
  my_putpixel[pos->x + (pos->y * pix->clipable.clip_width)] = color;
}
