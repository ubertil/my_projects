/*
** my_putstr_err.c for my_putstr_err in /home/uberti_l/source_files/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Dec 12 08:11:29 2015 louis-emile uberti-ares
** Last update Tue May  3 21:22:07 2016 louis-emile uberti-ares
*/

#include <unistd.h>

int	my_puterr(char *str)
{
  while (*str)
    write(2, str++, 1);
  return (-1);
}
