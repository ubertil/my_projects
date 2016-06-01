/*
** my_put_nbr.c for my_put_nbr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:41:42 2015 louis-emile uberti-ares
** Last update Tue May  3 23:23:02 2016 louis-emile uberti-ares
*/

#include <unistd.h>

void	my_put_nbr(int nb)
{
  int	modulo;
  int	spliter;
  char	letter[2];

  spliter = 1;
  if (nb < 0)
    {
      write(1, "-", 1);
      nb *= -1;
    }
  while ((nb / spliter) >= 10)
    spliter *= 10;
  while (spliter > 0)
    {
      modulo = ((nb / spliter) %10);
      spliter /= 10;
      letter[0] = modulo + 48;
      write(1, letter, 1);
    }
}
