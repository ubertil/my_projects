/*
** glob_wildcard.c for glob_wildcard in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 04:19:09 2016 louis-emile uberti-ares
** Last update Fri Jun  3 11:24:38 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <glob.h>
#include "shell.h"
#include "tools.h"

static int	glob_err_handler(const char *path, const int err)
{
  fprintf(stderr, "%s: %s\n", path, strerror(err));
  return (0);
}

static int	copy_old(char **new, char **args,
			 int *start, const int end)
{
  while (*start < end)
    {
      if ((new[*start] = strdup(args[*start])) == NULL)
	return (-1);
      *start += 1;
    }
  return (0);
}

static char	**add_glob_to_tab(glob_t results, char **args, int i)
{
  int		idx;
  int		j;
  char		**new;

  j = 0;
  idx = 0;
  if ((new = malloc(sizeof(char *) *
		    (args_size(args) + results.gl_pathc + 1))) == NULL)
    return (NULL);
  copy_old(new, args, &idx, i);
  while (idx <= (int)results.gl_pathc)
    if ((new[idx++] = strdup(results.gl_pathv[j++])) == NULL)
      return (NULL);
  copy_old(new, args, &idx, args_size(args));
  new[idx] = NULL;
  return (new);
}

char		**glob_wildcard(char **args, int i)
{
  int		err;
  char		**new;
  glob_t	results;

  err = glob(args[i], 0, glob_err_handler, &results);
  if (err != 0)
    return (args);
  else if ((new = add_glob_to_tab(results, args, i)) != NULL)
    {
      globfree(&results);
      return (new);
    }
  return (args);
}
