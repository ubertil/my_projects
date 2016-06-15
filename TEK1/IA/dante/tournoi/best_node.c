/*
** best_node.c for best_node.c in /home/trognot/rendu/IA/dante/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Sun May 22 11:21:19 2016 nicolas trognot
** Last update Sun May 22 11:21:19 2016 nicolas trognot
*/

#include "astar.h"

t_point		best_node(t_list *list)
{
  t_point	ret;
  float		costf;
  t_list	*cur;

  ret.x = list->node->x;
  ret.y = list->node->y;
  costf = list->node->cost_f;
  cur = list;
  while (cur)
    {
      if (cur->node->cost_f < costf)
	{
	  ret.x = cur->node->x;
	  ret.y = cur->node->y;
	  costf = cur->node->cost_f;
	}
      cur = cur->next;
    }
  return (ret);
}
