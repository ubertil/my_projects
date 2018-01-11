/*
** pgt.c for pgt.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:15:51 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:16:05 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "graphic/command_handler.h"
#include "graphic/player.h"
#include "common/utils/utils.h"

bool		handle_pgt(t_core *core, char *str)
{
  char		**vals;

  if ((vals = str_to_wordtab(str, " ")) == NULL)
    return (NULL);
  (void)core;
  free_wordtab(vals);
  return (true);
}
