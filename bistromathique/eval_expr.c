/*
** eval_expr.c for eval_expr in /home/wuilla_j/rendu/Piscine_C_evalexpr
**
** Made by Julien Wuillaume
** Login   <wuilla_j@epitech.net>
**
** Started on  Wed Oct 21 10:05:10 2015 Julien Wuillaume
** Last update Sun Nov  1 22:22:28 2015 Julien Wuillaume
*/

#include <stdlib.h>
#include "include/bistromathique.h"
#include "include/my.h"

void		handle_parenthesis(char *buffer, t_stack **stack)
{
  while ((get_token(buffer[stack[0]->buff_idx]) != 2))
    {
      *stack[stack[0]->stack_idx]->value = buffer[stack[0]->buff_idx];
      buffer[stack[0]->buff_idx] = 0;
      stack[0]->buff_idx--;
      stack[0]->stack_idx++;
    }
  buffer[stack[0]->buff_idx] = 0;
}

void		buffer_to_stack(char *buffer, t_stack **stack)
{
  while (stack[0]->buff_idx > 0)
    {
      if (stack[0]->buff_idx >= 0)
	{
	  *stack[stack[0]->stack_idx]->value = buffer[stack[0]->buff_idx - 1];
	  buffer[stack[0]->buff_idx] = 0;
	  stack[0]->buff_idx--;
	  stack[0]->stack_idx++;
	}
    }
}

int		str_to_npi(t_stack **stack, char *str)
{
  char		*buffer;
  int		token;
  int		i;

  i = 0;
  buffer = malloc(my_strlen(str) * sizeof(char));
  if (buffer == NULL)
    return (1);
  while (i < my_strlen(str))
    {
      token = get_token(str[i]);
      if ((token == 0) || (token == 1))
	stack_write(stack, buffer, str[i]);
      if (token == 2)
	buffer_write(stack, buffer, str[i]);
      if (token == 3)
	handle_parenthesis(buffer, stack);
      i = i + 1;
    }
  buffer_to_stack(buffer, stack);
  free(buffer);
}

t_stack		**initialize_struct(t_stack **stack, char *str, char *operators)
{
  int		i;

  i = 0;
  while (i < my_strlen(str) + get_sign_count(str) + 1)
    {
      stack[i] = malloc(sizeof(t_stack));
      stack[i]->value = malloc(sizeof(char));
      stack[i]->tmp = malloc(my_strlen(str) + get_sign_count(str) + 1);
      i = i + 1;
    }
  i = 0;
  while (i <= 6)
    {
      stack[i]->operators = operators[i];
      i = i + 1;
    }
  stack[0]->stack_idx = 0;
  stack[0]->buff_idx = 0;
  return (stack);
}

char		*eval_expr(char *str, char *operators)
{
  t_stack	**stack;
  char		*expr;
  int		i;

  str[13] = EOL;
  i = 0;
  stack = malloc((my_strlen(str) + get_sign_count(str)) * sizeof(t_stack));
  expr = malloc((my_strlen(str) + get_sign_count(str) + 1));
  if (stack == NULL)
    return (1);
  format_expr(expr, str);
  if (initialize_struct(stack, expr, operators) == NULL)
    return (1);
  str_to_npi(stack, expr);
  expr_to_tab(stack);
  do_op(stack);
  while (i < stack[0]->tmp_idx)
    {
      my_putstr(stack[i]->tmp);
      my_putchar('\n');
      i = i + 1;
    }
  free(stack);
  free(expr);
  return (*stack[0]->tmp);
}
