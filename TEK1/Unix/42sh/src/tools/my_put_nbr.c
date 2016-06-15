/*
** my_put_nbr.c for my_put_nbr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:41:42 2015 louis-emile uberti-ares
** Last update Tue May 31 14:47:47 2016 louis-emile uberti-ares
*/

#include <unistd.h>

void	my_put_nbr(const int nb, const int fd)
{
  int	modulo;
  int	spliter;
  char	number;

  spliter = 1;
  while ((nb / spliter) >= 10)
    spliter *= 10;
  while (spliter > 0)
    {
      modulo = ((nb / spliter) % 10);
      spliter /= 10;
      number = modulo + 48;
      write(fd, &number, 1);
    }
}
