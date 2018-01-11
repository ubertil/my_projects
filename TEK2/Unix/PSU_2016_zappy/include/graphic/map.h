/*
** map.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 12:08:36 2017 alexis papadimitriou
** Last update Sat Jul  1 18:43:21 2017 alexis papadimitriou
*/

#ifndef MAP_H_
# define MAP_H_
# include <stdint.h>
# include <SDL/SDL.h>
# include "drawing.h"
# include "common/resources.h"
# define MAP_SIZE 640
# define GRASS_SIZE MAP_SIZE / m_size
# define RES_SIZE MAP_SIZE / (m_size * 2)
# define NB_TEXTURE 8
# define GRASS_TEXT "resources/grass.png"
# define LINEMATE_TEXT "resources/linemate.png"
# define DERAUMERE_TEXT "resources/deraumere.png"
# define SIBUR_TEXT "resources/sibur.png"
# define MENDIANE_TEXT "resources/mendiane.png"
# define PHIRAS_TEXT "resources/phiras.png"
# define THYSTAME_TEXT "resources/thystame.png"
# define FOOD_TEXT "resources/food.png"
# define GRASS_IDX 0
# define IDX(x) x + 1

typedef struct	s_items
{
  uint8_t	data[NB_ITEM];
  t_pos		pos[NB_ITEM];
}		t_items;

typedef struct	s_map
{
  uint32_t	width;
  uint32_t	height;
  t_items	*items;
  SDL_Surface	**textures;
  int32_t	*collision_buffer;
}		t_map;

t_map		*init_map(uint32_t width, uint32_t height);
void		free_map(t_map *map);
void		set_data(t_map *map, uint32_t x, uint32_t y, uint8_t data);
void		render_map(SDL_Surface *pix, t_map *map, uint32_t x,
			   uint32_t y);
void		set_floor_id(int32_t *collision_buf, t_map *map,
			     uint32_t x, uint32_t y);

#endif /* !MAP_H_ */
