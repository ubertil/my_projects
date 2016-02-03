/*
** get_start.c for get_start.c in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jan  5 16:32:35 2016 louis-emile uberti-ares
** Last update Sun Jan 24 19:37:59 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>

int		my_exit(char **args)
{
  int		ret;

  if (args[1] == NULL)
    return (1);
  else
    ret = my_getnbr(args[1]);
  return (ret);
}

int		copy_env(t_shell *shell, char **env)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    i += 1;
  shell->env_row = i;
  if ((shell->env = malloc(sizeof(char *) * (i + 1))) == NULL)
    exit(84);
  i = 0;
  while (env[i] != NULL)
    {
      if ((shell->env[i] = malloc(my_strlen(env[i]) + 1)) == NULL)
	exit(84);
      shell->env[i] = my_strcpy(shell->env[i], env[i]);
      i += 1;
    }
  shell->env[i] = NULL;
  return (0);
}

int		check_easy(char **args)
{
  if (my_strcmp(args[0], "help") == 0)
    {
      display_help();
      return (0);
    }
  return (1);
}

int		check_buffer(t_shell *shell, t_check *check)
{
  int		i;
  int		ret;
  char		**args;

  if (my_strcmp(shell->buffer, "") == 0)
    return (0);
  args = my_str_to_wordtab(shell->buffer);
  if (my_strcmp(args[0], "exit") == 0)
    {
      ret = my_exit(args);
      free_tab(args);
      return (ret);
    }
  if (check_easy(args) == 0)
    return (0);
  i = 0;
  while ((my_strcmp(check[i].str, args[0]) != 0) && (i <= 3))
    i += 1;
  if (i < 4)
    check[i].func(shell);
  else
    fork_handler(shell, args);
  free_tab(args);
  return (0);
}
