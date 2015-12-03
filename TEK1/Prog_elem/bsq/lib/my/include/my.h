/*
** my.h for my_h in /home/uberti_l/rendu/PSU_2015_my_printf/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Nov 13 10:29:34 2015 louis-emile uberti-ares
** Last update Fri Nov 13 10:45:03 2015 louis-emile uberti-ares
*/

#include <stdarg.h>
#ifndef MY_H_
# define MY_H_

void			my_putchar(char c);
int			my_put_nbr(int nbr);
int			my_putstr(char *str);
int			my_putnbr_base(unsigned int nbr, char *base, int count);
int			my_put_nbr_us(unsigned int nbr);
int			my_putnbr_base_p(long long nbr, char *base, int count);
int			my_showstr(char *str);
int			my_strlen(char *str);
int			my_format_di(va_list list);
int			my_format_x(va_list list);
int			my_format_X(va_list list);
int			my_format_o(va_list list);
int			my_format_u(va_list list);
int			my_format_c(va_list list);
int			my_format_s(va_list list);
int			my_format_S(va_list list);
int			my_format_p(va_list list);
int			my_format_b(va_list list);
int			my_format_pourcentage();

typedef struct		s_format
{
  char			format;
  int			(*f)(va_list);
}			t_format;

#endif /* !MY_H */
