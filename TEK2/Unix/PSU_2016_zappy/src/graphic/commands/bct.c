/*
** bct.c for bct.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:17:08 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:17:25 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "common/utils/utils.h"

bool	handle_bct(t_core *core, char *str)
{
  char	**vals;
  int	x;
  int	y;
  int	i;

  if ((vals = str_to_wordtab(str, " ")) == NULL)
    return (false);
  x = atoi(vals[1]);
  y = atoi(vals[2]);
  i = -1;
  while (++i < NB_ITEM)
    core->map->items[x + y * core->map->width].data[i] = atoi(vals[i + 3]);
  free_wordtab(vals);
  return (true);
}
