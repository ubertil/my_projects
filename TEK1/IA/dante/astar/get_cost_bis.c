/*
** get_cost_bis.c for get_cost_bis.c in /home/trognot/rendu/IA/dante/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Sun May 22 11:54:35 2016 nicolas trognot
** Last update Sun May 22 11:54:35 2016 nicolas trognot
*/

#include "astar.h"

float		get_cost_h_from_father(int x, int y, t_maze *maze)
{
  t_list	*cur;

  cur = maze->close;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	return (cur->node->cost_h);
      cur = cur->next;
    }
  return (0);
}
