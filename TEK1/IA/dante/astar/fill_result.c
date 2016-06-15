/*
** fill_result.c for fill_result.c in /home/trognot/rendu/IA/dante/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Sun May 22 11:14:22 2016 nicolas trognot
** Last update Sun May 22 11:14:22 2016 nicolas trognot
*/

#include "astar.h"

void		fill_result(t_maze *maze)
{
  t_list	*cur;
  t_point	ftmp;

  maze->cells[maze->h - 1][maze->w - 1] = 3;
  cur = maze->close;
  ftmp.x = cur->node->father.x;
  ftmp.y = cur->node->father.y;
  while (ftmp.x != 0 || ftmp.y != 0)
    {
      cur = maze->close;
      while (cur && (cur->node->x != ftmp.x ||
		     cur->node->y != ftmp.y))
	cur = cur->next;
      ftmp.x = cur->node->father.x;
      ftmp.y = cur->node->father.y;
      maze->cells[cur->node->y][cur->node->x] = 3;
    }
  maze->cells[0][0] = 3;
}
