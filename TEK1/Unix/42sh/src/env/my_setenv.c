/*
** my_setenv.c for my_setenv in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 03:03:20 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:15:58 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "env.h"

static char	*load_env_line(char **args)
{
  char		*new;
  int		len;

  len = strlen(args[1]) + 2;
  if (args[2] != NULL)
    len += strlen(args[2]);
  if ((new = malloc(len)) == NULL)
    return (NULL);
  new[0] = '\0';
  if (((new = strcat(new, args[1])) == NULL) ||
      ((new = strcat(new, "=")) == NULL) ||
      (args[2] != NULL && (new = strcat(new, args[2])) == NULL))
    return (NULL);
  return (new);
}

static int	is_already_in_env(t_shell *shell, char **args)
{
  t_env		*tmp;

  tmp = shell->env;
  while (tmp != NULL)
    {
      if (strncmp(tmp->line, args[1], strlen(args[1])) == 0)
	{
	  free(tmp->line);
	  if ((tmp->line = load_env_line(args)) == NULL)
	    return (-1);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}

static int	append_to_env(t_shell *shell, char **args, t_env *new)
{
  int		ret;

  if ((ret = is_already_in_env(shell, args)) == -1)
    return (-1);
  else if (ret == 0)
    return (0);
  if ((new->line = load_env_line(args)) == NULL)
    return (-1);
  shell->env = reverse_env(shell->env);
  if ((shell->env = add_env_line(new->line, &shell->env)) == NULL)
    return (-1);
  shell->env = reverse_env(shell->env);
  return (0);
}

int		my_setenv(t_shell *shell, char **args)
{
  t_env		*new;

  if ((new = malloc(sizeof(t_env))) == NULL)
    return (0);
  new->next = NULL;
  if (args[1] == NULL)
    {
      my_env(shell, args);
      return (0);
    }
  if (args[2] != NULL && args[3] != NULL)
    {
      fprintf(stderr, "%s", SETENV_TOO_MANY_ARGS);
      return (0);
    }
  if ((args[1][0] != '_') &&
      (args[1][0] < 'A' || (args[1][0] > 'Z' && args[1][0] < 'a')
       || args[1][0] > 'z'))
    {
      fprintf(stderr, "%s", SETENV_ERR_LETTER);
      return (0);
    }
  return (append_to_env(shell, args, new));
}
