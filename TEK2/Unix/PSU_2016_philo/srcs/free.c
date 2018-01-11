/*
** free.c for free in /home/uberti_l/rendu/Unix/PSU_2016_philo
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar 16 01:14:30 2017 Lous-Emile Uberti-Ares
** Last update Sun Mar 19 22:46:14 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include "philo.h"
#include "extern.h"

int		end_threads(t_philo *philo,
			    pthread_mutex_t *chopsticks,
			    int nb_philo, int emergency)
{
  int		i;

  i = -1;
  while (++i < nb_philo)
    pthread_join(philo[i].thread, NULL);
  free(chopsticks);
  free(philo);
  RCFCleanup();
  if (emergency == 1)
    {
      exit(84);
      return (1);
    }
  return (0);
}
