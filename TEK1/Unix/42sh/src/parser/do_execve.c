/*
** do_execve.c for do_execve in /home/uberti_l/rendu/Unix/PSU_2015_minishell2/srcs
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr  6 12:00:22 2016 louis-emile uberti-ares
** Last update Sun Jun  5 23:39:18 2016 alexis papadimitriou
*/

#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "env.h"
#include "tools.h"
#include "alias.h"

static int	father(t_shell *shell)
{
  if (shell->command_name != NULL)
    free(shell->command_name);
  shell->command_name = NULL;
  shell->nb_children += 1;
  return (0);
}

static int	son(t_shell *shell, char **args)
{
  int		i;
  char		**env;

  i = -1;
  if ((env = get_tab_env(shell->env)) == NULL)
    return (-1);
  while (args[0][++i] != '\0')
    if (args[0][i] == '/' && args[0][i + 1] == '/')
      {
	printf("%s: Command not found.\n", shell->command_name);
	free(shell->command_name);
	shell->command_name = NULL;
	return (-1);
      }
  i = 0;
  if (shell->command_name[0] == '.' && shell->command_name[1] == '/')
    execve(shell->command_name, &shell->command_name, env);
  else
    while (args[i] != NULL)
      execve(args[i++], args, env);
  printf("%s: Command not found.\n", shell->command_name);
  free(shell->command_name);
  shell->command_name = NULL;
  return (-1);
}

static int	fork_and_exec(t_shell *shell, char **args, char **path)
{
  pid_t		p;

  if ((shell->command_name[0] != '.' || shell->command_name[1] != '/') &&
      path == NULL)
    {
      printf("%s: Command not found.\n", shell->command_name);
      return (0);
    }
  if (path != NULL)
    free_args(path);
  p = fork();
  if (p == 0)
    return (son(shell, args));
  else if (p != -1)
    return (father(shell));
  else
    {
      dprintf(2, "%s", FORK_FAIL);
      return (-1);
    }
}

int	do_execve(t_shell *shell, char **args)
{
  int	i;
  char	*str;
  char	**path;
  char	**new;

  i = -1;
  if (strncmp(shell->builtins[5].cmd, args[0],
	      strlen(shell->builtins[5].cmd)) == 0)
    return (shell->builtins[5].builtin(shell, args));
  if (((args = get_env_variable(shell, args)) == NULL) ||
      ((args = alias_to_command(shell, args)) == NULL) ||
      ((shell->command_name = strdup(args[0])) == NULL))
    return (-1);
  while (++i < 8)
    if (strcmp(shell->builtins[i].cmd, args[0]) == 0)
      return (shell->builtins[i].builtin(shell, args));
  str = my_getenv(shell, "PATH");
  if (((args = find_globings(args)) == NULL) ||
      ((path = my_str_to_wordtab(str, ":")) == NULL) ||
      ((new = append_path(path, args)) == NULL))
    return (fork_and_exec(shell, args, path));
  (str != NULL) ? (free(str)) : (0);
  return ((shell->do_nothing == 0) ? (fork_and_exec(shell, new, path)) : (0));
}
