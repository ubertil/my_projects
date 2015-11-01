/*
** bistromathique.c for bistromathique in /home/uberti_l/rendu/Piscine_C_bistromathique
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 31 17:34:18 2015 louis-emile uberti-ares
** Last update Sun Nov  1 12:32:37 2015 louis-emile uberti-ares
*/

#include "include/bistromathique.h"
#include "include/my.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
  char	*expr;
  char	*operators;
  int	i;

  i = 0;
  if ((ac != 4) || (av[1][0] == EOS) || (av[2][0] == EOS ) || (av[3][0] == EOS))
    {
      my_putstr(USAGE_MSG);
      return (1);
    }
  expr = get_expr(my_getnbr(av[3]));
  if (is_expr_valid(ac, av, expr) != expr)
    return (1);
  operators = malloc(my_strlen(av[2]));
  while (av[2][i] != EOS)
    {
      operators[i] = av[2][i];
      i = i + 1;
    }
  //eval_expr(expr, operators);
  my_putchar(EOL);
}
