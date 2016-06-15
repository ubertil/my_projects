/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/uberti_l/source_files/lib/my/src
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jan 19 22:18:50 2016 louis-emile uberti-ares
** Last update Wed May 11 12:23:47 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "tools.h"

static int	nbwords(const char *str, const char *sep)
{
  int		i;
  int		nb_words;

  i = 0;
  nb_words = 0;
  while (str[i] != '\0')
    {
      while (is_separator(sep, str[i]) == 0)
	++i;
      while (is_separator(sep, str[i]) == 1 && str[i] != '\0')
	++i;
      while (is_separator(sep, str[i]) == 0)
	++i;
      nb_words += 1;
    }
  return (nb_words);
}

static int		*get_lenght(const char *str, const char *sep,
				    int *lenght)
{
  int		i;
  int		idx;

  i = 0;
  idx = 0;
  while (str[i] != '\0')
    {
      lenght[idx] = 0;
      while (is_separator(sep, str[i]) == 0)
	++i;
      while (is_separator(sep, str[i]) == 1 && str[i] != '\0')
	{
	  lenght[idx] += 1;
	  ++i;
	}
      while (is_separator(sep, str[i]) == 0)
	++i;
      ++idx;
    }
  return (lenght);
}

static char	**malloc_tab(char **tab, int *lenght, int nb_words)
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
      ++idx;
      ++i;
    }
  tab[nb_words] = NULL;
  return (tab);
}

static char	**get_tab(char **tab, const char *str,
			  const char *sep, int i)
{
  int		j;
  int		idx;

  idx = 0;
  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (is_separator(sep, str[i]) == 0)
	++i;
      while (is_separator(sep, str[i]) == 1 && str[i] != '\0')
	{
	  tab[idx][j++] = str[i];
	  ++i;
	}
      while (is_separator(sep, str[i]) == 0)
	++i;
      ++idx;;
    }
  return (tab);
}

char		**my_str_to_wordtab(const char *str, const char *sep)
{
  int		*lenght;
  char		**tab;
  int		i;
  int		nb_words;

  i = 0;
  if (str == NULL || sep == NULL)
    return (NULL);
  nb_words = nbwords(str, sep);
  if ((nb_words == 0) ||
      ((tab = malloc(sizeof(char *) * (nb_words + 1))) == NULL) ||
      ((lenght = malloc(sizeof(int) * nb_words)) == NULL))
    return (NULL);
  lenght = get_lenght(str, sep, lenght);
  tab = malloc_tab(tab, lenght, nb_words);
  tab = get_tab(tab, str, sep, i);
  free(lenght);
  return (tab);
}
