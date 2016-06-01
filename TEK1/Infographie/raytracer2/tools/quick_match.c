/*
** quick_match.c for quick_match in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Mar  4 13:04:08 2016 louis-emile uberti-ares
** Last update Wed May  4 00:08:18 2016 louis-emile uberti-ares
*/

#include <stdlib.h>

int		quick_match(char *str1, char *str2)
{
  int		i;
  int		j;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (1);
  while (str1[i] != '\0')
    {
      j = 0;
      if (str1[i] == str2[j])
	{
	  while (str2[j] != '\0' && str1[i] == str2[j])
	    {
	      i += 1;
	      j += 1;
	    }
	  if (str2[j] == '\0' && str1[i] == '\0')
	    return (0);
	}
      i += 1;
    }
  return (1);
}
