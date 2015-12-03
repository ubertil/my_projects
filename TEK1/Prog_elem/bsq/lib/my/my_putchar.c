/*
** my_putchar.c for my_putchar in /home/uberti_l/rendu/Piscine_C_J07/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 20:03:48 2015 louis-emile uberti-ares
** Last update Tue Nov 10 16:10:13 2015 louis-emile uberti-ares
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}
