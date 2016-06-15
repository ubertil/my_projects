/*
** get_cost.c for get_cost.c in /home/trognot/rendu/IA/dante/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Sun May 22 11:52:12 2016 nicolas trognot
** Last update Sun May 22 18:54:43 2016 louis-emile uberti-ares
*/

#include "astar.h"

float		get_cost_g_from_father(int x, int y, t_maze *maze)
{
  t_list	*cur;

  cur = maze->close;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	return (cur->node->cost_g);
      cur = cur->next;
    }
  return (0);
}

float		get_cost_g_from_father_ouverte(int x, int y, t_maze *maze)
{
  t_list	*cur;

  cur = maze->open;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	return (cur->node->cost_g);
      cur = cur->next;
    }
  return (0);
}

float		get_cost_f_from_father(int x, int y, t_maze *maze)
{
  t_list	*cur;

  cur = maze->close;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	return (cur->node->cost_f);
      cur = cur->next;
    }
  return (0);
}

float		get_cost_h_from_father_ouverte(int x, int y, t_maze *maze)
{
  t_list	*cur;

  cur = maze->open;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	return (cur->node->cost_h);
      cur = cur->next;
    }
  return (0);
}

t_point		get_father_from_father_ouverte(int x, int y, t_maze *maze)
{
  t_list	*cur;
  t_point	ret;

  ret.x = 0;
  ret.y = 0;
  cur = maze->open;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	return (cur->node->father);
      cur = cur->next;
    }
  return (ret);
}
