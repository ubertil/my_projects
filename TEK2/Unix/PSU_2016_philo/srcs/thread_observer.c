/*
** thread_observer.c for thread_observer in /home/uberti_l/rendu/Unix/PSU_2016_philo
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Mar 15 12:44:17 2017 Lous-Emile Uberti-Ares
** Last update Sun Mar 19 22:35:59 2017 Lous-Emile Uberti-Ares
*/

#include "philo.h"
#include "observer.h"

static inline void	broadcast(t_observer *obs)
{
  pthread_mutex_lock(obs->mutex);
  *obs->turn_finished = 0;
  pthread_cond_broadcast(obs->cond);
  pthread_mutex_unlock(obs->mutex);
}

static void		*monitor(void *_arg)
{
  t_observer		*obs;

  obs = (t_observer *)_arg;
  while (*obs->has_finished == 0)
    if (*obs->turn_finished == obs->nb_philo)
      broadcast(obs);
  broadcast(obs);
  pthread_exit(NULL);
}

void			fill_thread(t_philo *philo, int var[5],
				    pthread_mutex_t *chopsticks)
{
  philo[var[2]].nb_philo = var[0];
  philo[var[2]].max = var[1];
  philo[var[2]].pos = var[2] + 1;
  philo[var[2]].has_finished = &var[3];
  philo[var[2]].turn_finished = &var[4];
  philo[var[2]].state = 'R';
  philo[var[2]].has_eaten = 0;
  philo[var[2]].chopsticks = chopsticks;
}

int			create_observer(t_observer *obs, int var[5],
					pthread_mutex_t *mutex,
					pthread_cond_t *cond)
{
  obs->has_finished = &var[3];
  obs->nb_philo = var[0];
  obs->turn_finished = &var[4];
  obs->cond = cond;
  obs->mutex = mutex;
  if (pthread_create(&obs->thread, NULL, monitor, &obs->thread) == -1)
    return (-1);
  return (0);
}
