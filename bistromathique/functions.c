/*
** tools.c for tools in /home/wuilla_j/rendu/Piscine_C_evalexpr
**
** Made by Julien Wuillaume
** Login   <wuilla_j@epitech.net>
**
** Started on  Thu Oct 22 08:51:28 2015 Julien Wuillaume
** Last update Sun Nov  1 22:24:16 2015 Julien Wuillaume
*/

#include "include/bistromathique.h"

int	get_token(char c)
{
  if ((c == 37) || (c == 42) || (c == 43) || (c == 45) || (c == 47))
    return (1);
  if (c == 40)
    return (2);
  if (c == 41)
    return (3);
  return (0);
}

int	get_sign(char c)
{
  if ((c == 45) || (c == 43))
    return (1);
  if ((c == 37) || (c == 42) || (c == 47))
    return (2);
  return (0);
}

int	stack_write(t_stack **stack, char *buffer, char c)
{
  int	token;
  int	last_token;

  token = get_token(c);
  last_token = 0;
  if (stack[0]->buff_idx > 0)
    last_token = get_token(buffer[stack[0]->buff_idx - 1]);
  if (token == 0)
    {
      *stack[stack[0]->stack_idx]->value = c;
      stack[0]->stack_idx++;
    }
  if (token == 1)
    {
      if (last_token == 1)
	{
	  if (get_sign(buffer[stack[0]->buff_idx - 1]) >= get_sign(c))
	    {
	      *stack[stack[0]->stack_idx]->value = buffer[stack[0]->buff_idx - 1];
	      buffer[stack[0]->buff_idx - 1] = 0;
	      buffer[stack[0]->buff_idx] = c;
	      stack[0]->stack_idx++;
	    }
	}
      buffer[stack[0]->buff_idx] = c;
      stack[0]->buff_idx = (stack[0]->buff_idx) + 1;
    }
}

int	buffer_write(t_stack **stack, char *buffer, char c)
{
  buffer[stack[0]->buff_idx] = c;
  stack[0]->buff_idx++;
}
