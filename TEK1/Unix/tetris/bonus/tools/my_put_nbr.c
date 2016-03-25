/*
** my_put_nbr.c for my_put_nbr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:41:42 2015 louis-emile uberti-ares
** Last update Mon Feb 22 14:13:48 2016 louis-emile uberti-ares
*/

#include "../include/tetris.h"

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
