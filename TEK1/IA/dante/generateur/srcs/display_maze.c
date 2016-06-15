/*
** display_maze.c for display_maze.c in /home/trognot/rendu/IA/dante/generator/perfect
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 02:22:17 2016 nicolas trognot
** Last update Thu May 12 02:22:17 2016 nicolas trognot
*/

#include "generateur.h"

void		display_maze(t_maze *maze)
{
  int		i;
  int		j;

  j = 0;
  while (j < maze->h)
    {
      i = 0;
      while (i < maze->w)
	{
	  if (maze->cells[j][i] == 1)
	    my_putstr("X");
	  else
	    my_putstr("*");
	  i++;
	}
      if (j < maze->h - 1)
	my_putstr("\n");
      j++;
    }
}
