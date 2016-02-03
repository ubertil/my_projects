/*
** my_put_nbr.c for my_put_nbr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:41:42 2015 louis-emile uberti-ares
** Last update Tue Feb  2 16:58:21 2016 louis-emile uberti-ares
*/

#include "../server/include/server.h"

int	my_put_nbr(int nb)
{
  int	modulo;
  int	spliter;

  spliter = 1;
  while ((nb / spliter) >= 10)
    spliter = spliter * 10;
  while (spliter > 0)
    {
      modulo = ((nb / spliter) %10);
      spliter = spliter / 10;
      my_putchar(modulo + 48);
    }
  return (0);
}
