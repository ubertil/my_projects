/*
** main.c for PSU_2016_strace in /home/uberti_p/delivery/PSU_2016_strace/main.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mar. avr. 11 11:04:43 2017 Louis-Emile Uberti-Arès
** Last update Thu Apr 13 21:40:15 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "strace.h"

static _Bool	is_nbr(const char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    if (!isdigit(str[i]))
      return (false);
  return (true);
}

static _Bool	find_exec(t_strace *info, char * const *av,
			  const int ac, const int start)
{
  int		i;

  i = -1;
  if ((info->exec = malloc(sizeof(char *) * (ac - start + 1))) == NULL)
    return (false);
  while (start + ++i < ac)
    if ((info->exec[i] = strdup(av[start + i])) == NULL)
      return (false);
  info->exec[i] = NULL;
  return (true);
}

static _Bool	handle_args(t_strace *info, const int ac, char * const *av)
{
  char		c;

  info->verbose = false;
  info->pid = -1;
  info->exec = NULL;
  while ((c = getopt(ac, av, "sp:")) != -1)
    {
      if (c == 's')
	info->verbose = true;
      if (c == 'p' && is_nbr(optarg))
	info->pid = atoi(optarg);
      else if (c == 'p' && !is_nbr(optarg))
	return (false);
    }
  if (optind < ac)
    return (find_exec(info, av, ac, optind));
  return (true);
}

int		main(const int ac, char * const *av)
{
  t_strace	info;

  if (ac < 2 || !handle_args(&info, ac, av))
    {
      dprintf(1, USAGE);
      return (1);
    }
  return (strace(&info, (optind < ac) ? (av[optind]) : (NULL)));
}
