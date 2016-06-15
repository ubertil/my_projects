/*
** alias_command.c for alias_command in /home/grella_c/rendu/PSU_2015_42sh
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Thu Jun  2 12:01:53 2016 come grellard
** Last update Sun Jun  5 17:08:08 2016 come grellard
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "alias.h"
#include "tools.h"

static void	disp_aliases(t_shell *shell)
{
  t_alias	*tmp;

  tmp = shell->alias;
  while (tmp != NULL)
    {
      printf("%s\t%s\n", tmp->command, tmp->replace);
      tmp = tmp->next;
    }
}

static void	look_for_alias(t_shell *shell, char *alias_name)
{
  t_alias	*tmp;

  tmp = shell->alias;
  while (tmp != NULL)
    {
      if (strcmp(tmp->command, alias_name) == 0)
	{
	  printf("%s\n", tmp->replace);
	  return;
	}
      tmp = tmp->next;
    }
}

static t_alias	*add_new_alias(t_alias **alias, char *command, char *replace)
{
  t_alias	*tmp;
  t_alias	*new;

  tmp = *alias;
  while (tmp != NULL)
    {
      if (strcmp(tmp->command, command) == 0)
	{
	  tmp->replace = replace;
	  return (*alias);
	}
      tmp = tmp->next;
    }
  if (((new = malloc(sizeof(t_alias))) == NULL) ||
      ((new->command = strdup(command)) == NULL) ||
      ((new->replace = strdup(replace)) == NULL))
    return (NULL);
  new->next = *alias;
  return (new);
}

static int	alias_in_multi_args(t_shell *shell, char **args)
{
  int		i;
  char		*replace;

  i = 2;
  if ((replace = my_concat(i, args)) == NULL)
    return (-1);
  if ((shell->alias = add_new_alias(&shell->alias, args[1], replace)) == NULL)
    return (-1);
  return (0);
}

int		alias_input(t_shell *shell, char **args)
{
  if (args[1] == NULL)
    disp_aliases(shell);
  else if (args[2] == NULL)
    look_for_alias(shell, args[1]);
  else if (alias_in_multi_args(shell, args) == -1)
    return (-1);
  return (0);
}
