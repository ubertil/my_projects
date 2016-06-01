/*
** my_strdup.c for my_strdup in /home/uberti_l/rendu/Piscine_C_J08/ex_01
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 09:20:24 2015 louis-emile uberti-ares
** Last update Mon May  9 11:56:17 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

char	*my_strdup(const char *src)
{
  int	i;
  char	*dest;

  i = 0;
  if (src == NULL)
    return (NULL);
  if ((dest = bunny_malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
