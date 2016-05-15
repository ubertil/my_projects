/*
** launch_algorithm.c for launch_algorithm.c in /home/trognot/rendu/CPE/CPE_2015_Lemin/srcs
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Mon Apr 18 10:22:04 2016 nicolas trognot
** Last update Thu Apr 21 14:58:23 2016 come grellard
*/

#include <stdlib.h>
#include "lemin.h"

int		check_line_algo(t_lemin *lemin, int idx)
{
  int		j;
  int		ret;

  ret = 0;
  j = 0;
  while (j < lemin->nb_rooms)
    {
      if (lemin->matrix[idx][j] == 1)
	ret = 1;
      j++;
    }
  return (ret);
}

int		check_start_end_has_possibilities(t_rooms *rooms,
						  t_lemin *lemin)
{
  char		start_ok;
  char		end_ok;
  t_rooms	*curr;
  int		idx;

  start_ok = 0;
  end_ok = 0;
  curr = rooms;
  idx = 0;
  while (curr != NULL)
    {
      if (curr->nb == 1)
	start_ok = check_line_algo(lemin, idx);
      if (curr->nb == 2)
	end_ok = check_line_algo(lemin, idx);
      curr = curr->next;
      idx++;
    }
  return (((start_ok == 1) && (end_ok == 1)) ? (0) : (1));
}

int		do_the_rec(t_lemin *lemin, int *is_visited, int *history)
{
  t_rooms	*curr;
  int		i;

  curr = lemin->rooms;
  i = -1;
  while (curr != NULL && ++i > -1)
    {
      if (curr->nb == 1)
	{
	  is_visited[i] = 1;
	  history[1] = i;
	  recursive_algo(lemin, i, is_visited, history);
	}
      curr = curr->next;
    }
  return (0);
}

int		launch_algorithm(t_lemin *lemin, int *is_visited,
				 int *history)
{
  int		i;

  if ((is_visited = malloc(sizeof(int) * lemin->nb_rooms)) == NULL ||
      (history = malloc(sizeof(int) * 2)) == NULL)
    return (1);
  history[0] = 1;
  i = -1;
  while (++i < lemin->nb_rooms)
    is_visited[i] = 0;
  if (check_start_end_has_possibilities(lemin->rooms, lemin) == 1)
    return (1);
  do_the_rec(lemin, is_visited, history);
  lemin->nb_ants_start = lemin->nb_ants;
  lemin->nb_ants_end = 0;
  free(is_visited);
  free(history);
  return (0);
}
