/*
** my_putstr_err.c for my_putstr_err in /home/uberti_l/source_files/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Dec 12 08:11:29 2015 louis-emile uberti-ares
** Last update Thu Apr  7 13:42:31 2016 louis-emile uberti-ares
*/

#include <unistd.h>

void	my_puterr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    write(2, &str[i++], 1);
}
