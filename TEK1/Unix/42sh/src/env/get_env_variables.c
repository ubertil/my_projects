/*
** get_env_variables.c for get_env_variable in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon May 16 09:18:23 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:12:34 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "env.h"

static char	*variable_value(const char *env)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((str = malloc(strlen(env) + 1)) == NULL)
    return (NULL);
  memset(str, '\0', strlen(env));
  while (env[i] != '=' && env[i] != '\0')
    ++i;
  ++i;
  while (env[i] != '\0')
    str[j++] = env[i++];
  return (str);
}

static char	**find_env_variable(t_shell *shell, char **args, int i)
{
  int		idx;
  char		*compare;
  t_env		*tmp;

  tmp = shell->env;
  idx = -1;
  args[i] += 1;
  while (tmp != NULL)
    {
      if (strncmp(tmp->line, args[i], strlen(args[i])) == 0)
	{
	  if (((compare = variable_value(tmp->line)) == NULL) ||
	      ((args[i] = strdup(variable_value(tmp->line))) == NULL))
	    return (NULL);
	  free(compare);
	  return (args);
	}
      tmp = tmp->next;
    }
  while (args[i][++idx] != '\\' && args[i][idx] != '\0')
    dprintf(2, "%c", args[i][idx]);
  dprintf(2, "%s", NO_REF);
  args[i] -= 1;
  shell->do_nothing = 1;
  return (args);
}

char	**get_env_variable(t_shell *shell, char **args)
{
  int	i;

  i = -1;
  while (args[++i] != NULL)
    {
      if (args[i][0] == '"' && args[i][1] == '$' && args[i][2] == '"')
	{
	  dprintf(2, "%s", ILLEGAL);
	  return (args);
	}
      if (args[i][0] == '$' && args[i][i + 1] != '\0')
	if ((args = find_env_variable(shell, args, i)) == NULL)
	  return (NULL);
    }
  return (args);
}
