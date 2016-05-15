/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
** Last update Sun Apr 24 17:29:17 2016 nicolas wadel
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    write(1, &str[i++], 1);
}
