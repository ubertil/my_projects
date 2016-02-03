/*
** get_gradient.c for get_gradient in /home/uberti_l/rendu/gfx_incendie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Dec  4 23:17:11 2015 louis-emile uberti-ares
** Last update Sat Dec  5 06:25:45 2015 louis-emile uberti-ares
*/

#include <lapin.h>
#include "include/flame.h"

void			set_gradient(t_fire *fire)
{
  int			i;
  unsigned int		col;

  col = 0x000000;
  i = 0;
  while (i != 128)
    {
      fire->gradient[i] = col;
      if (i < 32)
	(col == 0xF8) ? (col += 0x000007) : (col += 0x000008);
      else if (i < 64)
	(col == 0xF8FF) ? (col += 0x000700) : (col += 0x000800);
      else
	(col = 0xF8FFFF) ? (col += 0x070000) : (col += 0x080000);
      fire->gradient[i] = col;
      i = i + 1;
    }
}
