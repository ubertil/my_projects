/*
** my_mult.c for my_mult in /home/uberti_l/rendu/Piscine_C_evalexpr/multiplication
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 26 10:15:31 2015 louis-emile uberti-ares
** Last update Sat Oct 31 18:04:36 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/bistromathique.h"

t_mult	*my_zero_checker(t_mult *a)
{
  int	temp;
  int	idx;

  if (a->l1 == 0)
    {
      a->l2 = a->l2 - 1;
      a->l1 = a->perm_l1;
      a->zero_toadd = a->zero_toadd + 1;
      a->carry = 0;
      if (a->zero_toadd > 0)
	{
	  idx = a->perm_idx + a->zero_toadd;
	  temp = a->zero_toadd;
	  while (temp > 0)
	    {
	      a->tmp2[idx] = '0';
	      idx = idx - 1;
	      temp = temp - 1;
	    }
	}
      a->tmp1 = add_sub(a->tmp1, a->tmp2);
      a->tmp_idx = a->perm_idx;
    }
  return (a);
}

char	*my_mult(char *n1, char *n2, t_mult *a, char *final)
{
  while (a->l2 > 0)
    {
      a->n1 = (n1[a->l1 - 1] - 48);
      a->n2 = (n2[a->l2 - 1] - 48);
      if ((a->n1 * a->n2) + a->carry <= 9)
	{
	  a->n_res = ((a->n1 * a->n2) + a->carry);
	  a->tmp2[a->tmp_idx] = a->n_res + 48;
	  a->carry = 0;
	}
      else
	{
	  a->n_res = (((a->n1 * a->n2) + a->carry) % 10);
	  a->carry = (((a->n1 * a->n2) + a->carry) / 10);
	  a->tmp2[a->tmp_idx] = a->n_res + 48;
	  if (a->l1 - 1 == 0)
	    a->tmp2[a->tmp_idx - 1] = a->carry + 48;
	}
      a->l1 = a->l1 - 1;
      a->tmp_idx = a->tmp_idx - 1;
      a = my_zero_checker(a);
    }
  my_final_return(a, final);
}

t_mult	*my_lenght_checker(char *n1, char *n2, t_mult *a, char *final)
{
  int	temp;

  if (my_do_op_sub_cmp(n1, n2, 0, 0) == 1)
    {
      a->tmp_idx = (a->l1 > a->l2) ? (a->l1) : (a->l2);
      temp = a->l1;
      a->l1 = a->l2;
      a->l2 = temp;
      a->perm_l1 = a->l1;
      my_putstr(my_mult(n2, n1, a, final));
      return (NULL);
    }
  return (a);
}

t_mult	*my_preparator(char *n1, char *n2, char *final)
{
  t_mult	*a;

  a = malloc(sizeof(t_mult));
  if (a == NULL)
    return (NULL);
  a->l1 = (n1[0] == '-') ? (my_strlen(n1) - 1) : (my_strlen(n1));
  a->l2 = (n2[0] == '-') ? (my_strlen(n2) - 1) : (my_strlen(n2));
  if (a->l1 == a->l2)
    a->tmp_idx = a->l1;
  else
    a->tmp_idx = (a->l1 > a->l2) ? (a->l1) : (a->l2);
  a->perm_l1 = a->l1;
  a->perm_idx = a->tmp_idx;
  a->carry = 0;
  a->zero_toadd = -1;
  a->tmp1 = malloc(a->l1 + a->l2);
  a->tmp1[0] = '0';
  a->tmp2 = malloc(a->l1 + a->l2);
  a->tmp2[0] = '0';
  if ((a->tmp1 == NULL) || (a->tmp2 == NULL))
    return (NULL);
  a = my_lenght_checker(n1, n2, a, final);
  if (a != NULL)
    my_putstr(my_mult(n1, n2, a, final));
}

int	multiplication(char *n1, char *n2)
{
  char	*final;

  final = malloc(my_strlen(n1) + my_strlen(n2));
  if ((n1[0] == '-') ^ (n2[0] == '-'));
  final[0] = '-';
  if ((n1[0] == '0') || (n2[0] == '0'))
    return (0);
  my_preparator(n1, n2, final);
}
