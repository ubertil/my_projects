/*
** my_strcpy.c for my_strcpy in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 09:35:33 2015 louis-emile uberti-ares
** Last update Sat May  7 14:20:14 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "raytracer2.h"

char	*my_strcpy(char *dest, const char *src)
{
  int	i;
  int	count;

  count = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    dest[count++] = src[i++];
  dest[count] = '\0';
  return (dest);
}
