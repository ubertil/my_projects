/*
** my_putstr_err.c for my_putstr_err in /home/uberti_l/source_files/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Dec 12 08:11:29 2015 louis-emile uberti-ares
** Last update Sat Dec 12 08:12:53 2015 louis-emile uberti-ares
*/

#include <unistd.h>

void	err_putchar(char c)
{
  write(2, &c, 1);
}

void	my_putstr_err(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      err_putchar(str[i]);
      i += 1;
    }
}
