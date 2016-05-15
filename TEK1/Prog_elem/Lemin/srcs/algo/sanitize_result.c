/*
** sanitize_result.c for sanitize_result.c in /home/trognot/rendu/CPE/CPE_2015_Lemin
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed Apr 20 13:57:41 2016 nicolas trognot
** Last update Sun Apr 24 21:53:59 2016 come grellard
*/

#include <stdlib.h>
#include "lemin.h"

int		there_is_conflict(t_path_list *list, int *checker,
				  t_lemin *lemin)
{
  int		i;

  i = 0;
  while (++i < list->nb_idx - 1)
    {
      if (list->idx_list[i] < lemin->nb_rooms)
	if (checker[list->idx_list[i]] == 1)
	  return (1);
    }
  return (0);
}

void		set_one_in_table(t_path_list *list, int *checker,
				 t_lemin *lemin)
{
  int		i;

  i = 0;
  while (++i < list->nb_idx - 1)
    {
      if (list->idx_list[i] < lemin->nb_rooms)
	checker[list->idx_list[i]] = 1;
    }
}

int		disable_conflicts(t_path_list *list, t_lemin *lemin)
{
  int		*checker;
  t_path_list	*curr;
  int		i;

  if ((checker = malloc(sizeof(int) * lemin->nb_rooms)) == NULL)
    return (0);
  i = -1;
  while (++i < lemin->nb_rooms)
    checker[i] = 0;
  curr = list;
  while (curr)
    {
      if (curr->is_ok == 1)
	{
	  if (there_is_conflict(curr, checker, lemin) == 0)
	    set_one_in_table(curr, checker, lemin);
	  else
	    curr->is_ok = 0;
	}
      curr = curr->next;
    }
  free(checker);
  return (0);
}

void		disable_if_direct(t_path_list *list, t_lemin *lemin)
{
  t_path_list	*curr;

  if (list && lemin->list->nb_idx == 2)
    {
      curr = list->next;
      while (curr)
	{
	  curr->is_ok = 0;
	  curr = curr->next;
	}
    }
}

void		sanitize_list(t_path_list *list, t_lemin *lemin)
{
  t_path_list	*curr;
  int		i;
  int		tmp;
  int		final;

  i = 0;
  tmp = list->nb_idx - 1;
  if (lemin->nb_ants_start < tmp)
    final = tmp;
  else
    final = lemin->nb_ants_start;
  curr = list;
  while (curr)
    {
      if ((curr->nb_idx - 1 > final) && (i == 1))
	curr->is_ok = 0;
      i = 1;
      curr = curr->next;
    }
  disable_conflicts(list, lemin);
  disable_if_direct(list, lemin);
}
