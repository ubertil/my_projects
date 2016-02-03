/*
** tekgetpixel.c for tekgetpixel in /home/uberti_l/rendu/xorshape_2020
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Dec  3 10:18:06 2015 louis-emile uberti-ares
** Last update Sat Dec  5 01:19:55 2015 louis-emile uberti-ares
*/

#include <lapin.h>
#include "include/flame.h"

unsigned int	tekgetpixel(t_bunny_pixelarray *pix,
			    t_bunny_position *pos)
{
  unsigned int	*my_putpixel;

  my_putpixel = (unsigned int *)pix->pixels;
  return (my_putpixel[pos->x + (pos->y * pix->clipable.clip_width)]);
}
