/*
** my_cd.c for my_cd in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 03:02:25 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:07:20 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "builtins.h"
#include "env.h"
#include "tools.h"

char		*get_current_path(void)
{
  char		*path;
  int		i;

  i = 1;
  if ((path = malloc(i)) == NULL)
    return (NULL);
  while (getcwd(path, i++) == NULL)
    {
      free(path);
      if ((path = malloc(i)) == NULL)
	return (NULL);
    }
  return (path);
}

static char	**memorize_old_pwd(void)
{
  char		**old;

  if ((old = malloc(sizeof(char *) * 4)) == NULL)
    return (NULL);
  if (((old[0] = strdup("setenv")) == NULL) ||
      ((old[1] = strdup("OLDPWD")) == NULL) ||
      ((old[2] = get_current_path()) == NULL))
    return (NULL);
  old[3] = NULL;
  return (old);
}

static int	move_into_path(t_shell *shell, const char *path)
{
  char		**old;

  if ((old = memorize_old_pwd()) == NULL)
    return (-1);
  if (path == NULL || path[0] == '\0')
    return (0);
  if (chdir(path) == -1)
    {
      fprintf(stderr, "%s", path);
      if (access(path, F_OK) == -1)
	fprintf(stderr, "%s", CD_ERR_NO_FILE);
      else if (access(path, R_OK) == -1)
	fprintf(stderr, "%s", CD_PERMISSION_DENIED);
      return (1);
    }
  if (my_setenv(shell, old) == -1)
    return (-1);
  free_args(old);
  return (0);
}

int		my_cd(t_shell *shell, char **args)
{
  char		*path;

  path = NULL;
  if (args[1] == NULL)
    path = my_getenv(shell, "HOME");
  else if ((args[2] == NULL) && (strcmp(args[1], "-") == 0))
    path = my_getenv(shell, "OLDPWD");
  else if (args[2] == NULL)
    {
      if ((path = strdup(args[1])) == NULL)
	return (-1);
    }
  else
    {
      fprintf(stderr, "%s", CD_TOO_MANY);
      return (0);
    }
  if (move_into_path(shell, path) == -1)
    return (-1);
  (path != NULL) ? (free(path)) : (0);
  return (0);
}
