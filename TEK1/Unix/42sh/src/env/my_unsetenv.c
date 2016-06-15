/*
** my_unsetenv.c for my_unsetenv in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 03:06:12 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:17:03 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "env.h"

int		delete_node(t_env **head_ref, char *str)
{
  t_env		*temp;
  t_env		*prev;

  temp = *head_ref;
  if (temp != NULL && strcmp(str, temp->line) == 0)
    {
      *head_ref = temp->next;
      free(temp->line);
      free(temp);
      return (0);
    }
  while (temp != NULL && strcmp(str, temp->line) != 0)
    {
      prev = temp;
      temp = temp->next;
    }
  if (temp == NULL)
    return (0);
  prev->next = temp->next;
  free(temp->line);
  free(temp);
  return (0);
}

int		my_strlen_edit(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != '*')
    i++;
  return (i);
}

int		my_unsetenv(t_shell *shell, char **args)
{
  t_env		*tmp;
  t_env		*tmp2;

  if (args[1] == NULL)
    {
      fprintf(stderr, "%s", UNSETENV_ARGS);
      return (0);
    }
  tmp = shell->env;
  while (tmp != NULL)
    {
      tmp2 = tmp->next;
      if (strncmp(args[1], tmp->line, my_strlen_edit(args[1])) == 0)
	delete_node(&shell->env, tmp->line);
      tmp = tmp2;
    }
  return (0);
}
