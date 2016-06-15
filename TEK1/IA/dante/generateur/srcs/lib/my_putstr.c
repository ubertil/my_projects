/*
** my_putstr.c for my_putstr.c in /home/trognot/rendu/IA/dante/generateur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed May 18 13:11:26 2016 nicolas trognot
** Last update Wed May 18 13:11:26 2016 nicolas trognot
*/

#include <unistd.h>

void		my_putstr_err(const char *str)
{
  int		i;

  if (str)
    {
      i = 0;
      while (str[i])
	{
	  write(2, &str[i], 1);
	  i++;
	}
    }
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
