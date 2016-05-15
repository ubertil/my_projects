/*
** get_color.c for get_color in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Apr 22 15:16:32 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:34:24 2016 louis-emile uberti-ares
*/

#include "visu.h"

t_color			get_pixel(t_bunny_pixelarray *pix,
				  t_bunny_position *pos)
{
  t_color		*buffer;

  buffer = pix->pixels;
  return (buffer[POS]);
}
