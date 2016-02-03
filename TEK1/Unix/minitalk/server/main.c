/*
** main.c for main_server in /home/uberti_l/rendu/Unix/PSU_2015_minitalk/minitalk_server
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  1 16:41:02 2016 louis-emile uberti-ares
** Last update Wed Feb  3 14:06:36 2016 louis-emile uberti-ares
*/

#include <signal.h>
#include <unistd.h>
#include "include/server.h"

void		sighandler(int signum)
{
  static int	ascii = 0;
  static int	power = 0;

  if (signum == SIGUSR1)
    ascii += 1 << (7 - power);
  if ((power += 1) == 8)
    {
      my_putchar(ascii);
      power = 0;
      ascii = 0;
    }
}

int		main(void)
{
  my_putstr("PID : ");
  my_put_nbr(getpid());
  my_putchar('\n');
  signal(SIGUSR1, sighandler);
  signal(SIGUSR2, sighandler);
  while (42);
  return (0);
}
