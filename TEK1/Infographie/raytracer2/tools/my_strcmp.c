/*
** my_strcmp.c for my_strcmp in /home/uberti_l/day06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 20:05:55 2015 louis-emile uberti-ares
** Last update Mon May  9 14:12:29 2016 louis-emile uberti-ares
*/

#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[i] == s2[i])
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      ++i;
    }
  return (1);
}
