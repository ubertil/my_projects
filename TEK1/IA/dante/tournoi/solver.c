/*
** solver.c for solver.c in /home/trognot/rendu/IA/dante/generator/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 04:17:18 2016 nicolas trognot
** Last update Thu May 12 04:17:18 2016 nicolas trognot
*/

#include <stdlib.h>
#include "astar.h"

void		check_neighbours_cell(int *val, int i, int j,
				      t_maze *maze)
{
  t_node	tmp;

  if ((j != val[1] || i != val[0]) &&
      (get_maze_protected(maze, j, i) == 0))
    {
      if (already_in_list(maze->close, i, j) == 0)
	{
	  tmp.cost_g = get_cost_g_from_father(val[0], val[1], maze) +
	    distance(i, j, val[0], val[1]);
	  tmp.cost_h = distance(i, j, maze->begin.x, maze->begin.y);
	  tmp.cost_f = tmp.cost_g + tmp.cost_h;
	  tmp.father.x = val[0];
	  tmp.father.y = val[1];
	  tmp.y = j;
	  tmp.x = i;
	  if (already_in_list(maze->open, i, j) == 1)
	    {
	      if (tmp.cost_f < get_cost_f_from_father(i, j, maze))
		update_node(i, j, maze, &tmp);
	    }
	  else
	    maze->open = add_elem_in_list(maze->open, &tmp);
	}
    }
}

void		add_neighbours_cell(int x, int y, t_maze *maze)
{
  int		tmp[2];

  tmp[0] = x;
  tmp[1] = y;
  check_neighbours_cell(tmp, x, y - 1, maze);
  check_neighbours_cell(tmp, x - 1, y, maze);
  check_neighbours_cell(tmp, x + 1, y, maze);
  check_neighbours_cell(tmp, x, y + 1, maze);

}

int		solve_maze(t_maze *maze)
{
  t_node	start;
  t_point	current;

  start = init_start(maze, &current);
  maze->open = add_elem_in_list(maze->open, &start);
  maze->close = add_elem_in_close_list(maze, &current);
  add_neighbours_cell(current.x, current.y, maze);
  while ((current.x != maze->begin.x || current.y != maze->begin.y) &&
	 maze->open != NULL)
    {
      current = best_node(maze->open);
      maze->close = add_elem_in_close_list(maze, &current);
      add_neighbours_cell(current.x, current.y, maze);
    }
  if (maze->open == NULL && current.x != maze->begin.x &&
      current.y != maze->begin.y)
    return (0);
  fill_result(maze);
  return (1);
}
