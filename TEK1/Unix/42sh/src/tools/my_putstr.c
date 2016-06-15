/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
** Last update Tue May 31 15:06:16 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <unistd.h>

void	my_putstr(const char *str)
{
  if (!str)
    return;
  write(1, str, strlen(str));
}
