/*
** functions2.c for functions2 in /home/wuilla_j/rendu/Piscine_C_evalexpr
**
** Made by Julien Wuillaume
** Login   <wuilla_j@epitech.net>
**
** Started on  Sat Oct 31 18:09:05 2015 Julien Wuillaume
** Last update Sun Nov  1 22:23:13 2015 Julien Wuillaume
*/

#include "include/bistromathique.h"

int	get_sign_count(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != EOL)
    {
      if ((str[i] == 37)  \
	  || (str[i] == 42) \
	  || (str[i] == 43) \
	  || (str[i] == 45) \
	  || (str[i] == 47))
	{
	  count = count + 1;
	  }
      i = i + 1;
      }
  return (count);
}

int	format_expr(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (src[i] != EOL)
    {
      if ((get_token(src[i]) == 1) && (get_token(src[i + 1]) == 1))
	src[i] = 126;
      i = i + 1;
    }
  i = 0;
  while (src[i] != EOL)
    {
      dest[j] = src[i];
      if ((get_token(src[i + 1]) == 1))
	{
	  j = j + 1;
	  dest[j] = ' ';
	}
      i = i + 1;
      j = j + 1;
      dest[j] = EOL;
    }
}

int	expr_to_tab(t_stack **stack)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < stack[0]->stack_idx)
    {
      my_strcat(stack[j]->tmp, stack[i]->value);
      if (get_token(*stack[i]->value) == 1 \
	  && (get_token(*stack[i + 1]->value) != 0) \
	  || *stack[i + 1]->value == ' ' \
	  || get_token(*stack[i + 1]->value) == 1)
	{
	  j = j + 1;
	  if (*stack[i + 1]->value == ' ')
	    i = i + 1;
	}
      i = i + 1;
    }
  stack[0]->tmp_idx = j;
}

char    *do_op(t_stack **stack)
{
  int	i;
  t_op	my_op[] =
    {
      {&add_sub},
      {&add_sub},
      {&multiplication},
      {&my_division},
      {&my_modulo},
    };

  i = 0;
  while (i < stack[0]->tmp_idx)
    {
      if (get_token(*stack[i]->tmp) == 1)
	{
	  *stack[i]->tmp = my_op[i]->func(stack[i - 2]->tmp, stack[i - 1]->tmp);
	  *stack[i - 2]->tmp = 0;
	  *stack[i - 1]->tmp = 0;
	}
      i = i + 1;
    }
}
