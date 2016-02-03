/*
** change_env_line.c for change_env_line in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Jan 24 20:23:57 2016 louis-emile uberti-ares
** Last update Sun Jan 24 20:52:50 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>

char	**change_line(char **env, char **args, int line)
{
  int	i;
  int	idx;

  idx = 0;
  i = 0;
  free(env[line]);
  if ((env[line] = malloc(my_strlen(args[1]) + my_strlen(args[2]) + 2)) == NULL)
    exit(84);
  while (args[1][i] != '\0')
    {
      env[line][idx] = args[1][i];
      i += 1;
      idx += 1;
    }
  env[line][idx] = '=';
  idx += 1;
  i = 0;
  while (args[2][i] != '\0')
    {
      env[line][idx] = args[2][i];
      idx += 1;
      i += 1;
    }
  env[line][idx] = '\0';
  return (env);
}

int	change_env_line(t_shell *shell, char **args, int line)
{
  char	**new;

  new = my_tab_to_tab(shell->env);
  new = change_line(new, args, line);
  free_old_env(shell);
  copy_env(shell, new);
  return (0);
}
