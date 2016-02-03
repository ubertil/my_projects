/*
** fork_handler.c for fork_handler.c in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jan  5 16:39:21 2016 louis-emile uberti-ares
** Last update Sun Jan 24 23:10:14 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

char		**fill_exec(char **exec, char **path, char *todo, int i)
{
  int		j;
  int		idx;

  j = 0;
  idx = -1;
  while (path[i] != NULL)
    {
      while (path[i][j] != '\0')
	{
	  exec[i][j] = path[i][j];
	  j += 1;
	}
      exec[i][j] = '/';
      j += 1;
      while (todo[idx += 1] != '\0')
	{
	  exec[i][j] = todo[idx];
	  j += 1;
	}
      exec[i][j] = '\0';
      i += 1;
      idx = -1;
      j = 0;
    }
  return (exec);
}

char		**get_exec(char **path, char *todo)
{
  char		**exec;
  int		i;
  int		size;

  size = 0;
  while (path[size] != NULL)
    size += 1;
  if ((exec = malloc(sizeof(char *) * (size + 1))) == NULL)
    exit(84);
  size = 0;
  i = 0;
  while (path[i] != NULL)
    {
      while (path[i][size] != '\0')
	size += 1;
      if ((exec[i] = malloc(size + 2 + my_strlen(todo))) == NULL)
	exit(84);
      size = 0;
      i += 1;
    }
  exec[i] = NULL;
  i = 0;
  exec = fill_exec(exec, path, todo, i);
  return (exec);
}


char		**find_path(char **env)
{
  int		i;
  char		**path;

  i = 0;
  if (env == NULL)
    return (NULL);
  while ((unstrict_cmp(env[i], "PATH=") != 0) && (env[i + 1] != NULL))
    i += 1;
  if (unstrict_cmp(env[i], "PATH=") == 0)
    path = my_path_to_wordtab(env[i]);
  else
    path = NULL;
  return (path);
}

void		fork_handler(t_shell *shell, char **args)
{
  pid_t		p;

  p = fork();
  if (p == 0)
    {
      if (execve(args[0], args, shell->env) == -1)
	{
	  if (shell->env == NULL)
	    {
	      my_putstr_err(args[0]);
	      my_putstr_err(": Command not found.\n");
	      exit(0);
	    }
	  do_execve(shell->env, args);
	}
      exit(0);
    }
  else if (p != -1)
    {
      waitpid(0, &shell->status, 0);
    }
  else
    my_putstr_err("FATAL ERROR : Fork failed\n");
}
