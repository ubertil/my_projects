/*
** sort_results.c for sort_results.c in /home/trognot/rendu/CPE/CPE_2015_Lemin
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed Apr 20 11:33:29 2016 nicolas trognot
** Last update Wed Apr 20 11:33:29 2016 nicolas trognot
*/

#include "lemin.h"

int		is_sorted(t_path_list *list)
{
  t_path_list	*curr;

  curr = list;
  while (curr && curr->next)
    {
      if (curr->nb_idx > curr->next->nb_idx)
	return (0);
      curr = curr->next;
    }
  return (1);
}

void		sort_list(t_path_list *list)
{
  t_path_list	*curr;
  int		tmp_nb_idx;
  int		*tmp_idx_list;

  while (is_sorted(list) == 0)
    {
      curr = list;
      while (curr && curr->next)
	{
	  if (curr->nb_idx > curr->next->nb_idx)
	    {
	      tmp_nb_idx = curr->nb_idx;
	      tmp_idx_list = curr->idx_list;
	      curr->nb_idx = curr->next->nb_idx;
	      curr->idx_list = curr->next->idx_list;
	      curr->next->idx_list = tmp_idx_list;
	      curr->next->nb_idx = tmp_nb_idx;
	    }
	  curr = curr->next;
	}
    }
}
