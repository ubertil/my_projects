/*
** main.c for main in /home/uberti_l/rendu/101pong
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov  2 21:14:36 2015 louis-emile uberti-ares
** Last update Mon Nov  9 15:55:19 2015 louis-emile uberti-ares
*/

#include "include/pong.h"
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	main(int ac, char **av)
{
  int	idx;
  int	i;

  idx = 0;
  i = 1;
  if (ac != 8)
    {
      printf("Usage : ./101pong x0 y0 z0 x1 y1 z1 n\n");
      exit (84);
    }
  while (i < ac)
    {
      while (av[i][idx] != '\0')
	{
	  if ((av[i][idx] == '0') || (av[i][idx] == '1') || (av[i][idx] == '2')
	      || (av[i][idx] == '3') || (av[i][idx] == '4') || (av[i][idx] == '5')
	      || (av[i][idx] == '6') || (av[i][idx] == '7') || (av[i][idx] == '8')
	      || (av[i][idx] == '9') || (av[i][idx] == '+') || (av[i][idx] == '-')
	      || (av[i][idx] == '.'))
	    idx = idx + 1;
	  else
	    {
	      printf("Error : Please enter valid arguments\n");
	      exit (84);
	    }
	}
      idx = 0;
      i = i + 1;
    }
  if ((atoi(av[7]) <= 0) || (atof(av[7]) != atoi(av[7])))
    {
      printf("n should be an integer greater than 0 or equal\n");
      exit (84);
    }
  my_init(av);
  return (0);
}
