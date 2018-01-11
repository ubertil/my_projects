/*
** philo.h for PSU_2016_philo in /home/uberti_p/delivery/PSU_2016_philo/philo.h
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  ven. mars 10 10:20:53 2017 Louis-Emile Uberti-Arès
** Last update Sun Mar 19 22:43:49 2017 Lous-Emile Uberti-Ares
*/

#ifndef PHILO_H_
# define PHILO_H_
# include <pthread.h>

# define MUTEX() (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER
# define COND() (pthread_cond_t)PTHREAD_COND_INITIALIZER
# define USAGE "Usage : %s -p NB_PHILOSOPHERS -e MAX_EAT\n"

typedef struct		s_philo
{
  pthread_t		thread;
  pthread_mutex_t	*chopsticks;
  pthread_mutex_t	*mutex;
  pthread_mutex_t	*safe_mutex;
  pthread_cond_t	*cond;
  char			state;
  int			max;
  int			pos;
  int			has_eaten;
  int			nb_philo;
  int			*turn_finished;
  int			*has_finished;
}			t_philo;

void			fill_thread(t_philo *, int [5], pthread_mutex_t *);
int			wait(t_philo *);
int			end_threads(t_philo *, pthread_mutex_t *, int, int);
int			handle_resources(t_philo *);
int			my_think(t_philo *);
int			my_eat(t_philo *);
int			my_sleep(t_philo *);
int			other(t_philo *);

#endif /* !PHILO_H_ */
