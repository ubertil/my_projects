/*
** signal.c for signal in /home/uberti_l/rendu/Unix/PSU_2016_lemipc
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Mar 31 17:13:08 2017 Lous-Emile Uberti-Ares
** Last update Sun Apr  2 12:50:02 2017 Lous-Emile Uberti-Ares
*/

#include <signal.h>
#include <stdlib.h>
#include "lemipc.h"

int			sighandler(int signum, t_team *ptr)
{
  static t_team		*team = NULL;

  if (team == NULL)
    team = ptr;
  if (signum == SIGINT)
    {
      send_msg(team, ALERT_QUIT);
      team_dead(team);
      exit(0);
    }
  return (0);
}
