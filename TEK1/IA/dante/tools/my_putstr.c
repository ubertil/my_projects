/*
** my_putstr.c for my_putstr.c in /home/trognot/rendu/IA/dante/generateur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed May 18 13:11:26 2016 nicolas trognot
** Last update Fri May 27 13:54:01 2016 louis-emile uberti-ares
*/

#include <unistd.h>

int		my_putstr_err(const char *str)
{
  int		i;

  if (str != NULL)
    {
      i = 0;
      while (str[i])
	{
	  write(2, &str[i], 1);
	  i++;
	}
    }
  return (-1);
}

void		my_putstr(const char *str)
{
  int		i;

  if (str)
    {
      i = 0;
      while (str[i])
	{
	  write(1, &str[i], 1);
	  i++;
	}
    }
}
