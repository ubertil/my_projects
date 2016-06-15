/*
** ambigious_checker.c for ambigious_checker in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Jun  4 15:32:55 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:20:24 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "tools.h"

int		check_ambigious_pipe(t_shell *shell, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    {
      if (tab[i + 1] != NULL && tab[i + 2] != NULL &&
	  strncmp(tab[i], ">", 1) == 0 && strncmp(tab[i + 2], "|", 1) == 0)
	{
	  free_args(tab);
	  dprintf(2, "%s", OUTPUT_ERR);
	  return (-1);
	}
      if (tab[i + 1] != NULL && tab[i + 2] != NULL &&
	  strncmp(tab[i], "<", 1) == 0 && strncmp(tab[i + 2], "|", 1) == 0)
	{
	  free_args(tab);
	  dprintf(2, "%s", INPUT_ERR);
	  return (-1);
	}
    }
  return (check_null_command(shell, tab));
}

int		check_other_ambigious(t_shell *shell, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    {
      if (tab[i + 1] != NULL && tab[i + 2] != NULL &&
	  strncmp(tab[i], ">", 1) == 0 && strncmp(tab[i + 2], "<", 1) == 0)
	{
	  free_args(tab);
	  dprintf(2, "%s", OUTPUT_ERR);
	  return (-1);
	}
      if (tab[i + 1] != NULL && tab[i + 2] != NULL &&
	  strncmp(tab[i], "<", 1) == 0 && strncmp(tab[i + 2], ">", 1) == 0)
	{
	  free_args(tab);
	  dprintf(2, "%s", INPUT_ERR);
	  return (-1);
	}
    }
  return (check_ambigious_pipe(shell, tab));
}
