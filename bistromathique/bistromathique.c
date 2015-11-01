/*
** bistromathique.c for bistromathique in /home/uberti_l/rendu/Piscine_C_bistromathique
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 31 17:34:18 2015 louis-emile uberti-ares
** Last update Sun Nov  1 14:36:44 2015 louis-emile uberti-ares
*/

#include "include/bistromathique.h"
#include "include/my.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
  char	*expr;

  if ((ac != 4) || (av[1][0] == EOS) || (av[2][0] == EOS ) || (av[3][0] == EOS))
    {
      my_putstr(USAGE_MSG);
      return (1);
    }
  if (my_strlen(av[2]) != 7)
    {
      my_putstr(OPERATORS_MSG);
      return (1);
    }
  if (my_strlen(av[1]) != 10)
    {
      my_putstr(PLS_MSG);
      return (1);
    }
  expr = get_expr(my_getnbr(av[3]));
  if (is_expr_valid(ac, av, expr) != expr)
    return (1);
  else
    //my_putstr(eval_expr(expr, av[2]));
  return (0);
}
