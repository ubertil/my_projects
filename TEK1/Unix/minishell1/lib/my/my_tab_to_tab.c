/*
** my_tab_to_tab.c for my_tab_to_tab in /home/uberti_l
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jan 20 21:40:01 2016 louis-emile uberti-ares
** Last update Sun Jan 24 20:45:17 2016 louis-emile uberti-ares
*/

#include "../../include/mysh.h"
#include <stdlib.h>

char		**my_tab_to_tab(char **tab)
{
  int		i;
  char		**new;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  if ((new = malloc(sizeof(char *) * (i + 1))) == NULL)
    exit(84);
  i = 0;
  while (tab[i] != NULL)
    {
      if ((new[i] = malloc(my_strlen(tab[i]) + 1)) == NULL)
	exit(84);
      new[i] = my_strcpy(new[i], tab[i]);
      i += 1;
    }
  new[i] = NULL;
  return (new);
}
