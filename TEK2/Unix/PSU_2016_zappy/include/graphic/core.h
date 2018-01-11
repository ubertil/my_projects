/*
** core.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 11:19:01 2017 alexis papadimitriou
** Last update Sun Jul  2 19:42:55 2017 grella_c
*/

#ifndef CORE_H_
# define CORE_H_
# define INIT_FLAGS SDL_INIT_VIDEO
# define WIDTH 1280
# define HEIGHT WIDTH * 9 / 16
# define W_FLAGS SDL_DOUBLEBUF
# define W_TITLE "Graphical client for zappy project"
# include <SDL/SDL.h>
# include <stdbool.h>
# include "client.h"
# include "map.h"
# include "font.h"
# include "info.h"
# include "player.h"

typedef struct	s_core
{
  t_info	*info;
  t_font	*font;
  t_plist	*player_list;
  t_client	*client;
  SDL_Surface	*screen;
  SDL_Event	*event;
  t_map		*map;
  int32_t	*collision_buf;
  bool		running;
}		t_core;

t_core		*init_core();
void		free_core(t_core *core);
int32_t		get_object_id(int32_t *collision_buf, int32_t x, int32_t y);

#endif /* !CORE_H_ */
