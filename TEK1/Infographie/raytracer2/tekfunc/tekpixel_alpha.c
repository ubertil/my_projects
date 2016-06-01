/*
** tekpixel_alpha.c for tekpixel_alpha in /home/uberti_l/rendu/Infographie/gfx_colle_science_fiction
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon May 16 11:41:46 2016 louis-emile uberti-ares
** Last update Thu May 19 23:30:19 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

void		tekpixel_alpha(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       t_color color)
{
  t_color	*buffer;
  double	a;

  if (pos->x > -1 && pos->y > -1 && pos->x < pix->clipable.buffer.width &&
      pos->y < pix->clipable.buffer.height)
    {
      buffer = pix->pixels;
      a = color.argb[ALPHA_CMP] / 255.;
      buffer[POS].argb[RED_CMP] =
	buffer[POS].argb[RED_CMP] * (1 - a) + color.argb[RED_CMP] * a;
      buffer[POS].argb[GREEN_CMP] =
	buffer[POS].argb[GREEN_CMP] * (1 - a) + color.argb[GREEN_CMP] * a;
      buffer[POS].argb[BLUE_CMP] =
	buffer[POS].argb[BLUE_CMP] * (1 - a) + color.argb[BLUE_CMP] * a;
    }
}
