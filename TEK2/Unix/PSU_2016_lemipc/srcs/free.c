/*
** free.c for free in /home/wadel_n/Tek2/PSU_2016_lemipc/srcs
**
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Fri Mar 31 14:07:54 2017 Nicolas Wadel
** Last update Sun Apr  2 11:31:26 2017 Lous-Emile Uberti-Ares
*/

#include <sys/msg.h>
#include <sys/shm.h>
#include "lemipc.h"

int	team_dead(t_team *team)
{
  if (team->shared != (void *)0)
    {
      team->shared->map[team->current_y][team->current_x] = -1;
      team->shared->nb_connected -= 1;
      unlock(team->sem_id, team->sops);
      if (team->shared->nb_connected <= 0)
	{
	  shmctl(team->shm_id, IPC_RMID, 0);
	  semctl(team->sem_id, 0, IPC_RMID);
	  msgctl(team->msg_id, IPC_RMID, 0);
	}
      shmdt(team->shared);
    }
  return (0);
}
