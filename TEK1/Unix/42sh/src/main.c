/*
** main.c for main in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May  5 14:45:35 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:02:16 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "tokens.h"
#include "env.h"
#include "history.h"
#include "builtins.h"
#include "tools.h"

static int	do_command(t_shell *shell, char *buffer)
{
  int		i;
  char		**args;

  i = -1;
  if ((is_space(buffer) == 1) || (error_check(shell, buffer) == -1))
    {
      free(buffer);
      return (0);
    }
  if ((args = my_str_to_wordtab(buffer, ";")) == NULL)
    return (-1);
  while (args != NULL && args[++i] != NULL)
    {
      if (((shell->tree = malloc(sizeof(t_tree))) == NULL) ||
	  ((shell->tree->up = NULL) != NULL) ||
	  (fill_tree(shell, args[i]) == -1) ||
	  (start_parser(shell) == -1))
	return (-1);
      if (shell->should_i_exit != 0)
	return (shell->exit);
      free_tree(shell->tree);
    }
  free(buffer);
  (args != NULL) ? (free_args(args)) : (0);
  return (0);
}

static int	sh_core(t_shell *shell)
{
  int		ret;
  char		*buffer;

  while (shell->should_i_exit == 0)
    {
      if ((aff_prompt() == -1))
	return (-1);
      if ((buffer = get_shell_line(0)) == NULL)
	{
	  shell->should_i_exit = 1;
	  return (0);
	}
      if (((add_line_to_history(shell, buffer)) == -1) ||
	  ((buffer = sanitize_command(buffer, shell)) == NULL) ||
	  ((ret = do_command(shell, buffer)) == -1))
	return (ret);
    }
  return (0);
}

static int	init_struct(t_shell *shell)
{
  init_parsing_tab(shell->tk_parsing);
  shell->exit = 0;
  shell->erased = 1;
  shell->should_i_exit = 0;
  shell->do_nothing = 0;
  shell->tree = NULL;
  shell->alias = NULL;
  shell->command_name = NULL;
  shell->nb_line = -1;
  shell->fd_tab = NULL;
  shell->nb_children = 0;
  if ((shell->base_in_out[0] = dup(0)) == -1 ||
      (shell->base_in_out[1] = dup(1)) == -1)
    {
      dprintf(2, "%s", DUP_FAIL);
      return (-1);
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  int		ret;
  t_shell	*shell;

  if (((shell = malloc(sizeof(t_shell))) == NULL) ||
      (copy_env(shell, env) == -1) || (init_tokens(shell) == -1) ||
      (init_signals() == 1) || (init_builtins(shell)) ||
      (find_hist_place(shell) == -1) || init_struct(shell) == -1)
    return (-1);
  sh_core(shell);
  ret = shell->exit;
  (shell->should_i_exit != 0) ? (printf("exit\n")) : (0);
  free_all(shell);
  (void)ac;
  (void)av;
  return (ret);
}
