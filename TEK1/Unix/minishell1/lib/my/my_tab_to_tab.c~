/*
** my_tab_to_tab.c for my_tab_to_tab in /home/uberti_l
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jan 20 21:40:01 2016 louis-emile uberti-ares
** Last update Wed Jan 20 21:46:54 2016 louis-emile uberti-ares
*/

#include <stdlib.h>

char		**fill_lines(char **tab, char **new)
{
  int		i;

  i = -1;
  while (tab[i += 1] != NULL)
    new[i] = my_strdup(tab[i]);
  new[i] = NULL;
  return (new);
}

char		**malloc_lines(char **tab, char **new)
{
  int		lenght;
  int		i;
  int		j;

  lenght = 1;
  i = 0;
  j = -1;
  while (tab[i] != NULL)
    {
      while (tab[i][j += 1] != '\0')
	lenght += 1;
      if ((new[i] = malloc(lenght)) == NULL)
	exit(84);
      i += 1;
      j = -1;
    }
  return (new);
}

char		**my_tab_to_tab(char **tab)
{
  int		i;
  char		**new;

  if (tab[0] == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    i += 1;
  if ((new = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  new = malloc_lines(tab, new);
  new = fill_lines(tab, new);
  return (tab);
}
