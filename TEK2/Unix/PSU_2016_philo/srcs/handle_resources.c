/*
** handle_ressources.c for PSU_2016_philo in /home/uberti_p/delivery/PSU_2016_philo/handle_ressources.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  lun. mars 13 11:38:23 2017 Louis-Emile Uberti-Arès
** Last update Fri Mar 17 10:38:00 2017 félix grellard
*/

#include "philo.h"
#include "extern.h"

int			state_pair(t_philo *philo, int i)
{
  int			res;

  res = (philo->pos % 2 == i) ? (my_think(philo)) : (my_sleep(philo));
  if (res != 0)
    return (res);
  res = (philo->pos % 2 == i) ? (my_eat(philo)) : (my_sleep(philo));
  return (res);
}

int			pair(t_philo *philo)
{
  int			res;
  short			i;

  i = 0;
  while (philo->max > philo->has_eaten && *philo->has_finished == 0)
    {
      res = state_pair(philo, i);
      if (res != 0)
	return (res);
      i = (i == 1) ? (0) : (i + 1);
    }
  *philo->has_finished = 1;
  return (res);
}

void			step_three(t_philo *philo, int i, int j)
{
  if (philo->pos % 3 == i)
    my_eat(philo);
  else if (philo->pos % 3 == j)
    my_think(philo);
  else
    my_sleep(philo);
}

int			multiple_three(t_philo *philo)
{
  int			i;
  int			j;

  i = 0;
  j = 1;
  while (philo->max > philo->has_eaten && *philo->has_finished == 0)
    {
      step_three(philo, i, j);
      i = (i > 2) ? (0) : (i + 1);
      j = (j > 2) ? (0) : (j + 1);
    }
  *philo->has_finished = 1;
  return (0);
}

int			handle_resources(t_philo *philo)
{
  return ((philo->nb_philo % 3 == 0) ? (multiple_three(philo)) :
	  ((philo->nb_philo % 2 == 0) ?
	   (pair(philo)) :
	   (other(philo))));
}
