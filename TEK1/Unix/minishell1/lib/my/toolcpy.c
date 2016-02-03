/*
** toolcpy.c for toolcpy in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Jan 24 21:42:28 2016 louis-emile uberti-ares
** Last update Sun Jan 24 21:43:51 2016 louis-emile uberti-ares
*/

#include "../../include/mysh.h"

char	*toolcpy(char *dest, char *src)
{
  int	i;
  int	j;

  j = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      i += 1;
      j += 1;
    }
  dest[j] = '\0';
  return (dest);
}
