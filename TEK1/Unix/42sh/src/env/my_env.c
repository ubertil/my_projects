/*
** my_env.c for my_env in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 03:04:59 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:13:51 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#include "env.h"

static void	disp_env(t_shell *shell)
{
  t_env		*tmp;

  tmp = shell->env;
  while (tmp != NULL)
    {
      printf("%s\n", tmp->line);
      tmp = tmp->next;
    }
}

static int	prepare_for_exec(t_shell *shell, char **args, int i)
{
  char		**command;
  int		len;
  int		idx;

  len = 0;
  idx = 0;
  while (args[len] != NULL)
    len += 1;
  if ((command = malloc(sizeof(char *) * (len - i + 1))) == NULL)
    return (-1);
  while (args[i] != NULL)
    command[idx++] = args[i++];
  command[idx] = NULL;
  if (do_execve(shell, command) == -1)
    return (-1);
  return (0);
}

int		my_env(t_shell *shell, char **args)
{
  t_env		*mem;
  int		i;

  mem = shell->env;
  i = 1;
  if (args[1] != NULL && strcmp(args[1], "-i") == 0)
    {
      shell->env = NULL;
      i = 2;
    }
  if (args[i] == NULL)
    disp_env(shell);
  else if (prepare_for_exec(shell, args, i) == -1)
    return (-1);
  shell->env = mem;
  return (0);
}
