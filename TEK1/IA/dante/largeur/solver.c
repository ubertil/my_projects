/*
** solver.c for solver.c in /home/trognot/rendu/IA/dante/generator/largeur/srcs
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Fri May 13 15:42:59 2016 nicolas trognot
** Last update Sun May 22 19:02:37 2016 louis-emile uberti-ares
*/

#include "largeur.h"

int		do_it(t_maze *maze, int j, int i)
{
  fill_three(maze);
  while (++j < maze->h)
    {
      i = -1;
      while (++i < maze->w)
	{
	  if (maze->cells[j][i] == 3)
	    {
	      if (get_maze_protected(maze, j - 1, i) == 0)
		maze->cells[j - 1][i] = 4;
	      if (get_maze_protected(maze, j, i - 1) == 0)
		maze->cells[j][i - 1] = 4;
	      if (get_maze_protected(maze, j, i + 1) == 0)
		maze->cells[j][i + 1] = 4;
	      if (get_maze_protected(maze, j + 1, i) == 0)
		maze->cells[j + 1][i] = 4;
	      maze->cells[j][i] = 2;
	      if (j == maze->h - 1 && i == maze->w - 1)
		return (1);
	    }
	}
    }
  return (0);
}

int	is_there_nice_one(t_maze *maze)
{
  int	j;
  int	i;

  j = -1;
  while (++j < maze->h)
    {
      i = -1;
      while (++i < maze->w)
	{
	  if (maze->cells[j][i] == 4)
	    if (get_maze_protected(maze, j - 1, i) == 0 ||
		get_maze_protected(maze, j, i - 1) == 0 ||
		get_maze_protected(maze, j, i + 1) == 0 ||
		get_maze_protected(maze, j + 1, i) == 0)
	return (1);
	}
    }
  return (0);
}

int	do_reverse(t_maze *maze, int x, int y)
{
  while ((x != 0) || (y != 0))
    {
      set_maze_protected(maze, y, x, get_maze_protected(maze, y, x) + 1);
      if (compare_neighbours(maze, x, y,
			     get_maze_protected(maze, y, x - 1)) == 1)
	x--;
      else if (compare_neighbours(maze, x, y,
				  get_maze_protected(maze, y - 1, x)) == 1)
	y--;
      else if (compare_neighbours(maze, x, y,
				  get_maze_protected(maze, y + 1, x)) == 1)
	y++;
      else if (compare_neighbours(maze, x, y,
				  get_maze_protected(maze, y, x + 1)) == 1)
	x++;
    }
  if (x == 0 && y == 0)
    set_maze_protected(maze, y, x, 3);
  return (0);
}

int	do_last(t_maze *maze, int x, int y)
{
  while ((x != maze->w - 1 || y != maze->h - 1))
    {
      set_maze_protected(maze, y, x, 9);
      if (cmp_nb_final(maze, x, y,
		       get_maze_protected(maze, y, x + 1)) == 1)
	x++;
      else if (cmp_nb_final(maze, x, y,
			    get_maze_protected(maze, y + 1, x)) == 1)
	y++;
      else if (cmp_nb_final(maze, x, y,
			    get_maze_protected(maze, y - 1, x)) == 1)
	y--;
      else if (cmp_nb_final(maze, x, y,
			    get_maze_protected(maze, y, x - 1)) == 1)
	x--;
    }
  if (x == maze->w - 1 && y == maze->h - 1)
    set_maze_protected(maze, y, x, 9);
  return (0);
}

int	solver(t_maze *maze)
{
  int	ret;
  int	x;
  int	y;

  maze->cells[0][0] = 4;
  ret = 0;
  while (ret == 0 && is_there_nice_one(maze) == 1)
    ret = do_it(maze, -1, 0);
  if (get_maze_protected(maze, maze->h - 1, maze->w - 1) == 4)
    set_maze_protected(maze, maze->h - 1, maze->w - 1, 2);
  y = -1;
  while (++y < maze->h)
    {
      x = -1;
      while (++x < maze->w)
	if (get_maze_protected(maze, y, x) == 4)
	  set_maze_protected(maze, y, x, 0);
    }
  ret = (get_maze_protected(maze, maze->h - 1, maze->w - 1)) ? (1) : (ret);
  if (get_maze_protected(maze, maze->h - 1, maze->w - 1) == 2)
    do_reverse(maze, maze->w - 1, maze->h - 1);
  if (get_maze_protected(maze, 0, 0) == 3)
    do_last(maze, 0, 0);
  return (ret);
}
