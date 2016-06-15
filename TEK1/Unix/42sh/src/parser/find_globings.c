/*
** find_globings.c for find_globings in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 04:39:09 2016 louis-emile uberti-ares
** Last update Thu May 12 06:44:50 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "parser.h"

static int	has_globing(const char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '*')
      return (1);
  return (0);
}

char		**find_globings(char **args)
{
  int		i;

  i = -1;
  while (args[++i] != NULL)
    if (has_globing(args[i]) == 1)
      args = glob_wildcard(args, i);
  return (args);
}
