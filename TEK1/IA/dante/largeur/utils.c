/*
** utils.c for utils.c in /home/trognot/rendu/IA/dante
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Fri May 20 14:03:09 2016 nicolas trognot
** Last update Fri May 20 14:03:09 2016 nicolas trognot
*/

#include "largeur.h"

int		get_maze_protected(t_maze *maze, int y, int x)
{
  if (x >= 0 && y >= 0 && x < maze->w && y < maze->h)
    return (maze->cells[y][x]);
  return (-1);
}

void		fill_three(t_maze *maze)
{
  int		i;
  int		j;

  j = -1;
  while (++j < maze->h)
    {
      i = -1;
      while (++i < maze->w)
	if (maze->cells[j][i] == 4)
	  maze->cells[j][i] = 3;
    }
}
