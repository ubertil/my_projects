/*
** ia_mode_target.c for ia_mode_target in /home/uberti_l/rendu/Unix/PSU_2016_lemipc
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Apr  1 21:22:32 2017 Lous-Emile Uberti-Ares
** Last update Sun Apr  2 16:26:59 2017 Lous-Emile Uberti-Ares
*/

#include "lemipc.h"

static void	move_and_eliminate(t_team *team, int move_x, int move_y)
{
  int		next_x;
  int		next_y;

  next_x = ((move_x == team->current_x) ? (move_x) :
	    (team->current_x + ((move_x < team->current_x) ? (-1) : (1))));
  next_y = ((move_y == team->current_y) ? (move_y) :
	    (team->current_y + ((move_y < team->current_y) ? (-1) : (1))));
  if (next_y >= 0 && next_y < MAP_Y && next_x >= 0 && next_x < MAP_X &&
      team->shared->map[next_y][next_x] == -1)
    {
      team->shared->map[team->current_y][team->current_x] = -1;
      team->current_x = next_x;
      team->current_y = next_y;
      team->shared->map[team->current_y][team->current_x] = team->team_number;
    }
  else
    move_random(team);
}

static void	find_and_fuck(t_team *team, int me)
{
  int		i[2];
  int		move_x;
  int		move_y;
  int		dist;

  i[0] = -1;
  dist = 0;
  if (team->status == ADMIN && team->live == DEAD)
    return ;
  while (++i[0] < MAP_Y)
    {
      i[1] = -1;
      while (++i[1] < MAP_X)
	if (team->shared->map[i[0]][i[1]] != -1 &&
	    team->shared->map[i[0]][i[1]] != me)
	  if (dist == 0 ||
	      ABS(team->current_x - i[1]) + ABS(team->current_y - i[0]) < dist)
	    {
	      dist = ABS(team->current_x - i[1]) + ABS(team->current_y - i[0]);
	      move_x = i[1];
	      move_y = i[0];
	    }
    }
  move_and_eliminate(team, move_x, move_y);
}

int		mode_target(t_team *team)
{
  int		msg;

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
	      team->shared->nb_connected -=1;
	    }
	  else
	    return (team_dead(team));
	}
      find_and_fuck(team, team->team_number);
      display_map(team);
      unlock(team->sem_id, team->sops);
    }
  team->shared->nb_connected = 0;
  return (team_dead(team));
}
