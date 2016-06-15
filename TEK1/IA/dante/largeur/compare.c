/*
** compare.c for compare.c in /home/trognot/rendu/IA/dante
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Fri May 20 14:06:05 2016 nicolas trognot
** Last update Fri May 20 14:06:05 2016 nicolas trognot
*/

#include "../include/largeur.h"

void	compare_each(t_maze *maze, int h, int w, int *smaller)
{
  if (get_maze_protected(maze, h, w) > 1 &&
      get_maze_protected(maze, h, w) < *smaller)
    *smaller = get_maze_protected(maze, h, w);
}

int	compare_neighbours(t_maze *maze, int w, int h, int val)
{
  int	smaller;

  smaller = 4048;
  if (val == 2)
    return (1);
  if (val == -1)
    return (0);
  compare_each(maze, h - 1, w, &smaller);
  compare_each(maze, h + 1, w, &smaller);
  compare_each(maze, h, w - 1, &smaller);
  compare_each(maze, h, w + 1, &smaller);
  if (smaller == val)
    return (1);
  return (0);
}

void	compare_each_final(t_maze *maze, int h, int w, int *smaller)
{
  if (get_maze_protected(maze, h, w) > 2 &&
      get_maze_protected(maze, h, w) < *smaller)
    *smaller = get_maze_protected(maze, h, w);
}

int	cmp_nb_final(t_maze *maze, int w, int h, int val)
{
  int	smaller;

  smaller = 4048;
  if (val == 3)
    return (1);
  if (val == -1)
    return (0);
  compare_each_final(maze, h - 1, w, &smaller);
  compare_each_final(maze, h + 1, w, &smaller);
  compare_each_final(maze, h, w - 1, &smaller);
  compare_each_final(maze, h, w + 1, &smaller);
  if (smaller == val)
    return (1);
  return (0);
}
