/*
** infin_add.c for infin_add.c in /home/trogno_n/rendu/Piscine_C_infinadd
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Mon Oct 19 09:12:42 2015 nicolas trognot
** Last update Sat Oct 31 18:02:29 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/bistromathique.h"
#include "include/my.h"

void	my_put_in_final_return(t_add_sub *a, char what_to_put)
{
  if ((a->final_return[a->final_rank - 1] == '0') &&
      (a->final_return[a->final_rank - 2] == '-'))
    {
      a->final_rank = a->final_rank - 1;
    }
  else
    {
      if ((a->final_return[a->final_rank - 1] == '0') &&
	  (a->final_rank - 1 == 0))
	{
	  a->final_rank = a->final_rank - 1;
	}
    }
  a->final_return[a->final_rank] = what_to_put;
  a->final_rank = a->final_rank + 1;
}

t_add_sub	*init_my_a(char **av)
{
  t_add_sub	*a;

  a = malloc(sizeof(t_add_sub));
  if (a == NULL)
    return (NULL);
  a->l1 = my_strlen(av[1]);
  a->l2 = my_strlen(av[2]);
  a->n1 = 0;
  a->n2 = 0;
  a->n_res = 0;
  a->carry = 0;
  a->tmp_is_higher = 0;
  a->final_rank = 0;
  if (a->l1 > a->l2)
    a->final_return = malloc(a->l1 + 1);
  else
    a->final_return = malloc(a->l2 + 1);
  if (a->final_return == NULL)
    return (NULL);
  return (a);
}

int	my_clean_str(char **av, int mode, t_add_sub *a, char s2)
{
  if (mode == 1)
    {
      if ((av[1][0] == '-') || (av[1][0] == '+'))
	av[1][0] = '0';
      if ((av[2][0] == '-') || (av[2][0] == '+'))
	av[2][0] = '0';
    }
  else
    {
      if ((a->tmp_is_higher == '-') && (s2 >= '0'))
	my_put_in_final_return(a, '-');
    }
  return (0);
}

int	my_do_op_sub(t_add_sub *a, char **av, int r, char *display)
{
  int	b;

  b = my_do_op_sub_cmp(av[1], av[2], 0, 0);
  a->l1 = my_strlen(av[b + 1]);
  a->l1 = (av[b + 1][0] == '-') ? (a->l1 - 1) : (a->l1);
  a->l2 = my_strlen(av[(1 - b) + 1]);
  a->l2 = (av[(1 - b) + 1][0] == '-') ? (a->l2 - 1) : (a->l2);
  a->tmp_is_higher = av[b + 1][0];
  my_clean_str(av, 1, 0, '0');
  while ((a->l1 > 0) || (a->l2 > 0))
    {
      a->n1 = (a->l1 > 0) ? (av[b + 1][my_strlen(av[b + 1]) - r] - 48) : (0);
      if (a->l2 > 0)
	a->n2 = av[(1 - b) + 1][my_strlen(av[(1 - b) + 1]) - r] - 48 + a->carry;
      else
	a->n2 = a->carry;
      a->n_res = (a->n1 - a->n2 >= 0) ? (a->n1 - a->n2) : (a->n1 - a->n2 + 10);
      a->carry = (a->n_res != (a->n1 - a->n2)) ? (1) : (0);
      display[r - 1] = a->n_res + 48;
      a->l1 = a->l1 - 1;
      a->l2 = a->l2 - 1;
      r = r + 1;
    }
  my_display_sub(2, av, display, a);
  return (0);
}

char		*add_sub(char *n1, char *n2)
{
  char		*display;
  char		*v[3];
  t_add_sub	*a;

  v[1] = my_strdup(n1);
  v[2] = my_strdup(n2);
  a = init_my_a(v);
  my_display_sum(1, v, "null", a);
  if (a->l1 > a->l2)
    display = malloc(a->l1 + 1);
  else
    display = malloc(a->l2 + 1);
  if (((*v[1] == '-') && (*v[2] != '-')) || ((*v[1] != '-') && (*v[2] == '-')))
    my_do_op_sub(a, v, 1,  display);
  else
    my_do_op_sum(a, v, 1, display);
  if (a->final_rank == 0)
    my_put_in_final_return(a, '0');
  if ((a->final_return[0] == '-') && (a->final_return[1] == '0') &&
      (a->final_return[2] == EOS))
    return ("0");
  else
    return (a->final_return);
}
