/*
** list_handler.c for list_handler.c in /home/trognot/rendu/IA/dante/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Sun May 22 11:46:31 2016 nicolas trognot
** Last update Fri May 27 14:23:45 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <stdlib.h>
#include "astar.h"

int		already_in_list(t_list *list, int x, int y)
{
  t_list	*cur;

  cur = list;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	return (1);
      cur = cur->next;
    }
  return (0);
}

t_list		*add_elem_in_list(t_list *list, t_node *node)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL ||
      (new->node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  new->node->cost_g = node->cost_g;
  new->node->cost_h = node->cost_h;
  new->node->cost_f = node->cost_f;
  new->node->x = node->x;
  new->node->y = node->y;
  new->node->father.x = node->father.x;
  new->node->father.y = node->father.y;
  new->next = list;
  return (new);
}

t_list		*add_elem_in_close_list(t_maze *maze, t_point *pt)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL ||
      (new->node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  new->node->x = pt->x;
  new->node->y = pt->y;
  new->node->cost_g = get_cost_g_from_father_ouverte(pt->x, pt->y, maze);
  new->node->cost_h = get_cost_h_from_father_ouverte(pt->x, pt->y, maze);
  new->node->father = get_father_from_father_ouverte(pt->x, pt->y, maze);
  new->node->cost_f = new->node->cost_g + new->node->cost_h;
  new->next = maze->close;
  delete_node(&maze->open, pt->x, pt->y);
  return (new);
}

int		delete_node(t_list **head_ref, int x, int y)
{
  t_list	*temp;
  t_list	*prev;

  temp = *head_ref;
  if (temp != NULL && temp->node->x == x && temp->node->y == y)
    {
      *head_ref = temp->next;
      free(temp->node);
      free(temp);
      return (0);
    }
  while (temp != NULL && (temp->node->x != x || temp->node->y != y))
    {
      prev = temp;
      temp = temp->next;
    }
  if (temp == NULL)
    return (0);
  prev->next = temp->next;
  free(temp->node);
  free(temp);
  return (0);
}

void		update_node(int x, int y, t_maze *maze, t_node *node)
{
  t_list	*cur;

  cur = maze->close;
  while (cur)
    {
      if (cur->node->x == x && cur->node->y == y)
	memcpy(cur->node, node, sizeof(t_node));
      cur = cur->next;
    }
}
