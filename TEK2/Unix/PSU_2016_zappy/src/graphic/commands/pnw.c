/*
** pnw.c for pnw.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:18:59 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:19:01 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "graphic/player.h"
#include "common/utils/utils.h"

bool		handle_pnw(t_core *core, char *str)
{
  char		**vals;
  t_player	*p;

  if ((vals = str_to_wordtab(str, " ")) == NULL ||
      (p = init_player(atoi(vals[2]), atoi(vals[3]))) == NULL)
    return (false);
  p->id = atoi(vals[1] + 1);
  p->dir = atoi(vals[4]);
  p->level = atoi(vals[5]);
  if ((p->team = strdup(vals[6])) == NULL)
    return (false);
  push(core->player_list, p);
  free_wordtab(vals);
  return (true);
}
