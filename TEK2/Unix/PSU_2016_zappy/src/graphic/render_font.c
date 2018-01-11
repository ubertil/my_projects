/*
** render_font.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Fri Jun 30 14:09:36 2017 alexis papadimitriou
** Last update Fri Jun 30 15:17:27 2017 alexis papadimitriou
*/

#include "graphic/font.h"

static bool	init_rendering(char c, uint32_t *start_y)
{
  if (c < 33 && c != '\n' && c != ' ')
    return (true);
  start_y[0] = (c - 33) * 5;
  start_y[1] = -1;
  return (false);
}

static bool	init_pos(char c, t_pos *pos, t_font *font, uint32_t tmp_x)
{
  if (c == '\n')
    {
      pos->y += 6 * font->scale_y;
      pos->x = tmp_x;
      return (true);
    }
  return (false);
}

static bool	can_render(t_font *font, uint32_t *start_y, uint32_t start_x)
{
  if (font->data[start_y[0] + (uint32_t)(start_y[1] / font->scale_y)]
      [(uint32_t)(start_x / font->scale_x)])
    return (true);
  return (false);
}

void		render_font(SDL_Surface *pix, const char *str,
			    t_font *font, t_pos pos)
{
  uint32_t	start_y[2];
  uint32_t	start_x;
  uint32_t	tmp_x;
  uint32_t	idx;

  tmp_x = pos.x;
  idx = -1;
  while (str[++idx])
    {
      if (init_rendering(str[idx], start_y) ||
	  init_pos(str[idx], &pos, font, tmp_x))
	continue ;
      if (str[idx] != ' ')
	while (++start_y[1] < 5 * font->scale_y)
	  {
	    start_x = -1;
	    while (++start_x < 5 * font->scale_x)
	      if (can_render(font, start_y, start_x))
		putpixel_a(pix, pos.x + start_x, pos.y + start_y[1],
			   font->color.full);
	  }
      pos.x += 6 * font->scale_x;
    }
}
