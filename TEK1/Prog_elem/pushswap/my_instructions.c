/*
** my_instructions.c for my_instructions in /home/uberti_l/pushswap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 17 17:01:16 2015 louis-emile uberti-ares
** Last update Wed Nov 18 17:30:04 2015 louis-emile uberti-ares
*/

#include <unistd.h>
#include "include/my.h"

void		my_pa(t_swap **l_a, t_swap **l_b, t_list *a)
{
  init_my_tab(l_b[0]->nb, l_a);
  *l_b = l_b[0]->next;
  a->idx_la = a->idx_la + 1;
  write (1, "pa", 2);
}

void		my_pb(t_swap **l_a, t_swap **l_b, t_list *a)
{
  init_my_tab(l_a[0]->nb, l_b);
  *l_a = l_a[0]->next;
  a->idx_la = a->idx_la - 1;
  write (1, "pb", 2);
}

void		my_sa(t_list *a)
{
  int		tmp;

  tmp = a->l_a->nb;
  a->l_a->nb = a->l_a->next->nb;
  a->l_a->next->nb = tmp;
  write (1, "sa", 2);
}

int		check_sucess(t_list *a)
{
  t_swap	*tmp;

  tmp = a->l_a;
  if (a->idx_la != a->perm)
    return (1);
  while (tmp->next != NULL)
    {
      if (tmp->nb > tmp->next->nb)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		check_la(t_list *a)
{
  t_swap	*tmp;

  tmp = a->l_a;
  while (tmp->next != NULL)
    {
      if (tmp->nb > tmp->next->nb)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void		pushswap(t_list *a)
{
  int		i;

  i = 0;
  while (check_sucess(a) == 1)
    {
      if (i != 0)
	write (1, " ", 1);
      if (a->l_a->nb > a->l_a->next->nb)
	my_sa(a);
      else
	{
	  if (check_la(a) == 0)
	    my_pa(&a->l_a, &a->l_b, a);
	  else
	    my_pb(&a->l_a, &a->l_b, a);
	}
      i = i + 1;
    }
  write (1, "\n", 1);
}
