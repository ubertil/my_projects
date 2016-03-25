/*
** getnbr_from.c for getnbr_from in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 21:55:26 2016 louis-emile uberti-ares
** Last update Fri Mar 11 16:07:01 2016 louis-emile uberti-ares
*/

#include <unistd.h>

int		getnbr_lenght(char *str, int to_start)
{
  int		lenght;

  lenght = 1;
  while (str[to_start] != '\0')
    {
      if ((str[to_start] >= '0') && (str[to_start] <= '9'))
	lenght *= 10;
      else
	return (lenght / 10);
      to_start += 1;
    }
  (lenght != 1) ? (lenght /= 10) : (0);
  return (lenght);
}

int		getnbr_from(char *str, int to_start)
{
  int		nb;
  int		lenght;

  nb = 0;
  lenght = getnbr_lenght(str, to_start);
  while (str[to_start] != '\0')
    {
      if ((str[to_start] >= '0') && (str[to_start] <= '9'))
	{
	  nb = nb + lenght * (str[to_start] - 48);
	  lenght /= 10;
	}
      else
	return (nb);
      to_start += 1;
    }
  return (nb);
}
