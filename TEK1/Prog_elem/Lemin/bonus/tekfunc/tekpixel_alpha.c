/*
** tekpixel_alpha.c for tekpixel_alpha in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Apr 22 15:00:33 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:35:19 2016 louis-emile uberti-ares
*/

#include "visu.h"

void		tekpixel_alpha(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       t_color *color)
{
  t_color	*buffer;
  double	alpha;

  if (pos->x > -1 && pos->y > -1 && pos->x < pix->clipable.buffer.width &&
      pos->y < pix->clipable.buffer.height)
    {
      buffer = pix->pixels;
      alpha = color->argb[ALPHA_CMP] / 255.;
      buffer[POS].argb[RED_CMP] =
	buffer[POS].argb[RED_CMP] * (1 - alpha) +
	color->argb[RED_CMP] * alpha;
      buffer[POS].argb[GREEN_CMP] =
	buffer[POS].argb[GREEN_CMP] * (1 - alpha) +
	color->argb[GREEN_CMP] * alpha;
      buffer[POS].argb[BLUE_CMP] =
	buffer[POS].argb[BLUE_CMP] * (1 - alpha) +
	color->argb[BLUE_CMP] * alpha;
    }
}
