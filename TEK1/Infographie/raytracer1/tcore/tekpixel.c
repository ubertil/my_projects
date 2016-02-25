/*
** tekpixel.c for tekpixel.c in /home/uberti_l/rendu/gfx_fdf2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 10 10:09:19 2015 louis-emile uberti-ares
** Last update Sun Dec 20 17:49:03 2015 louis-emile uberti-ares
*/

#include <lapin.h>

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  unsigned int		*my_putpixel;

  my_putpixel = (unsigned int *)pix->pixels;
  my_putpixel[pos->x + (pos->y * pix->clipable.clip_width)] = color->full;
}
