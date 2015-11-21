/*
** pushswap.c for pushswap in /home/uberti_l/pushswap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 17 16:45:31 2015 louis-emile uberti-ares
** Last update Wed Nov 18 17:30:49 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>

int		init_my_tab(int nb, t_swap **a)
{
  t_swap	*tmp;

  tmp = malloc(sizeof(*tmp));
  if (tmp == NULL)
    return (1);
  tmp->nb = nb;
  tmp->next = *a;
  *a = tmp;
  return (0);
}

int		main(int ac, char **av)
{
  t_list	*a;
  int		i;

  i = ac;
  if ((a = malloc(sizeof(t_list))) == NULL)
    return (1);
  a->l_a = NULL;
  a->l_b = NULL;
  a->perm = ac - 1;
  a->idx_la = ac - 1;
  while (i > 1)
    {
      init_my_tab((my_getnbr(av[i - 1])), &a->l_a);
      i = i - 1;
    }
  pushswap(a);
  return (0);
}
