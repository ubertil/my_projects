/*
** free_env.c for free_env in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May  6 12:29:51 2016 louis-emile uberti-ares
** Last update Fri May  6 12:43:25 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "env.h"

int		free_env(t_env *env)
{
  t_env		*curr;

  while ((curr = env) != NULL)
    {
      env = env->next;
      free(curr->line);
      free(curr);
    }
  return (0);
}
