/*
** msz.c for msz.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:16:10 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:17:00 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "common/utils/utils.h"

bool		handle_msz(t_core *core, char *str)
{
  char		**vals;
  uint32_t	m_size;

  if ((vals = str_to_wordtab(str, " ")) == NULL||
      (core->map = init_map(atoi(vals[1]), atoi(vals[2]))) == NULL)
    return (false);
  m_size = (core->map->width > core->map->height) ? (core->map->width) :
    (core->map->height);
  if ((core->player_list->player_texture[NORTH] =
       stretch(core->player_list->player_texture[NORTH], PLAYER_SIZE))
      == NULL || (core->player_list->player_texture[SOUTH] =
		  stretch(core->player_list->player_texture[SOUTH],
			  PLAYER_SIZE))
      == NULL || (core->player_list->player_texture[WEST] =
		  stretch(core->player_list->player_texture[WEST],
			  PLAYER_SIZE))
      == NULL || (core->player_list->player_texture[EAST] =
		  stretch(core->player_list->player_texture[EAST],
			  PLAYER_SIZE)) == NULL)
    return (false);
  free_wordtab(vals);
  return (true);
}
