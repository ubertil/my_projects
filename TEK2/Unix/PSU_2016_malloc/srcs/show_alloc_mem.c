/*
** show_alloc_mem.c for show_alloc_mem in /Users/uberti_l/rendu/Unix/PSU_2016_malloc
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Jan 27 13:30:24 2017 Louis-Emile Uberti
** Last update Sat Feb 11 14:55:14 2017 alexis papadimitriou
*/

#include <unistd.h>
#include "malloc.h"

extern void		*first_break;

static int		my_strlen(const char *base)
{
  int			i;

  i = 0;
  if (base == (void *)0)
    return (0);
  while (base[i] != '\0')
    ++i;
  return (i);
}

inline static void	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

inline static void	my_putchar(const char c)
{
  write(1, &c, 1);
}

static void		my_putnbr_base_pointer(unsigned long nbr, const char *base)
{
  if (nbr >= (unsigned long)my_strlen(base))
    {
      my_putnbr_base_pointer((nbr / my_strlen(base)), base);
      my_putnbr_base_pointer((nbr % my_strlen(base)), base);
    }
  else
    my_putchar(base[nbr]);
}

void			show_alloc_mem()
{
  t_header		*tmp;
  void			*base;

  tmp = (t_header *)first_break;
  if ((base = sbrk(0)) == (void *)-1)
    return ;
  my_putstr("break : ");
  my_putnbr_base_pointer((unsigned long)base, HEX);
  my_putchar('\n');
  while (tmp != NULL)
    {
      if (!tmp->free)
	{
	  my_putnbr_base_pointer((unsigned long)(tmp + 1), HEX);
	  my_putstr(" - ");
	  my_putnbr_base_pointer((unsigned long)(tmp + 1) + tmp->size, HEX);
	  my_putstr(" : ");
	  my_putnbr_base_pointer(tmp->size, DEC);
	  my_putstr(" bytes\n");
	}
      tmp = tmp->next;
    }
}
