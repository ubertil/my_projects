/*
** show_env.c for show_env in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jan  6 20:50:07 2016 louis-emile uberti-ares
** Last update Sun Jan 24 11:12:38 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>

int		show_env(t_shell *shell)
{
  int		i;

  i = 0;
  if (shell->env != NULL)
    {
      while (shell->env[i] != NULL)
	{
	  my_putstr(shell->env[i]);
	  my_putchar('\n');
	  i += 1;
	}
      return (0);
    }
  else
    return (1);
}
