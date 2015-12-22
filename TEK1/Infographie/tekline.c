/*
** tekline.c for tekline in /home/uberti_l/rendu/gfx_fdf1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 17 11:19:50 2015 louis-emile uberti-ares
** Last update Tue Dec 22 12:44:17 2015 louis-emile uberti-ares
*/

#include <lapin.h>
float			get_pente(t_bunny_position *pos)
{
  float			pente;

  pente = (float)(pos[1].y - pos[0].y);
  pente = (float)(pente / (pos[1].x - pos[0].x));
  return (pente);
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color)
{
  t_bunny_position	current;
  float			pente;

  current.x = pos[0].x;
  current.y = pos[0].y;
  pente = get_pente(pos);
  if ((pente >= -1) && (pente <= 1))
    while (current.x != pos[1].x)
      {
	(pos[1].x > pos[0].x) ? (current.x += 1) : (current.x -= 1);
	current.y = pos[0].y + ((current.x - pos[0].x) * pente);
	tekpixel(pix, &current, color);
      }
  else
    {
      while (current.y != pos[1].y)
	{
	  (pos[1].y > pos[0].y) ? (current.y += 1) : (current.y -= 1);
	  current.x = pos[0].x + ((current.y - pos[0].y) * (1 / pente));
	  tekpixel(pix, &current, color);
	}
    }
}
