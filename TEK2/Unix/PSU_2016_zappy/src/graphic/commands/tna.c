/*
** tna.c for tna.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:15:16 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:15:22 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "common/utils/utils.h"

bool	handle_tna(t_core *core, char *str)
{
  char	**vals;

  if ((vals = str_to_wordtab(str, " ")) == NULL)
    return (false);
  add_team_name(core->player_list, vals[1]);
  free_wordtab(vals);
  return (true);
}
