/*
** my_strcpy.c for my_strcpy in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 09:35:33 2015 louis-emile uberti-ares
** Last update Mon Feb 22 14:14:03 2016 louis-emile uberti-ares
*/

#include "../include/tetris.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  int	count;

  count = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[count] = src[i];
      count = count + 1;
      i = i + 1;
    }
  dest[count] = '\0';
  return (dest);
}
