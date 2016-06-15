/*
** new_command.c for new_command in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May 11 11:06:21 2016 louis-emile uberti-ares
** Last update Mon May 30 17:31:12 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "shell.h"

static int	full_size(char **args, int i)
{
  int		size;

  size = 0;
  while (args[i] != NULL)
    size += strlen(args[i++]) + 1;
  return (size);
}

char	*new_command(char **args, int idx)
{
  int	size;
  char	*str;

  idx += 1;
  str = NULL;
  if (args[idx] == NULL)
    return (NULL);
  size = full_size(args, idx);
  if ((str = malloc(size + 1)) == NULL)
    return (NULL);
  str[0] = '\0';
  while (args[idx] != NULL)
    {
      str = strcat(str, args[idx++]);
      if (args[idx] != NULL)
	str = strcat(str, " ");
    }
  free_args(args);
  return (str);
}
