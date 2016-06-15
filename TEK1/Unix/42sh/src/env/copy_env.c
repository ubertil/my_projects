/*
** copy_env.c for copy_env in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May  5 15:05:06 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:11:49 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "env.h"
#include "tools.h"

t_env			*reverse_env(t_env *root)
{
  t_env			*new_root;
  t_env			*next;

  new_root = NULL;
  while (root != NULL)
    {
      next = root->next;
      root->next = new_root;
      new_root = root;
      root = next;
    }
  return (new_root);
}

t_env			*add_env_line(const char *str, t_env **old)
{
  t_env			*env;

  if (((env = malloc(sizeof(t_env))) == NULL) ||
      ((env->line = strdup(str)) == NULL))
    return (NULL);
  env->next = *old;
  return (env);
}

int		copy_env(t_shell *sh, char **env)
{
  int		i;

  i = -1;
  sh->env = NULL;
  if (env != NULL)
    {
      while (env[++i])
	if ((sh->env = add_env_line(env[i], &sh->env)) == NULL)
	  {
	    fprintf(stderr, "%s", ERR_CREAT);
	    return (-1);
	  }
      sh->env = reverse_env(sh->env);
    }
  return (0);
}
