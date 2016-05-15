/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/uberti_l/source_files/lib/my/src
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jan 19 22:18:50 2016 louis-emile uberti-ares
** Last update Mon Apr 25 21:07:42 2016 louis-emile uberti-ares
*/

#include <stdlib.h>

int		nbwords(char *str)
{
  int		i;
  int		nb_words;

  i = 0;
  nb_words = 0;
  while (str[i] != '\0')
    {
      while (str[i] == ' ' || str[i] == '\t')
	i += 1;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	i += 1;
      while (str[i] == ' ' || str[i] == '\t')
	i += 1;
      nb_words += 1;
    }
  return (nb_words);
}

int		*get_lenght(char *str, int *lenght)
{
  int		i;
  int		idx;

  i = 0;
  idx = 0;
  while (str[i] != '\0')
    {
      lenght[idx] = 0;
      while (str[i] == ' ' || str[i] == '\t')
	i += 1;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
	  lenght[idx] += 1;
	  i += 1;
	}
      while (str[i] == ' ' || str[i] == '\t')
	i += 1;
      idx += 1;
    }
  return (lenght);
}

char		**malloc_tab(char **tab, int *lenght, int nb_words)
{
  int		i;
  int		idx;

  i = 0;
  idx = 0;
  while (i < nb_words)
    {
      if ((tab[idx] = malloc(lenght[idx] + 1)) == NULL)
	return (NULL);
      tab[idx][lenght[idx]] = '\0';
      idx += 1;
      i += 1;
    }
  tab[nb_words] = NULL;
  return (tab);
}

char		**get_tab(char **tab, char *str, int i)
{
  int		j;
  int		idx;

  idx = 0;
  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (str[i] == ' ' || str[i] == '\t')
	i += 1;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
	  tab[idx][j++] = str[i];
	  i += 1;
	}
      while (str[i] == ' ' || str[i] == '\t')
	i += 1;
      idx += 1;
    }
  return (tab);
}

char		**my_str_to_wordtab(char *str)
{
  int		*lenght;
  char		**tab;
  int		i;
  int		nb_words;

  i = 0;
  if (str == NULL)
    return (NULL);
  nb_words = nbwords(str);
  if (((tab = malloc(sizeof(char *) * (nb_words + 1))) == NULL) ||
      ((lenght = malloc(sizeof(int) * nb_words)) == NULL))
    return (NULL);
  lenght = get_lenght(str, lenght);
  if ((tab = malloc_tab(tab, lenght, nb_words)) == NULL)
    return (NULL);
  tab = get_tab(tab, str, i);
  free(lenght);
  return (tab);
}
