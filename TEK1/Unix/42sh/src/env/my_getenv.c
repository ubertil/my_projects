/*
** my_getenv.c for my_getenv.c in /home/trognot/rendu/PSU/PSU_2015_42sh
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Tue May 31 16:08:35 2016 nicolas trognot
** Last update Sun Jun  5 16:14:46 2016 louis-emile uberti-ares
*/

#include <string.h>
#include "env.h"
#include "tools.h"
#include "shell.h"

char		*my_getenv(t_shell *shell, char *name)
{
  t_env		*tmp;
  char		**tab;
  char		*path;

  tmp = shell->env;
  while (tmp != NULL)
    {
      if (strncmp(tmp->line, name, strlen(name)) == 0)
	{
	  if (((tab = my_str_to_wordtab(tmp->line, "=")) == NULL) ||
	      (tab[1] == NULL) || ((path = strdup(tab[1])) == NULL))
	    return (NULL);
	  free_args(tab);
	  return (path);
	}
      tmp = tmp->next;
    }
  return (NULL);
}
