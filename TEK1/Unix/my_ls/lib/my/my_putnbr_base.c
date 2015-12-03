/*
** my_putnbr_base.c for my_putnbr_base in /home/uberti_l/rendu/Piscine_C_J06/ex_16
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct 13 09:32:00 2015 louis-emile uberti-ares
** Last update Sat Nov 14 16:44:01 2015 louis-emile uberti-ares
*/

#include "include/my.h"

int	my_putnbr_base_p(long long nbr, char *base, int count)
{
  if (nbr >= (long long)my_strlen(base))
    {
     count =  my_putnbr_base_p((nbr / my_strlen(base)), base, count + 1);
     count =  my_putnbr_base_p((nbr % my_strlen(base)), base, count);
    }
  else
    my_putchar(base[nbr]);
  return (count);
}

int	my_putnbr_base_us(unsigned int nbr, char *base, int count)
{
  if (nbr >= (unsigned int)my_strlen(base))
    {
      count = my_putnbr_base_us((nbr / my_strlen(base)), base, count + 1);
      count = my_putnbr_base_us((nbr % my_strlen(base)), base, count);
    }
  else
    my_putchar(base[nbr]);
  return (count);
}

int	my_putnbr_base(unsigned int nbr, char *base, int count)
{
  if (nbr >= (unsigned int)my_strlen(base))
    {
      count = my_putnbr_base((nbr / my_strlen(base)), base, count + 1);
      count = my_putnbr_base((nbr % my_strlen(base)), base, count);
    }
  else
    my_putchar(base[nbr]);
  return (count);
}
