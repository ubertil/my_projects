/*
** to_free.c for to_free in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Jan 21 18:41:16 2016 louis-emile uberti-ares
** Last update Sun Jan 24 19:42:16 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>

int		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
  return (0);
}

int		free_all_on_exit(t_shell *shell)
{
  int		i;

  i = 0;
  if (shell->env != NULL)
    {
      while (shell->env[i] != NULL)
	{
	  free(shell->env[i]);
	  i += 1;
	}
      free(shell->env);
    }
  free(shell);
  return (0);
}

int		free_old_env(t_shell *shell)
{
  int		i;

  i = 0;
  while (shell->env[i] != NULL)
    {
      free(shell->env[i]);
      i += 1;
    }
  free(shell->env);
  return (0);
}
