/*
** perfect.c for perfect.c in /home/trognot/rendu/IA/dante/serieux/perfect
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Fri May  6 11:45:57 2016 nicolas trognot
** Last update Fri May 27 17:16:08 2016 louis-emile uberti-ares
** Last update Fri May 27 15:50:22 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "generateur.h"

void		detect_neighbours(t_maze *maze, char *neighbours, int x,
				  int y)
{
  int		i;

  i = -1;
  while (++i < 4)
    neighbours[i] = 1;
  if (y - 2 >= 0 && x >= 0 && y - 2 < maze->h
      && x < maze->w && maze->cells[y - 2][x] == 0)
    neighbours[0] = 0;
  if (x + 2 >= 0 && x + 2 < maze->w && y >= 0 && y < maze->h
      && maze->cells[y][x + 2] == 0)
    neighbours[1] = 0;
  if (y + 2 < maze->h && y + 2 >= 0 && x >= 0
      && x < maze->w && maze->cells[y + 2][x] == 0)
    neighbours[2] = 0;
  if (x - 2 >= 0 && x - 2 < maze->w && y >= 0 && y < maze->h
      && maze->cells[y][x - 2] == 0)
    neighbours[3] = 0;
}

int		there_is_no_neighbours(char *neighbours)
{
  int		i;

  i = -1;
  while (++i < 4)
    if (neighbours[i] == 0)
      i = 41;
  if (i == 42)
    return (0);
  return (1);
}

int		set_open_door(int i, int *xy, t_maze *maze,
			      int len)
{
  if (i == 0)
    {
      set_maze_protected(maze, xy[1] - 1, xy[0], 2);
      set_maze_protected(maze, xy[1] - 2, xy[0], 2);
      return (build_maze(maze, xy[0], xy[1] - 2, len));
    }
  if (i == 1)
    {
      set_maze_protected(maze, xy[1], xy[0] + 1, 2);
      set_maze_protected(maze, xy[1], xy[0] + 2, 2);
      return (build_maze(maze, xy[0] + 2, xy[1], len));
    }
  if (i == 2)
    {
      set_maze_protected(maze, xy[1] + 1, xy[0], 2);
      set_maze_protected(maze, xy[1] + 2, xy[0], 2);
      return (build_maze(maze, xy[0], xy[1] + 2, len));
    }
  if (i == 3)
    {
      set_maze_protected(maze, xy[1], xy[0] - 1, 2);
      set_maze_protected(maze, xy[1], xy[0] - 2, 2);
      return (build_maze(maze, xy[0] - 2, xy[1], len));
    }
  return (0);
}

int		build_maze(t_maze *maze, int x, int y, int len)
{
  char		neighbours[4];
  int		i;
  int		ret;
  int		xy[2];

  if (len >= 50000)
    return (0);
  ret = 0;
  detect_neighbours(maze, neighbours, x, y);
  if (there_is_no_neighbours(neighbours) == 1)
    return (0);
  i = rand() % 4;
  while (neighbours[i] == 1)
    i = rand() % 4;
  xy[0] = x;
  xy[1] = y;
  ret = set_open_door(i, xy, maze, len + 1);
  while (ret != 0)
    ret = build_maze(maze, x, y, len + 1);
  return (1);
}

int		main(int ac, char **av)
{
  t_maze	*maze;
  int		w;
  int		h;
  char		mode;

  mode = 0;
  if ((ac != 4) && (ac != 3))
    return (my_putstr_err(USAGE));
  if (check_args(av, ac, &mode) == -1)
    return (1);
  w = my_getnbr(av[1]);
  h = my_getnbr(av[2]);
  srand(time(NULL) * getpid());
  if ((maze = init_maze(w, h)) == NULL)
    return (1);
  maze->is_perf = mode;
  maze->cells[0][0] = 2;
  build_maze(maze, 0, 0, 0);
  fill(maze, w, h);
  display_maze(maze);
  free_all(maze);
  return (0);
}
