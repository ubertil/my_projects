/*
** pin.c for pin.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 18:55:17 2017 Nicolas TROGNOT
** Last update Sun Jul  2 18:55:17 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "common/utils/utils.h"

bool	handle_pin(t_core *core, char *str)
{
  char	**vals;
  int	x;
  int	y;
  int	i;

  if ((vals = str_to_wordtab(str, " ")) == NULL)
    return (false);
  x = atoi(vals[2]);
  y = atoi(vals[3]);
  i = -1;
  get_from_id(core->player_list, atoi(vals[1] + 1))->pos.x = x;
  get_from_id(core->player_list, atoi(vals[1] + 1))->pos.y = y;
  while (++i < NB_ITEM)
    get_from_id(core->player_list, atoi(vals[1] + 1))->inventory[i] =
      atoi(vals[i + 4]);
  free_wordtab(vals);
  return (true);
}
