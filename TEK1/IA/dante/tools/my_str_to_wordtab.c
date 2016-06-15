/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/trogno_n/rendu/CPE_colle_semaine4
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Wed May 18 20:01:17 2016 nicolas trognot
** Last update Wed May 18 22:44:56 2016 nicolas trognot
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	get_nb_of_word(const char *str)
{
  int		nb;
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  nb = 1;
  while (str[i])
    {
      if (((str[i] == '\n')) &&
	  ((str[i + 1] != '\0') && (str[i + 1] != '\n')))
	nb++;
      i++;
    }
  return (nb);
}

static void	fill_ret(char **ret, const char *str, int nb,
			 int i)
{
  int		a;

  a = 0;
  while (str[i])
    {
      if (((str[i] == '\n')) &&
	  ((str[i + 1] != '\0') && (str[i + 1] != '\n')))
	{
	  ret[nb][a] = '\0';
	  a = 0;
	  nb++;
	}
      else if (str[i] != '\n')
	{
	  ret[nb][a] = str[i];
	  a++;
	}
      i++;
    }
  ret[nb][a] = '\0';
}

char		**my_str_to_wordtab(const char *str)
{
  char		**ret;
  int		i;

  if ((ret = malloc(sizeof(char *) * (get_nb_of_word(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < get_nb_of_word(str))
    {
      if ((ret[i] = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
	return (NULL);
      i++;
    }
  fill_ret(ret, str, 0, 0);
  ret[i] = NULL;
  return (ret);
}
