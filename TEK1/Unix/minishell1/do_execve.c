/*
** do_execve.c for do_execve in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jan 20 11:47:53 2016 louis-emile uberti-ares
** Last update Sun Jan 24 20:52:34 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include "include/mysh.h"

int	do_execve(char **env, char **args)
{
  int	i;
  char	**exec;
  char	**path;

  i = 0;
  path = find_path(env);
  if (path == NULL)
    {
      my_putstr_err(args[0]);
      my_putstr(": Command not found.\n");
      return (0);
    }
  exec = get_exec(path, args[0]);
  while (exec[i] != NULL)
    {
      if (execve(exec[i], args, env) == 0)
	return (0);
      else
	i += 1;
    }
  my_putstr_err(args[0]);
  my_putstr(": Command not found.\n");
  free_tab(exec);
  free_tab(path);
  return (0);
}
