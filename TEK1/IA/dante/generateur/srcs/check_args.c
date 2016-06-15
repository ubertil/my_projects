/*
** check_args.c for check_args in /home/uberti_l/rendu/Init_ia/dante/generateur/srcs
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 27 13:47:07 2016 louis-emile uberti-ares
** Last update Fri May 27 17:17:29 2016 louis-emile uberti-ares
** Last update Fri May 27 16:23:56 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <string.h>
#include "generateur.h"

int		check_args(char **av, int ac, char *mode)
{
  if ((atoi(av[1]) <= 0) ||
      (atoi(av[2]) <= 0))
    return (my_putstr_err(ERR_SIZE));
  if ((atoi(av[1]) > 1000) || (atoi(av[2]) > 1000))
    return (my_putstr_err(TOO_MUCH));
  if (ac == 3)
    {
      *mode = 0;
    }
  else
    {
      if (strcmp(av[3], "parfait") != 0 && strcmp(av[3], "imparfait") != 0)
	return (my_putstr_err(ERR_TYPE));
      if (av[3][0] == 'p')
	*mode = 1;
      else
	*mode = 0;
    }
  return (0);
}
