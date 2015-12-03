/*
** tekpixel.c for tekpixel in /home/uberti_l/rendu/xorshape_2020
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Dec  3 10:14:35 2015 louis-emile uberti-ares
** Last update Thu Dec  3 10:16:44 2015 louis-emile uberti-ares
*/

#include <lapin.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*my_putpixel;

  my_putpixel = (unsigned int *)pix->pixels;
  my_putpixel[pos->x + (pos->y * pix->clipable.clip_width)] = color;
}
