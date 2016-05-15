/*
** launch_feeder.c for launch_feeder.c in /home/trognot/rendu/CPE/CPE_2015_Lemin/srcs/algo
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed Apr 20 21:31:25 2016 nicolas trognot
** Last update Sun Apr 24 16:10:54 2016 nicolas trognot
*/

#include <stdlib.h>
#include "lemin.h"

void		print_movements(t_lemin *lemin,
				int *tab)
{
  int		i;
  int		u;

  i = 0;
  u = 0;
  while (i < lemin->nb_ants)
    {
      if (tab[i] != -1)
	{
	  if (u != 0)
	    my_putstr(" ");
	  u = 1;
	  my_putstr("P");
	  my_putnbr(i + 1);
	  my_putstr("-");
	  my_putstr(get_name(lemin, tab[i]));
	}
      i++;
    }
  if (lemin->list->nb_idx == 2 &&
      lemin->nb_ants_end < lemin->nb_ants)
    my_putstr(" ");
  else
    my_putstr("\n");
}

void		shift_ants(t_path_list *list, int *tab)
{
  int		i;
  t_path_list	*curr;

  curr = list;
  while (curr)
    {
      i = curr->nb_idx - 1;
      while (i > 0)
	{
	  curr->idx_ants_list[i] = curr->idx_ants_list[i - 1];
	  if (curr->idx_ants_list[i] != 0)
	    tab[curr->idx_ants_list[i] - 1] = curr->idx_list[i];
	  i--;
	}
      curr->idx_ants_list[0] = 0;
      curr = curr->next;
    }
}

void		push_ant(t_path_list *list, t_lemin *lemin)
{
  t_path_list	*curr;

  curr = list;
  while (curr)
    {
      if (curr->is_ok == 1)
	if (lemin->nb_ants_start > 0)
	  if (curr->idx_ants_list[0] == 0)
	    {
	      curr->idx_ants_list[0] =
		lemin->nb_ants - lemin->nb_ants_start + 1;
	      lemin->nb_ants_start--;
	    }
      curr = curr->next;
    }
}

void		check_feeder(t_path_list *list, t_lemin *lemin)
{
  t_path_list	*curr;

  curr = list;
  while (curr)
    {
      if (curr->idx_ants_list[curr->nb_idx - 1] != 0)
	{
	  curr->idx_ants_list[curr->nb_idx - 1] = 0;
	  lemin->nb_ants_end++;
	}
      curr = curr->next;
    }
}

void		launch_feeder(t_path_list *list, t_lemin *lemin)
{
  int		*tab;
  int		i;

  if ((list) &&
      ((tab = malloc(sizeof(int) * (lemin->nb_ants + 2))) != NULL))
    while (lemin->nb_ants_end < lemin->nb_ants)
      {
	i = 0;
	while (i < lemin->nb_ants + 2)
	  {
	    tab[i] = -1;
	    i++;
	  }
	sanitize_list(lemin->list, lemin);
	push_ant(lemin->list, lemin);
	shift_ants(list, tab);
	check_feeder(list, lemin);
	print_movements(lemin, tab);
      }
}
