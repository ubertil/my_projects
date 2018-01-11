/*
** wait.c for wait in /home/uberti_l/rendu/Unix/PSU_2016_philo
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar 16 12:14:45 2017 Lous-Emile Uberti-Ares
** Last update Thu Mar 16 22:59:05 2017 Lous-Emile Uberti-Ares
*/

#include "philo.h"

int			wait(t_philo *philo)
{
  pthread_mutex_lock(philo->mutex);
  *philo->turn_finished += 1;
  pthread_cond_wait(philo->cond, philo->mutex);
  pthread_mutex_unlock(philo->mutex);
  return (0);
}
