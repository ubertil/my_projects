/*
** colle3.c for colle3 in /home/uberti_l/rendu/Piscine_C_colles-Semaine_03
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 24 17:31:00 2015 louis-emile uberti-ares
** Last update Sun Oct 25 10:47:07 2015 louis-emile uberti-ares
*/

#include <unistd.h>
#include "include/my.h"

int	check_A(char *buff, int x, int y)
{
  if (buff[x - 1] == 'A')
    {
      colle1_3(x, y);
      my_putchar('\n');
      return (0);
    }
  else
    {
      if (buff[(x * y) - 1] == 'C')
	{
	  colle1_5(x, y);
	  my_putchar('\n');
	  return (0);
	}
      else
	{
	  colle1_4(x, y);
	  my_putchar('\n');
	  return (0);
	}
    }
}

int	what_is_x(char *buff, int i, int x)
{
  x = 0;
  while (buff[i] != '\n')
    {
      x = x + 1;
      i = i + 1;
    }
  return (x);
}

int	what_is_y(char *buff, int i, int y)
{
  y = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	y = y + 1;
      i = i + 1;
    }
  return (y);
}

int	colle3(char *buff)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = what_is_x(buff, i, x);
  y = what_is_y(buff, i, y);
  if (buff[0] == '/')
    colle1_2(x, y);
  if (buff[0] == 'o')
    colle1_1(x, y);
  if (buff[0] == 'B')
    {
      colle1_3(x, y);
      my_putstr(" || ");
      colle1_4(x, y);
      my_putstr(" || ");
      colle1_5(x, y);
      my_putchar('\n');
      return (0);
    }
  if (buff[0] == 'A')
    check_A(buff, x, y);
  if (buff[0] == '*')
    colle_commune(x, y);
}

int	main()
{
  char	buff[BUFF_SIZE + 1];
  int	len;
  long	i;

  i = 0;
  while (i < 999999999)
    i = i + 1;
  while ((len = read(0, buff, BUFF_SIZE)) > 0)
    {
      if (len != 1)
	{
	  buff[len] = 0;
	  colle3(buff);
	}
    }
  return (0);
}
