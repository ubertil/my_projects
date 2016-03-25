/*
** my_dupkey.c for dupkey in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Mar 18 15:12:14 2016 Louis-Emile Uberti
** Last update Fri Mar 18 16:06:45 2016 Louis-Emile Uberti
*/

#include <stdio.h>
#include <stdlib.h>

int	keylenght(char *str)
{
  int	lenght;
  int	i;

  i = 0;
  lenght = 1;
  while (str[i - 1] != '=')
    i += 1;
  while (str[i] != '\0')
    {
      i += 1;
      lenght += 1;
    }
  return (lenght);
}

char	*dupkey(char *str)
{
  char	*key;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((key = malloc(keylenght(str) + 1)) == NULL)
    return (NULL);
  while (str[i - 1] != '=')
    i += 1;
  while (str[i] != '\0')
    key[j++] = str[i++];
  key[j] = '\0';
  return (key);
}
