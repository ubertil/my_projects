/*
** play.c for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/play.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. mars 29 19:17:06 2017 Louis-Emile Uberti-Arès
** Last update Sun Apr  2 15:46:02 2017 Nicolas Wadel
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemipc.h"

void		move_random(t_team *team)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  if (team->status == ADMIN && team->live == DEAD)
    return ;
  while (team->shared->map[team->current_y + y][team->current_x + x] != -1)
    {
      x = (rand() % 3) - 1;
      y = (rand() % 3) - 1;
      while ((team->current_x + x < 0 || team->current_x + x >= MAP_X) ||
	     (team->current_y + y < 0 || team->current_y + y >= MAP_Y))
	{
	  x = (rand() % 3) - 1;
	  y = (rand() % 3) - 1;
	}
    }
  team->shared->map[team->current_y][team->current_x] = -1;
  team->current_x += x;
  team->current_y += y;
  team->shared->map[team->current_y][team->current_x] = team->team_number;
}

int	mode_random(t_team *team)
{
  int	msg;

  while (winner(team) == 0)
    {
      lock(team->sem_id, team->sops);
      if ((is_dead(team) == 1) || (msg = rcv_msg(team, ALERT_QUIT) == 0))
	{
	  team->live = DEAD;
	  if (msg == 0)
	    send_msg(team, ALERT_QUIT);
	  if (team->status == ADMIN)
	    {
	      team->shared->map[team->current_y][team->current_x] = -1;
	      team->shared->nb_connected -= 1;
	    }
	  else
	    return (team_dead(team));
	}
      move_random(team);
      display_map(team);
      unlock(team->sem_id, team->sops);
    }
  team->shared->nb_connected = 0;
  return (team_dead(team));
}
