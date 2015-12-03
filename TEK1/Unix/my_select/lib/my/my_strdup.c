/*
** my_strdup.c for my_strdup in /home/uberti_l/rendu/Piscine_C_J08/ex_01
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 09:20:24 2015 louis-emile uberti-ares
** Last update Wed Nov  4 11:53:07 2015 louis-emile uberti-ares
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	lenght;
  int	i;
  char	*dest;

  lenght = 0;
  i = 0;
  while (src[lenght] != '\0')
    lenght = lenght + 1;
  dest = malloc(lenght + 1);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
