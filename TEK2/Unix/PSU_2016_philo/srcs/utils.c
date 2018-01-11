/*
** utils.c for utils in /home/grella_f/Rendu/2nd_year/PSU_2016_philo
**
** Made by félix grellard
** Login   <grella_f@epitech.net>
**
** Started on  Tue Mar 14 11:14:25 2017 félix grellard
** Last update Thu Mar 16 23:27:12 2017 Lous-Emile Uberti-Ares
*/

#include "philo.h"
#include "extern.h"

int			my_think(t_philo *philo)
{
  pthread_mutex_lock(philo->safe_mutex);
  if (*philo->has_finished == 1)
    {
      pthread_mutex_unlock(philo->safe_mutex);
      pthread_exit(NULL);
      return (1);
    }
  pthread_mutex_lock(&philo->chopsticks[philo->pos - 1]);
  lphilo_take_chopstick(&philo->chopsticks[philo->pos - 1]);
  lphilo_think();
  pthread_mutex_unlock(&philo->chopsticks[philo->pos - 1]);
  lphilo_release_chopstick(&philo->chopsticks[philo->pos - 1]);
  philo->state = 'T';
  pthread_mutex_unlock(philo->safe_mutex);
  return ((*philo->has_finished == 0) ? (wait(philo)) : (0));
}

int			my_eat(t_philo *philo)
{
  int			i;

  pthread_mutex_lock(philo->safe_mutex);
  i = (philo->pos - 2 < 0) ? (philo->nb_philo - 1) : (philo->pos - 2);
  if (*philo->has_finished == 1)
    {
      pthread_mutex_unlock(philo->safe_mutex);
      pthread_exit(NULL);
      return (1);
    }
  pthread_mutex_lock(&philo->chopsticks[philo->pos - 1]);
  lphilo_take_chopstick(&philo->chopsticks[philo->pos - 1]);
  pthread_mutex_lock(&philo->chopsticks[i]);
  lphilo_take_chopstick(&philo->chopsticks[i]);
  lphilo_eat();
  philo->has_eaten += 1;
  pthread_mutex_unlock(&philo->chopsticks[philo->pos - 1]);
  lphilo_release_chopstick(&philo->chopsticks[philo->pos - 1]);
  pthread_mutex_unlock(&philo->chopsticks[i]);
  lphilo_release_chopstick(&philo->chopsticks[i]);
  philo->state = 'E';
  pthread_mutex_unlock(philo->safe_mutex);
  return ((*philo->has_finished == 0) ? (wait(philo)) : (0));
}

int			my_sleep(t_philo *philo)
{
  pthread_mutex_lock(philo->safe_mutex);
  if (*philo->has_finished == 1)
    {
      pthread_mutex_unlock(philo->safe_mutex);
      pthread_exit(NULL);
      return (1);
    }
  if (philo->state != 'S')
    {
      lphilo_sleep();
      philo->state = 'S';
    }
  pthread_mutex_unlock(philo->safe_mutex);
  return ((*philo->has_finished == 0) ? (wait(philo)) : (0));
}

void			step(t_philo *philo, int i, int j)
{
  if (philo->pos % 4 == i)
    my_eat(philo);
  else if (philo->pos % 4 == j)
    my_think(philo);
  else
    my_sleep(philo);
}

int			other(t_philo *philo)
{
  int			i;
  int			j;

  if (philo->max > philo->has_eaten && *philo->has_finished == 0)
    step(philo, 3, 1);
  i = 1;
  j = 2;
  while (philo->max > philo->has_eaten && *philo->has_finished == 0)
    {
      step(philo, i, j);
      i = (i > 3) ? (0) : (i + 1);
      j = (j > 3) ? (0) : (j + 1);
    }
  *philo->has_finished = 1;
  return (0);
}
