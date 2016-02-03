/*
** main.c for main in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Jan  4 12:50:53 2016 louis-emile uberti-ares
** Last update Sun Jan 24 23:09:17 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void		init_check(t_check *check)
{
  check[0].str = "env";
  check[0].func = &show_env;
  check[1].str = "setenv";
  check[1].func = &my_setenv;
  check[2].str = "unsetenv";
  check[2].func = &my_unsetenv;
  check[3].str = "cd";
  check[3].func = &my_cd;
}

int		my_core(t_shell *shell, t_check *check)
{
  int		i;

  i = 0;
  signal(SIGINT, signal_sigint);
  while (i == 0)
    {
      my_putstr("$> ");
      shell->buffer = get_next_line(0);
      if (shell->buffer == NULL)
	return (0);
      else
	{
	  i = check_buffer(shell, check);
	  free(shell->buffer);
	}
      if (i != 0)
	{
	  if (i == 1)
	    return (0);
	  return (i);
	}
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_shell	*shell;
  t_check	check[4];
  int		return_value;

  if ((shell = malloc(sizeof(t_shell))) == NULL)
    return (1);
  if (env[0] != NULL)
    copy_env(shell, env);
  shell->status = 0;
  init_check(check);
  return_value = my_core(shell, check);
  (void)ac;
  (void)av;
  my_putstr("exit\n");
  free_all_on_exit(shell);
  return (return_value);
}
