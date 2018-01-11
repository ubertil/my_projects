/*
** str_to_wordtab.c for exam in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 16:26:43 2017 alexis papadimitriou
** Last update Thu Jun 29 15:56:48 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include "common/utils/utils.h"

int		is_separator(const char c, const char *sep)
{
  int		i;

  i = 0;
  while (sep[i] != '\0' && sep[i] != c)
    i++;
  return ((sep[i] == '\0') ? (0) : (1));
}

char		*create(const char *str, uint32_t start, uint32_t end)
{
  char		*new;
  uint32_t	len;
  uint32_t	idx;

  len = end - start;
  if ((new = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  new[len] = '\0';
  idx = 0;
  while (idx < len)
    {
      new[idx] = str[start + idx];
      idx += 1;
    }
  return (new);
}

char		**fill_tab(char **new, const char *str, const char *sep)
{
  uint32_t	i;
  uint32_t	start;
  uint32_t	end;

  i = 0;
  end = 0;
  while (str[end])
    {
      while (str[end] && (is_separator(str[end], sep) == 1))
	end += 1;
      start = end;
      while (str[end] && (is_separator(str[end], sep) != 1))
	end += 1;
      if (end > start)
	{
	  if ((new[i] = create(str, start, end)) == NULL)
	    return (NULL);
	  i += 1;
	}
    }
  return (new);
}

char		**str_to_wordtab(const char *str, const char *sep)
{
  char		**new;
  uint32_t	tab_len;
  uint32_t	add;
  uint32_t	idx;

  if (str == NULL)
    return (NULL);
  idx = 0;
  tab_len = 0;
  while (str[idx])
    {
      add = 0;
      while (str[idx] && (is_separator(str[idx], sep) == 1))
	idx += 1;
      while (str[idx] && (is_separator(str[idx], sep) != 1))
	{
	  idx += 1;
	  add = 1;
	}
      tab_len += add;
    }
  if (tab_len == 0 || (new = malloc(sizeof(char *) * (tab_len + 1))) == NULL)
    return (NULL);
  new[tab_len] = NULL;
  return (fill_tab(new, str, sep));
}

void		free_wordtab(char **wordtab)
{
  uint32_t	idx;

  idx = 0;
  if (wordtab)
    {
      while (wordtab[idx])
	{
	  free(wordtab[idx]);
	  idx += 1;
	}
      free(wordtab);
      wordtab = NULL;
    }
}
