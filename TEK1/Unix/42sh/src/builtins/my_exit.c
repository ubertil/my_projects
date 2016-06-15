/*
** my_exit.c for my_exit in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 03:07:25 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:09:46 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <string.h>
#include "builtins.h"
#include "shell.h"
#include "tools.h"

int		check_parenthesis(char *arg)
{
  int		i;
  int		nb_parenthesis_open;
  int		nb_parenthesis_close;

  i = 0;
  nb_parenthesis_open = 0;
  nb_parenthesis_close = 0;
  while (arg[i] != '\0' && nb_parenthesis_close <= nb_parenthesis_open)
    {
      if (arg[i] == '(')
	nb_parenthesis_open += 1;
      else if (arg[i] == ')')
	nb_parenthesis_close += 1;
      i++;
    }
  if (nb_parenthesis_open < nb_parenthesis_close)
    return (-1);
  else if (nb_parenthesis_open > nb_parenthesis_close)
    return (1);
  else
    return (0);
}

int		check_syntax(char *arg)
{
  int		i;
  int		close;
  int		chars;

  close = 0;
  chars = 0;
  i = -1;
  while (arg[++i] != '\0')
    {
      if (arg[i] != '(' && arg[i] != ')')
	chars += 1;
      if (arg[i] == ')')
	close += 1;
      if ((arg[i] == '(') && ((close != 0) || (chars != 0)))
	return (-1);
      if ((arg[i] < '0' || arg[i] > '9') && (arg[i] != '(' || arg[i] != ')')
	  && (arg[i] != '-'))
	return (-1);
    }
  return (0);
}

int		no_arg1(t_shell *shell,
			char **args)
{
  char		**tmp;
  char		**tmp2;

  if (strncmp(args[0], "exit(", 5) == 0)
    {
      tmp = my_str_to_wordtab(args[0], "(");
      if (tmp == NULL || tmp[1] == NULL)
	{
	  fprintf(stderr, "%s", EXIT_TOO_MANY_OPEN);
	  return (0);
	}
      tmp2 = my_str_to_wordtab(tmp[1], ")");
      if (tmp2 == NULL || tmp2[0] == NULL || tmp2[0][0] == '\0')
	{
	  shell->exit = 0;
	  shell->should_i_exit = 1;
	  return (0);
	}
      shell->should_i_exit = 1;
      shell->exit = (unsigned int)my_getnbr(tmp2[0]);
      return (0);
    }
  shell->exit = 0;
  shell->should_i_exit = 1;
  return (0);
}

int		my_exit(t_shell *shell, char **args)
{
  int		ret_val;

  if (args[1] == NULL)
    return (no_arg1(shell, args));
  ret_val = check_parenthesis(args[1]);
  if (ret_val == -1)
    fprintf(stderr, "%s", EXIT_TOO_MANY_CLOSE);
  else if (ret_val == 1)
    fprintf(stderr, "%s", EXIT_TOO_MANY_OPEN);
  if (ret_val == 1 || ret_val == -1)
    return (0);
  if (check_syntax(args[1]) == -1)
    {
      fprintf(stderr, "%s", EXIT_ERR_EXPRESSION);
      return (0);
    }
  shell->should_i_exit = 1;
  shell->exit = (unsigned int)my_getnbr(args[1]);
  return (0);
}
