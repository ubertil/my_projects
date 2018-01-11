/*
** observer.h for observer in /home/uberti_l/rendu/Unix/PSU_2016_philo
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar 16 01:16:55 2017 Lous-Emile Uberti-Ares
** Last update Sun Mar 19 22:35:31 2017 Lous-Emile Uberti-Ares
*/

#ifndef OBSERVER_H_
# define OBSERVER_H_
# include <pthread.h>

typedef struct		s_observer
{
  pthread_t		thread;
  pthread_mutex_t	*mutex;
  pthread_cond_t	*cond;
  int			*turn_finished;
  int			*has_finished;
  int			nb_philo;
}			t_observer;

int			create_observer(t_observer *, int [5],
					pthread_mutex_t *,
					pthread_cond_t *);

#endif /* !OBSERVER_H_ */
