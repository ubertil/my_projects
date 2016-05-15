/*
** free_all.c for free_all in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr  7 14:43:38 2016 louis-emile uberti-ares
** Last update Sun Apr 24 21:23:42 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "lemin.h"

int	free_history_visited(int *is_visited_new, int *newhistory)
{
  free(is_visited_new);
  free(newhistory);
  return (0);
}

void	free_args(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

int	free_two_rooms(char *s1, char *s2)
{
  free(s1);
  free(s2);
  return (0);
}

void		free_tpath_list(t_lemin *lemin)
{
  t_path_list	*curr;

  while ((curr = lemin->list) != NULL)
    {
      lemin->list = lemin->list->next;
      free(curr->idx_ants_list);
      free(curr->idx_list);
      free(curr);
    }
  free(curr);
}

void		free_struct(t_lemin *lemin)
{
  int		i;
  t_rooms	*curr;

  i = 0;
  if (lemin->got_matrix == 2)
    {
      while (i < lemin->nb_rooms)
	free(lemin->matrix[i++]);
      i = 0;
      while (lemin->names[i] != NULL)
	free(lemin->names[i++]);
      free(lemin->names);
      free(lemin->matrix);
    }
  while ((curr = lemin->rooms) != NULL)
    {
      lemin->rooms = lemin->rooms->next;
      free(curr->room_name);
      free(curr);
    }
  free(curr);
  free_tpath_list(lemin);
  free(lemin);
}
