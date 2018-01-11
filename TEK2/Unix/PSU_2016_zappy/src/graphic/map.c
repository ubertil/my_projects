/*
** map.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 12:16:26 2017 alexis papadimitriou
** Last update Sat Jul  1 18:45:40 2017 alexis papadimitriou
*/

#include <stdbool.h>
#include <SDL/SDL_image.h>
#include "graphic/core.h"


static bool	load_textures(t_map *client, uint32_t m_size)
{
  if ((client->textures = malloc(sizeof(SDL_Surface *) * (NB_TEXTURE + 1)))
      == NULL ||
      (client->textures[GRASS_IDX] = stretch(IMG_Load(GRASS_TEXT), GRASS_SIZE))
      == NULL ||
      (client->textures[IDX(LINEMATE)] = stretch(IMG_Load(LINEMATE_TEXT),
						 RES_SIZE)) == NULL ||
      (client->textures[IDX(DERAUMERE)] = stretch(IMG_Load(DERAUMERE_TEXT),
						  RES_SIZE)) == NULL ||
      (client->textures[IDX(SIBUR)] = stretch(IMG_Load(SIBUR_TEXT),
					      RES_SIZE)) == NULL ||
      (client->textures[IDX(MENDIANE)] = stretch(IMG_Load(MENDIANE_TEXT),
						 RES_SIZE)) == NULL ||
      (client->textures[IDX(PHIRAS)] = stretch(IMG_Load(PHIRAS_TEXT),
					       RES_SIZE)) == NULL ||
      (client->textures[IDX(THYSTAME)] = stretch(IMG_Load(THYSTAME_TEXT),
						 RES_SIZE)) == NULL ||
      (client->textures[IDX(FOOD)] = stretch(IMG_Load(FOOD_TEXT),
					     RES_SIZE)) == NULL)
    return (false);
  client->textures[NB_TEXTURE] = NULL;
  return (true);
}

t_map		*init_map(uint32_t width, uint32_t height)
{
  t_map		*new;
  uint32_t	idx;
  uint32_t	i_pos;

  if ((new = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  new->width = width;
  new->height = height;
  if ((new->items = malloc(sizeof(t_items) * (width * height))) == NULL ||
      load_textures(new, (width > height) ? (width) : (height)) == false)
    return (NULL);
  idx = -1;
  while (++idx < width * height)
    {
      i_pos = -1;
      memset(new->items[idx].data, 0, NB_ITEM);
      while (++i_pos < NB_ITEM)
	{
	  new->items[idx].pos[i_pos].x = rand() %
	    (new->textures[GRASS_IDX]->w - new->textures[IDX(i_pos)]->w);
	  new->items[idx].pos[i_pos].y = rand() %
	    (new->textures[GRASS_IDX]->h - new->textures[IDX(i_pos)]->h);
	}
    }
  return (new);
}

void		free_map(t_map *map)
{
  uint32_t	idx;

  idx = 0;
  while (map->textures[idx])
    {
      SDL_FreeSurface(map->textures[idx]);
      idx += 1;
    }
  free(map->textures);
  free(map->items);
  free(map);
}

void		render_map(SDL_Surface *pix, t_map *map,
			   uint32_t x, uint32_t y)
{
  SDL_Surface	*to_render;
  t_pos		pos;
  t_pos		size;
  uint8_t	i_type;
  uint32_t	i_idx;

  pos.y = 0;
  while ((unsigned)pos.y < map->height)
    {
      pos.x = 0;
      while ((unsigned)pos.x < map->width)
	{
	  to_render = map->textures[GRASS_IDX];
	  size.x = x + pos.x * to_render->w;
	  size.y = y + pos.y * to_render->h;
	  blit_surface(pix, to_render, size.x, size.y);
	  i_type = -1;
	  i_idx = pos.x + pos.y * map->width;
	  while (++i_type < NB_ITEM)
	    {
	      if (map->items[i_idx].data[i_type])
		{
		  to_render = map->textures[IDX(i_type)];
		  blit_surface(pix, to_render,
			       size.x + map->items[i_idx].pos[i_type].x,
			       size.y + map->items[i_idx].pos[i_type].y);
		}
	    }
	  pos.x += 1;
	}
      pos.y += 1;
    }
}

void		set_floor_id(int32_t *collision_buf, t_map *map,
			     uint32_t x, uint32_t y)
{
  t_pos		pos;
  uint32_t	m_size;

  m_size = (map->width > map->height) ? (map->width) : (map->height);
  pos.y = 0;
  while ((unsigned)pos.y < map->height * GRASS_SIZE)
    {
      pos.x = 0;
      while ((unsigned)pos.x < map->width * GRASS_SIZE)
	{
	  collision_buf[pos.x + x + (pos.y + y) * WIDTH] = 0;
	  pos.x += 1;
	}
      pos.y += 1;
    }
}
