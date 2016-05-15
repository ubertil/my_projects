/*
** stock_results.c for stock_result.c in /home/trognot/rendu/CPE/CPE_2015_Lemin/srcs/algo
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed Apr 20 08:38:47 2016 nicolas trognot
** Last update Sun Apr 24 21:55:21 2016 come grellard
*/

#include <stdlib.h>
#include "lemin.h"

t_path_list		*add_to_list(int *list, t_path_list **old,
				     t_lemin *lemin)
{
  t_path_list		*new;
  int			i;

  if ((new = malloc(sizeof(t_path_list))) == NULL)
    return (NULL);
  new->next = *old;
  *old = new;
  new->nb_idx = list[0];
  new->is_ok = 1;
  if ((new->idx_list = malloc(sizeof(int) * new->nb_idx)) == NULL)
    return (NULL);
  if ((new->idx_ants_list = malloc(sizeof(int)
				   * (new->nb_idx + lemin->nb_ants))) == NULL)
    return (NULL);
  i = -1;
  while (++i < new->nb_idx + lemin->nb_ants)
    new->idx_ants_list[i] = 0;
  i = 0;
  while (++i < new->nb_idx)
    new->idx_list[i - 1] = list[i];
  new->nb_idx--;
  return (new);
}
