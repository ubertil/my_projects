/*
** solver.c for solver.c in /home/trognot/rendu/IA/dante/generator/profondeur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 04:17:18 2016 nicolas trognot
** Last update Fri May 27 16:24:47 2016 louis-emile uberti-ares
*/

#include "profondeur.h"

int		get_maze_protected(t_maze *maze, int y, int x)
{
  if (x >= 0 && y >= 0 && x < maze->w && y < maze->h)
    return (maze->cells[y][x]);
  return (-1);
}

int		solver(t_maze *maze, int x, int y, int len)
{
  int		ret;

  if (len >= 300000)
    return (0);
  ret = 0;
  if ((x == maze->w - 1) && (y == maze->h - 1))
    return (1);
  maze->cells[y][x] = 4;
  if (get_maze_protected(maze, y, x + 1) == 0)
    if ((solver(maze, x + 1, y, len + 1)) == 1)
      ret = 1;
  if (get_maze_protected(maze, y + 1, x) == 0)
    if ((solver(maze, x, y + 1, len + 1)) == 1)
      ret = 1;
  if (get_maze_protected(maze, y - 1, x) == 0)
    if ((solver(maze, x, y - 1, len + 1)) == 1)
      ret = 1;
  if (get_maze_protected(maze, y, x - 1) == 0)
    if ((solver(maze, x - 1, y, len + 1)) == 1)
      ret = 1;
  if (ret == 1)
    maze->cells[y][x] = 3;
  return (ret);
}

int		solve_maze(t_maze *maze)
{
  int		ret;

  ret = solver(maze, 0, 0, 0);
  if (ret == 1)
    maze->cells[maze->h - 1][maze->w -1] = 3;
  return (ret);
}
