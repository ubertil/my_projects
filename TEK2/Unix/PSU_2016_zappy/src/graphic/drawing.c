/*
** drawing.c<src> for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 11:40:25 2017 alexis papadimitriou
** Last update Thu Jun 29 16:45:40 2017 alexis papadimitriou
*/

#include "graphic/drawing.h"

void		putpixel(SDL_Surface *pix, int32_t x, int32_t y, uint32_t c)
{
  if (x>= 0 && y >= 0 && x < pix->w && y < pix->h)
    ((uint32_t *)(pix->pixels))[x + y * pix->w] = c;
}

void		putpixel_a(SDL_Surface *pix, int32_t x, int32_t y, uint32_t c)
{
  t_color	c1;
  t_color	c2;
  t_color	result;
  float		factor;

  c1.full = c;
  if (x>= 0 && y >= 0 && x < pix->w && y < pix->h)
    {
      c2.full = getpixel(pix, x, y);
      factor = c1.argb[A] / 255.;
      result.argb[R] = c2.argb[R] * (1 - factor) + c1.argb[R] * factor;
      result.argb[G] = c2.argb[G] * (1 - factor) + c1.argb[G] * factor;
      result.argb[B] = c2.argb[B] * (1 - factor) + c1.argb[B] * factor;
      ((uint32_t *)(pix->pixels))[x + y * pix->w] = result.full;
    }
}

uint32_t	getpixel(const SDL_Surface *pix, int32_t x, int32_t y)
{
  t_color	c;

  if (x>= 0 && y >= 0 && x < pix->w && y < pix->h)
    c.full = ((uint32_t *)(pix->pixels))[x + y * pix->w];
  return (c.full);
}

void		fill(SDL_Surface *pix, uint32_t c)
{
  uint32_t	size;
  uint32_t	idx;

  size = pix->w * pix->h;
  idx = 0;
  while (idx < size)
    {
      ((uint32_t *)(pix->pixels))[idx] = c;
      idx += 1;
    }
}

void		blit_surface(SDL_Surface *pix, const SDL_Surface *src,
			     int32_t x, int32_t y)
{
  t_pos		pos;

  pos.y = 0;
  while (pos.y < src->h)
    {
      pos.x = 0;
      while (pos.x < src->w)
	{
	  putpixel_a(pix, x + pos.x, y + pos.y, getpixel(src, pos.x, pos.y));
	  pos.x += 1;
	}
      pos.y += 1;
    }
}
