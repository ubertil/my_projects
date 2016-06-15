/*
** get_tab_env.c for get_tab_env in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May 11 17:09:31 2016 louis-emile uberti-ares
** Last update Mon May 30 16:13:17 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <string.h>
#include "env.h"

char		**get_tab_env(t_env *env)
{
  t_env		*tmp;
  char		**tab;
  int		size;

  tmp = env;
  size = 0;
  while (tmp != NULL)
    {
      ++size;
      tmp = tmp->next;
    }
  tmp = env;
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  size = 0;
  while (tmp != NULL)
    {
      if ((tab[size++] = strdup(tmp->line)) == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  tab[size] = NULL;
  return (tab);
}
