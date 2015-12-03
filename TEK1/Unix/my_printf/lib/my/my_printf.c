/*
** my_printf.c for my_printf in /home/uberti_l/rendu/PSU_2015_my_printf
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Nov  5 10:15:30 2015 louis-emile uberti-ares
** Last update Thu Nov 12 14:59:50 2015 louis-emile uberti-ares
*/

#include <stdarg.h>

void		my_putchar(char c);
int		my_format_di(va_list list);
int		my_format_x(va_list list);
int		my_format_X(va_list list);
int		my_format_o(va_list list);
int		my_format_u(va_list list);
int		my_format_c(va_list list);
int		my_format_s(va_list list);
int		my_format_S(va_list list);
int		my_format_p(va_list list);
int		my_format_b(va_list list);
int		my_format_pourcentage();

typedef struct		s_format
{
  char			format;
  int			(*f)(va_list);
}			t_format;

static const t_format	show[12] =
  {
    {'d', &my_format_di},
    {'i', &my_format_di},
    {'x', &my_format_x},
    {'X', &my_format_X},
    {'o', &my_format_o},
    {'u', &my_format_u},
    {'c', &my_format_c},
    {'s', &my_format_s},
    {'S', &my_format_S},
    {'p', &my_format_p},
    {'b', &my_format_b},
    {'%', &my_format_pourcentage}
  };

int		my_format_pourcentage()
{
  my_putchar('%');
  return (1);
}

int		my_printf(const char *format, ...)
{
  int		tab[3];
  va_list	list;

  va_start(list, format);
  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  while (format[tab[0]] != '\0')
    {
      while (format[tab[0]] != '%' && format[tab[0]] != '\0')
	{
	  my_putchar(format[tab[0]]);
	  tab[0] = tab[0] + 1;
	}
      (format[tab[0]] != '\0') ? (tab[0] = tab[0] + 1) : (0);
      while (format[tab[0]] == ' ')
	tab[0] = tab[0] + 1;
      while ((show[tab[1]].format != format[tab[0]]) && (tab[1] != 13))
	tab[1] = tab[1] + 1;
      (format[tab[0]] != '\0') ? (tab[2] = show[tab[1]].f(list) + tab[2]) : (0);
      tab[1] = 0;
      (format[tab[0]] != '\0') ? (tab[0] = tab[0] + 1) : (0);
    }
  va_end(list);
  return (tab[2]);
}
