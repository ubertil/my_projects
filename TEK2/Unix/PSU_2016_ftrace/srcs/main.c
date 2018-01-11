/*
** main.c for PSU_2016_strace in /home/uberti_p/delivery/PSU_2016_strace/main.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mar. avr. 11 11:04:43 2017 Louis-Emile Uberti-Arès
** Last update Sat May  6 23:39:38 2017 chalie_a
*/

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "ftrace.h"

static _Bool	is_nbr(const char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    if (!isdigit(str[i]))
      return (false);
  return (true);
}

static _Bool	handle_args(int *pid, const int ac, char * const *av)
{
  char		c;

  while ((c = getopt(ac, av, "p:")) != -1)
    {
      if (c == 'p' && is_nbr(optarg))
	*pid = atoi(optarg);
      else if (c == 'p' && !is_nbr(optarg))
	return (false);
    }
  return (true);
}

int		main(const int ac, char * const *av)
{
  int		pid;

  pid = -1;
  if (ac < 2 || !handle_args(&pid, ac, av))
    {
      dprintf(1, USAGE);
      return (1);
    }
  return (ftrace(pid, av + optind));
}
