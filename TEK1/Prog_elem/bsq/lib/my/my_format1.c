/*
** my_format1.c for my_format1 in /home/uberti_l/rendu/PSU_2015_my_printf
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov  9 17:04:53 2015 louis-emile uberti-ares
** Last update Tue Nov 17 11:39:29 2015 louis-emile uberti-ares
*/

#include <stdarg.h>
#include "include/my.h"

int	my_format_di(va_list list)
{
  int	count;

  count = my_put_nbr(va_arg(list, int));
  return (count);
}

int	my_format_o(va_list list)
{
  int	count;

  count = 1;
  count = my_putnbr_base(va_arg(list, unsigned int), "01234567", count);
  return (count);
}

int	my_format_x(va_list list)
{
  int	count;

  count = 1;
  count = my_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef", count);
  return (count);
}

int	my_format_X(va_list list)
{
  int	count;

  count = 1;
  count = my_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF", count);
  return (count);
}

int	my_format_u(va_list list)
{
  int	count;

  count = my_put_nbr_us(va_arg(list, unsigned int));
  return (count);
}
