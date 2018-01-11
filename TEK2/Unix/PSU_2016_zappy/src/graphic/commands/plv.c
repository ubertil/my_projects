/*
** plv.c for plv.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:15:33 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:15:46 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "common/utils/utils.h"

bool	handle_plv(t_core *core, char *str)
{
  char	**vals;

  if ((vals = str_to_wordtab(str, " ")) == NULL)
    return (false);
  get_from_id(core->player_list, atoi(vals[1] + 1))->level = atoi(vals[2]);
  free_wordtab(vals);
  return (true);
}
