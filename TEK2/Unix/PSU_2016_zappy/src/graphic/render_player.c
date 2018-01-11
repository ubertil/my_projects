/*
** render_player.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 28 16:55:23 2017 alexis papadimitriou
** Last update Sat Jul  1 18:56:19 2017 alexis papadimitriou
*/

#include "graphic/core.h"

void		render_player(SDL_Surface *pix, t_plist *list,
			      uint32_t width, uint32_t height)
{
  t_player	*current;
  SDL_Surface	*to_render;

  current = list->head;
  while (current)
    {
      to_render = list->player_texture[current->dir];
      blit_surface(pix, to_render,
		   current->pos.x * width + width / 2 - to_render->w / 4,
		   current->pos.y * height + height / 2 - to_render->h / 4);
      current = current->next;
    }
}

static void	blit_id(int32_t *collision_buf, const SDL_Surface *src,
			int32_t id, t_pos *start)
{
  t_pos		pos;

  pos.y = 0;
  while (pos.y < src->h)
    {
      pos.x = 0;
      while (pos.x < src->w)
	{
	  if (getpixel(src, pos.x, pos.y))
	    collision_buf[start->x + pos.x + (start->y + pos.y) * WIDTH] = id;
	  pos.x += 1;
	}
      pos.y += 1;
    }
}

void		set_player_id(int32_t *collision_buf, t_plist *list,
			      uint32_t width, uint32_t height)
{
  t_player	*current;
  SDL_Surface	*to_render;
  t_pos		start;

  current = list->head;
  while (current)
    {
      to_render = list->player_texture[current->dir];
      start.x = current->pos.x * width + width / 2 - to_render->w / 4;
      start.y = current->pos.y * height + height / 2 - to_render->h / 4;
      blit_id(collision_buf, to_render, current->id, &start);
      current = current->next;
    }
}
