/*
** handle_args.c for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/handle_args.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. mars 30 13:00:06 2017 Louis-Emile Uberti-Arès
** Last update Sun Apr  2 16:23:55 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include <string.h>
#include "modes.h"

static void	init_modes(t_modes *modes)
{
  modes[0].str = "target";
  modes[1].str = "random";
  modes[2].str = "default";
  modes[3].str = "";
  modes[0].f = mode_target;
  modes[1].f = mode_random;
  modes[2].f = mode_target;
  modes[3].f = mode_target;
}

int		handle_args(t_team *team, const char *cmd)
{
  int		i;
  int		start;
  int		idx;
  t_modes	modes[4];

  i = -1;
  init_modes(modes);
  start = 0;
  idx = 2;
  if (strncmp("--mode=", cmd, 7) != 0)
    idx = 2;
  else
    {
      while (modes[++i].str[0] != '\0')
	if (strcmp(cmd + 7, modes[i].str) == 0)
	  idx = i;
    }
  dprintf(1, IA_MODE, modes[idx].str);
  while (start != 1)
    start = can_start(team);
  return (modes[idx].f(team));
}
