/*
** my_echo.c for my_echo in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 12 03:09:30 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:54:21 2016 come grellard
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "tools.h"

static int	check_quotes(const char *str)
{
  int		i;
  int		cpt_quote;

  i = 0;
  cpt_quote = 0;
  while  (str[i] != '\0')
    {
      if (str[i] == '"')
	cpt_quote += 1;
      i += 1;
    }
  if (cpt_quote % 2 != 0)
    {
      fprintf(stderr, "Unmatched %c.\n", '"');
      return (-1);
    }
  return (0);
}

static int	display_backslashes(const char *str, int i)
{
  int		cpt;
  char		*name;
  char		*content;

  name = "\\abefnrtv";
  content = "\\\a\b\e\f\n\r\t\v";
  cpt = -1;
  while (name[++cpt] != '\0')
    if (str[i + 1] == name[cpt])
      {
	write(1, &content[cpt], 1);
	i += 1;
      }
  if (cpt == 10)
    write(1, "\\", 1);
  return (i);
}

static int	display_str(const char *str)
{
  int		i;
  int		check;

  i = -1;
  check = 0;
  if (check_quotes(str) == -1)
    return (1);
  while (str[++i] != '\0')
    {
      if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
	return (1);
      if (str[i] == '"')
	(check == 0) ? (check = 1) : (check = 0);
      else if (str[i] == '\\')
	{
	  if (check == 1)
	    i = display_backslashes(str, i);
	}
      else
	write(1, &str[i], 1);
    }
  return (0);
}

int		my_echo(t_shell *shell, char **args)
{
  int		mem;
  char		*str;

  (args[1] != NULL && strcmp(args[1], "-n") == 0) ? (mem = 2) : (mem = 1);
  if (((args = find_globings(args)) == NULL) ||
      ((str = my_concat(mem, args)) == NULL))
    return (-1);
  if (str != NULL && display_str(str) == 1)
    return (0);
  if (args[1] == NULL || strcmp(args[1], "-n") != 0)
    my_putstr("\n");
  (void)shell;
  return (0);
}
