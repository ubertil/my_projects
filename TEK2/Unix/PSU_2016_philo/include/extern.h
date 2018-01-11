/*
** extern.h for extern in /home/uberti_l/rendu/Unix/PSU_2016_philo
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar 16 12:50:40 2017 Lous-Emile Uberti-Ares
** Last update Sun Mar 19 22:44:24 2017 Lous-Emile Uberti-Ares
*/

#ifndef EXTERN_H_
# define EXTERN_H_
# include <pthread.h>

int	RCFStartup(int ac, char **av);
void	RCFCleanup();
int	lphilo_eat();
int	lphilo_sleep();
int	lphilo_think();
int	lphilo_take_chopstick(const pthread_mutex_t *mutex_id);
int	lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* !EXTERN_H_ */
