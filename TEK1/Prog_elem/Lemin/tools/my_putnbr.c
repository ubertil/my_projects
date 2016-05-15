/*
** my_putnbr.c for my_putnbr.c in /home/trognot/rendu/CPE/CPE_2015_Lemin/tools
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu Apr 21 09:39:13 2016 nicolas trognot
** Last update Thu Apr 21 09:39:13 2016 nicolas trognot
*/

#include <unistd.h>
#include "lemin.h"

void	my_putchar_nbr(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      nbr = -nbr;
      my_putchar_nbr('-');
    }
  if (nbr > 0)
    {
      my_putnbr(nbr / 10);
      my_putchar_nbr(nbr % 10 + 48);
    }
}
