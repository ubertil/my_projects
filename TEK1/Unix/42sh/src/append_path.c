/*
** append_path.c for append_path in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May 11 16:59:10 2016 louis-emile uberti-ares
** Last update Sun Jun  5 15:57:32 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

static void		append_them_both(char *str, char **old, char **path,
					 const int i)
{
  memset(old[0], '\0', (strlen(path[i]) + strlen(str) + 1));
  old[0] = strcpy(old[0], path[i]);
  (path[i][strlen(path[i])] == '/') ? (0) : (old[0][strlen(old[0])] = '/');
  old[0] = strcat(old[0], str);
}

char		**append_path(char **path, char **old)
{
  int		i;
  char		*str;

  i = -1;
  if ((path == NULL) || ((str = strdup(old[0])) == NULL))
    return (NULL);
  while (path[++i] != NULL)
    {
      if (((old[0][0] == '.' && old[0][1] == '/') || (i != 0))
	  && access(old[0], F_OK) == 0)
	{
	  free(str);
	  return (old);
	}
      free(old[0]);
      if ((old[0] = malloc(strlen(path[i]) + strlen(str) + 2)) == NULL)
	{
	  free(str);
	  return (NULL);
	}
      append_them_both(str, old, path, i);
    }
  free(str);
  return ((access(old[0], F_OK) == 0) ? (old) : (NULL));
}
