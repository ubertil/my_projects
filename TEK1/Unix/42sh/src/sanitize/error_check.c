/*
** error_check.c for error_check in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May 11 14:13:01 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:21:18 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <stdio.h>
#include "shell.h"
#include "tools.h"

int		is_pipe(t_shell *shell, const char *str)
{
  int		i;

  i = -1;
  if (str == NULL)
    return (0);
  while (shell->tokens[++i] != NULL)
    if (((i == 0) || (i == 5) || (i == 6)) &&
	strcmp(shell->tokens[i], str) == 0)
      return (0);
  return (1);
}

static int	is_token(t_shell *shell, const char *str)
{
  int		i;

  i = -1;
  if (str == NULL)
    return (0);
  while (shell->tokens[++i] != NULL)
    if (i != 0 && i != 5 && i != 6 && strcmp(shell->tokens[i], str) == 0)
      return (0);
  return (1);
}

int		check_null_command(t_shell *shell, char **args)
{
  int		i;

  i = -1;
  while (args[++i] != NULL)
    {
      if ((i == 0 && is_pipe(shell, args[i]) == 0) ||
	  (is_pipe(shell, args[i]) == 0 && is_pipe(shell, args[i + 1]) == 0)
	  || (i == 0 && is_token(shell, args[i]) == 0 &&
	      is_token(shell, args[i + 1]) != 0 && args[i + 2] == NULL))
	{
	  free_args(args);
	  dprintf(2, "%s", NULL_CMD);
	  return (-1);
	}
    }
  return (0);
}

static int	check_ambigious(t_shell *shell, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL)
    {
      if ((tab[i + 1] != NULL) && (tab[i + 2] != NULL) &&
	  (strncmp(tab[i], ">", 1) == 0 && strncmp(tab[i + 2], ">", 1) == 0))
	{
	  free_args(tab);
	  dprintf(2, "%s", OUTPUT_ERR);
	  return (-1);
	}
      if (tab[i + 1] != NULL && tab[i + 2] != NULL &&
	  strncmp(tab[i], "<", 1) == 0 && strncmp(tab[i + 2], "<", 1) == 0)
	{
	  free_args(tab);
	  dprintf(2, "%s", INPUT_ERR);
	  return (-1);
	}
    }
  return (check_other_ambigious(shell, tab));
}

int	error_check(t_shell *shell, const char *buffer)
{
  int	i;
  char	**args;

  i = -1;
  if ((args = my_str_to_wordtab(buffer, " ")) == NULL)
    return (-1);
  while (args[++i] != NULL)
    {
      if ((is_token(shell, args[i]) == 0 &&
	   is_token(shell, args[i + 1]) == 0))
	{
	  free_args(args);
	  dprintf(2, "%s", MISSING_NAME);
	  return (-1);
	}
    }
  return (check_ambigious(shell, args));
}
