/*
** fill.c for fillc in /home/trognot/rendu/IA/dante/generateur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 19 01:56:50 2016 nicolas trognot
** Last update Thu May 19 01:56:50 2016 nicolas trognot
*/

#include "generateur.h"

void	fill(t_maze *maze, int w, int h)
{
  int	j;
  int	i;

  set_maze_protected(maze, w - 1, h - 2, 2);
  set_maze_protected(maze, w - 1, h - 1, 2);
  if (maze->is_perf == 0)
    {
      j = -1;
      while (++j < h)
	{
	  i = -1;
	  while (++i < w)
	    if (maze->cells[j][i] == 2)
	      maze->cells[j][i] = 0;
	}
      build_maze(maze, 0, 0, 0);
    }
}
