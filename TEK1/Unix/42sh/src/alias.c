/*
** alias.c for alias in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon May 23 16:43:32 2016 louis-emile uberti-ares
** Last update Sun Jun  5 15:55:04 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "alias.h"
#include "shell.h"

static char	**add_alias_command(char **args, char *str, const int i)
{
  char		**tab;
  char		**new;
  int		tmp;
  int		j;

  if (((tab = my_str_to_wordtab(str, " ")) == NULL) || (tab[0] == NULL) ||
      ((new = malloc(sizeof(char *) *
		     (args_size(args) + args_size(tab) + 1))) == NULL))
    return (NULL);
  tmp = -1;
  while (++tmp < i)
    new[tmp] = strdup(args[tmp]);
  j = -1;
  while (tab[++j] != NULL)
    new[tmp++] = strdup(tab[j]);
  j = i;
  while (args[++j] != NULL)
    new[tmp++] = strdup(args[j]);
  new[tmp] = NULL;
  free_args(tab);
  return (new);
}

char		**alias_to_command(t_shell *shell, char **args)
{
  int		i;
  char		**new;
  t_alias	*tmp;

  i = -1;
  new = args;
  if (shell->alias != NULL)
    {
      while (args[++i] != NULL)
	{
	  tmp = shell->alias;
	  while (tmp != NULL)
	    {
	      if (strcmp(tmp->command, args[i]) == 0)
		{
		  if ((new =
		       add_alias_command(args, tmp->replace, i)) == NULL)
		    return (NULL);
		}
	      tmp = tmp->next;
	    }
	}
    }
  return (new);
}
