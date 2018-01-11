/*
** main.c for main in /home/uberti_l/rendu/Unix/PSU_2016_lemipc
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Mar 20 10:29:03 2017 Lous-Emile Uberti-Ares
** Last update Sun Apr  2 11:49:39 2017 Lous-Emile Uberti-Ares
*/

#include <signal.h>
#include <sys/shm.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

static int	get_sem(t_team *team, const key_t key)
{
  int		sem_id;

  sem_id = semget(key, 1, SHM_R | SHM_W);
  team->live = ALIVE;
  if (sem_id == -1)
    {
      team->sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
      if (team->sem_id == -1)
	{
	  dprintf(2, SEM_ERR_CREATE);
	  return (1);
	}
      semctl(team->sem_id, 0, SETVAL, 1);
      dprintf(1, SEM_CREATED, team->sem_id);
    }
  else
    {
      team->sem_id = sem_id;
      dprintf(1, SEM_USED, team->sem_id);
    }
  return (get_msgq(team, key));
}

static int	get_shm(t_team *team, const key_t key)
{
  int		shm_id;

  shm_id = shmget(key, SHM_SIZE, SHM_R | SHM_W);
  if (shm_id == -1)
    {
      team->shm_id = shmget(key, SHM_SIZE, IPC_CREAT | SHM_R | SHM_W);
      if (team->shm_id == -1)
	{
	  dprintf(2, SHM_ERR_CREATE);
	  return (1);
	}
      team->status = ADMIN;
      dprintf(1, SHM_CREATED, team->shm_id);
      team->shared = (t_shared *)shmat(team->shm_id, NULL, SHM_R | SHM_W);
      create_map(team);
    }
  else
    {
      team->status = CLIENT;
      team->shm_id = shm_id;
      dprintf(1, SHM_USED, team->shm_id);
      team->shared = (t_shared *)shmat(team->shm_id, NULL, SHM_R | SHM_W);
      team->shared->nb_connected += 1;
    }
  return (0);
}

static int	launch_prog(const key_t key, const int team_number,
			    const char *cmd)
{
  t_team	team;

  team.team_number = team_number;
  team.shared = NULL;
  if (get_shm(&team, key))
    {
      team_dead(&team);
      return (1);
    }
  if (get_sem(&team, key))
    {
      team_dead(&team);
      return (1);
    }
  if (MAP_Y * MAP_X < team.shared->nb_connected)
    {
      dprintf(1, TOO_MANY_CLIENTS, MAP_Y * MAP_X);
      return (team_dead(&team));
    }
  place_randomly(&team);
  sighandler(42, &team);
  if (signal(SIGINT, (void (*)(int))sighandler) == SIG_ERR)
    return (1);
  dprintf(1, NEW_FIGHTER, team.team_number, team.current_y, team.current_x);
  return (handle_args(&team, cmd));
}

static inline int	is_nbr(const char *str)
{
  int			i;

  i = -1;
  while (str[++i] != '\0')
    if (isdigit(str[i]))
      return (1);
  return (0);
}

int		main(int ac, const char * const * av)
{
  key_t		key;

  if (ac < 3)
    {
      dprintf(1, USAGE);
      return (1);
    }
  key = ftok(av[1], 0);
  if ((key == (key_t)-1) || (!is_nbr(av[2])))
    {
      perror("Error");
      return (1);
    }
  return (launch_prog(key, atoi(av[2]), (ac < 4) ? ("") : (av[3])));
}
