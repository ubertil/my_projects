/*
** utils.c for utils.c in /home/trognot/rendu/IA/dante/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Sun May 22 11:32:21 2016 nicolas trognot
** Last update Sun May 22 11:32:21 2016 nicolas trognot
*/

#include "astar.h"

int		get_maze_protected(t_maze *maze, int y, int x)
{
  if (x >= 0 && y >= 0 && x < maze->w && y < maze->h)
    return (maze->cells[y][x]);
  return (-1);
}

float			distance(int x1, int y1, int x2, int y2)
{
  register int		a;
  register int		b;
  register int		ret;

  a = x2 - x1;
  a = (a < 0) ? (-a) : (a);
  b = y2 - y1;
  b = (b < 0) ? (-b) : (b);
  ret = a + b;
  return (ret);
}
