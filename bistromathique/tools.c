/*
** tools.c for tools.c in /home/trogno_n/rendu/Piscine_C_infinadd
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Mon Oct 19 09:12:42 2015 nicolas trognot
** Last update Sat Oct 31 18:05:56 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/bistromathique.h"
#include "include/my.h"

int	my_display_sum(int mode, char **av, char *display, t_add_sub *a)
{
  if (mode == 1)
    {
      if ((av[1][0] == '-') && (av[2][0] == '-'))
	{
	  av[1][0] = '0';
	  av[2][0] = '0';
	  my_put_in_final_return(a, '-');
	}
    }
  else
    {
      display = my_revstr(display);
      if (a->carry != 0)
	my_put_in_final_return(a, a->carry + 48);
      mode = 0;
      while (display[mode] != EOS)
	{
	  if ((mode != 0) || ((display[mode] >= '0') && (mode == 0)))
	    if (display[mode] != '+')
	      my_put_in_final_return(a, display[mode]);
	  mode = mode + 1;
	}
    }
  return (0);
}

int	my_display_sub(int mode, char **av, char *display, t_add_sub *a)
{
  int	is_done;

  my_clean_str(av, 2, a, display[0]);
  is_done = 0;
  display = my_revstr(display);
  mode = 0;
  while (display[mode] != EOS)
    {
      if (display[mode] > '0')
	is_done = 1;
      if ((mode != 0) || ((display[mode] != '0') && mode == 0))
	if (is_done == 1)
	  {
	    my_put_in_final_return(a, display[mode]);
	  }
      mode = mode + 1;
    }
  if (is_done == 0)
    {
      my_put_in_final_return(a, '0');
    }
  return (0);
}

int	my_do_op_sum(t_add_sub *a, char **av, int rank, char *display)
{
  while ((a->l1 > 0) || (a->l2 > 0))
    {
      a->n1 = (a->l1 > 0) ? (av[1][my_strlen(av[1]) - rank] - 48) : (0);
      a->n2 = (a->l2 > 0) ? (av[2][my_strlen(av[2]) - rank] - 48) : (0);
      if ((a->n1 + a->n2 + a->carry) <= 9)
	{
	  a->n_res = (a->n1 + a->n2 + a->carry);
	  (a->carry > 0) ? (a->carry = 0) : (a->carry = a->carry);
	}
      else
	{
	  a->n_res = (a->n1 + a->n2 + a->carry - 10);
	  a->carry = 1;
	}
	display[rank - 1] = (a->n_res + 48);
	a->l1 = a->l1 - 1;
	a->l2 = a->l2 - 1;
	rank = rank + 1;
    }
  my_display_sum(2, av, display, a);
  return (0);
}

int	my_do_op_sub_cmp(char *n1, char *n2, int s1, int s2)
{
  int	len1;
  int	len2;

  s1 = (n1[0] == '-') ? (1) : (0);
  s2 = (n2[0] == '-') ? (1) : (0);
  len1 = (s1 == 1) ? (my_strlen(n1) - 1) : (my_strlen(n1));
  len2 = (s2 == 1) ? (my_strlen(n2) - 1) : (my_strlen(n2));
  if (len2 > len1)
    return (1);
  if (len1 > len2)
    return (0);
  while ((n1[s1] != EOS) && (n2[s2] != EOS))
    {
      if (n1[s1] > n2[s2])
	return (0);
      if (n2[s2] > n1[s1])
	return (1);
      s1 = s1 + 1;
      s2 = s2 + 1;
    }
  return (1);
}
