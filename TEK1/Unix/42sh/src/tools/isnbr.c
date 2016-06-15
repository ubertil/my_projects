/*
** isnbr.c for is_nbr in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Feb 19 11:33:18 2016 louis-emile uberti-ares
** Last update Thu May  5 14:53:07 2016 louis-emile uberti-ares
*/

#include <stdlib.h>

int		is_nbr(const char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (1);
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9'))
	return (1);
      else
	++i;
    }
  return (0);
}
