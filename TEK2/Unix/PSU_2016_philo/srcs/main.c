/*
1;4402;0c** main.c for PSU_2016_philo in /home/uberti_p/delivery/PSU_2016_philo/main.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  ven. mars 10 10:10:41 2017 Louis-Emile Uberti-Arès
** Last update Sun Mar 19 22:45:18 2017 Lous-Emile Uberti-Ares
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <getopt.h>
#include "observer.h"
#include "extern.h"
#include "philo.h"

static void		*organize(void *_arg)
{
  t_philo		*philo;

  philo = (t_philo *)_arg;
  wait(philo);
  if (*philo->has_finished == 0)
    handle_resources(philo);
  pthread_mutex_lock(philo->mutex);
  *philo->has_finished = 1;
  pthread_cond_broadcast(philo->cond);
  pthread_mutex_unlock(philo->mutex);
  pthread_exit(NULL);
  return (NULL);
}

static int		init_threads(int var[5],
				     pthread_mutex_t *mutex,
				     pthread_cond_t *cond)
{
  t_philo		*philo;
  t_observer		obs;
  pthread_mutex_t	safe_mutex;
  pthread_mutex_t	*chopsticks;

  safe_mutex = MUTEX();
  if (((philo = malloc(sizeof(t_philo) * var[0])) == NULL) ||
      ((chopsticks = malloc(sizeof(pthread_mutex_t) * var[0])) == NULL) ||
      (create_observer(&obs, var, mutex, cond) == -1))
    return (-1);
  while (++var[2] < var[0])
    {
      chopsticks[var[2]] = MUTEX();
      philo[var[2]].cond = cond;
      philo[var[2]].mutex = mutex;
      philo[var[2]].safe_mutex = &safe_mutex;
      fill_thread(philo, var, chopsticks);
      if (pthread_create(&philo[var[2]].thread, NULL, organize,
			 &philo[var[2]].thread))
	return (end_threads(philo, chopsticks, var[2], 1));
    }
  pthread_join(obs.thread, NULL);
  return (end_threads(philo, chopsticks, var[0], 0));
}

static inline _Bool	is_nbr(const char *str)
{
  int			i;

  i = -1;
  if (str == NULL)
    return (false);
  while (str[++i] != '\0')
    if (!isdigit(str[i]))
      return (false);
  return (true);
}

static _Bool		get_args(int ac, char * const *av, int *nb_philo,
				 int *max)
{
  char			c;
  _Bool			e_flag;
  _Bool			p_flag;

  e_flag = false;
  p_flag = false;
  while ((c = getopt(ac, av, "p:e:")) != -1)
    {
      if (c == 'p' && !p_flag && is_nbr(optarg))
	{
	  *nb_philo = atoi(optarg);
	  p_flag = true;
	}
      else if ((c == 'p' && p_flag) || (!is_nbr(optarg)))
	return (false);
      else if (c == 'e' && !e_flag && is_nbr(optarg))
	{
	  *max = atoi(optarg);
	  e_flag = true;
	}
      else if ((c == 'e' && e_flag) || (!is_nbr(optarg)))
	return (false);
    }
  return (true);
}

int			main(int ac, char **av)
{
  int			var[5];
  pthread_mutex_t	mutex;
  pthread_cond_t	cond;

  var[0] = -1;
  var[1] = -1;
  var[2] = -1;
  var[3] = 0;
  var[4] = 0;
  cond = COND();
  mutex = MUTEX();
  if ((ac != 5) || (RCFStartup(ac, av) == -1) ||
      (!get_args(ac, av, &var[0], &var[1])) || (var[0] <= -1) || (var[1] <= -1))
    {
      dprintf(1, USAGE, av[0]);
      return (1);
    }
  if (var[0] <= 1 || var[1] == 0)
    return (0);
  if (init_threads(var, &mutex, &cond) == -1)
    {
      perror("Error: init_threads: ");
      return (1);
    }
  return (0);
}
