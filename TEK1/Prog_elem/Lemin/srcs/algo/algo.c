/*
** algo.c for algo.c in /home/trognot/rendu/CPE/CPE_2015_Lemin
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Mon Apr 18 15:04:58 2016 nicolas trognot
** Last update Sun Apr 24 15:22:15 2016 nicolas trognot
*/

#include <stdlib.h>
#include "lemin.h"

int		get_nb(t_lemin *lemin, int idx)
{
  int		i;
  t_rooms	*curr;

  i = 0;
  curr = lemin->rooms;
  while (curr != NULL && i < idx)
    {
      curr = curr->next;
      i++;
    }
  return (curr->nb);
}

char		*get_name(t_lemin *lemin, int idx)
{
  int		i;
  t_rooms	*curr;

  i = 0;
  curr = lemin->rooms;
  while (curr != NULL && i < idx)
    {
      curr = curr->next;
      i++;
    }
  return (curr->room_name);
}

int		*new_visited(int *is_visited, t_lemin *lemin)
{
  int		i;
  int		*is_visited_new;

  if ((is_visited_new = malloc(sizeof(int) * lemin->nb_rooms)) == NULL)
    return (NULL);
  i = -1;
  while (++i < lemin->nb_rooms)
    is_visited_new[i] = is_visited[i];
  return (is_visited_new);
}

int		recursive_algo(t_lemin *lemin, int idx, int *is_visited,
			       int *history)
{
  int		i;
  int		*is_visited_new;
  int		*newhistory;

  if ((newhistory = malloc(sizeof(int) * (history[0] + 1))) == NULL)
    return (0);
  i = -1;
  while (++i < history[0])
    newhistory[i] = history[i];
  newhistory[i] = idx;
  newhistory[0]++;
  if ((is_visited_new = new_visited(is_visited, lemin)) == NULL)
    return (0);
  if (get_nb(lemin, idx) == 2)
    {
      add_to_list(newhistory, &lemin->list, lemin);
      return (free_history_visited(is_visited_new, newhistory));
    }
  else
    is_visited_new[idx] = 1;
  i = -1;
  while (++i < lemin->nb_rooms)
    if (lemin->matrix[idx][i] == 1 && is_visited_new[i] == 0)
      recursive_algo(lemin, i, is_visited_new, newhistory);
  return (free_history_visited(is_visited_new, newhistory));
}
