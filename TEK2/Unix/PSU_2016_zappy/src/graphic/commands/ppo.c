/*
** ppo.c for ppo.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:15:28 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:15:30 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "common/utils/utils.h"

bool	handle_ppo(t_core *core, char *str)
{
  char	**vals;

  if ((vals = str_to_wordtab(str, " ")) == NULL)
    return (false);
  (void)core;
  get_from_id(core->player_list, atoi(vals[1] + 1))->pos.x = atoi(vals[2]);
  get_from_id(core->player_list, atoi(vals[1] + 1))->pos.y = atoi(vals[3]);
  get_from_id(core->player_list, atoi(vals[1] + 1))->dir = atoi(vals[4]);
  free_wordtab(vals);
  return (true);
}