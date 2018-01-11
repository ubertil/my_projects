/*
** stretch.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Thu Jun 29 15:46:12 2017 alexis papadimitriou
** Last update Thu Jun 29 17:02:25 2017 alexis papadimitriou
*/

#include <SDL/SDL.h>
#include "graphic/drawing.h"

static SDL_Surface	*createSurfaceByDim(uint32_t width, uint32_t height,
					    uint32_t size)
{
  t_pos			dim;

  dim.x = (width > height) ? (size) : (((float)width / height) * size);
  dim.y = (height > width) ? (size) : (((float)height / width) * size);

  return (SDL_CreateRGBSurface(0, dim.x, dim.y, 32,
			       0x000000FF,
			       0x0000FF00,
			       0x00FF0000,
			       0xFF000000));
}

uint32_t		fix_color(t_color c)
{
  uint32_t		swap;

  swap = c.argb[R];
  c.argb[R] = c.argb[B];
  c.argb[B] = swap;
  return (c.full);
}

SDL_Surface		*stretch(SDL_Surface *pix, uint32_t size)
{
  SDL_Surface		*new;
  t_color		c;
  t_pos			pos;
  float			ratio[2];

  if ((new = createSurfaceByDim(pix->w, pix->h, size)) == NULL)
    return (NULL);
  ratio[0] = (float)new->w / pix->w;
  ratio[1] = (float)new->h / pix->h;
  pos.y = 0;
  while (pos.y < new->h)
    {
      pos.x = 0;
      while (pos.x < new->w)
	{
	  c.full = getpixel(pix, (int)(pos.x / ratio[0]),
			    (int)(pos.y / ratio[1]));
	  putpixel(new, pos.x, pos.y, fix_color(c));
	  pos.x += 1;
	}
      pos.y += 1;
    }
  SDL_FreeSurface(pix);
  return (new);
}
