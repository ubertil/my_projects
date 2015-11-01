/*
** is_expr_valid.c for is_expr_valid in /home/uberti_l/rendu/Piscine_C_evalexpr
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct 22 11:41:29 2015 louis-emile uberti-ares
** Last update Sun Nov  1 09:57:24 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/bistromathique.h"

int	par_checker(char *expr, char *to_use)
{
  int	tab[3];

  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  while (expr[tab[2]] != EOS)
    {
      if (expr[tab[2]] == to_use[0])
	tab[0] = tab[0] + 1;
      if (expr[tab[2]] == to_use[1])
	tab[1] = tab[1] + 1;
      if (((expr[tab[2]] == to_use[0]) && (expr[tab[2] + 1] == to_use[1]))
	|| ((expr[tab[2]] == to_use[1]) && (expr[tab[2] + 1] == to_use[0])))
	{
	  my_putstr(PAR_MSG);
	  return (1);
	}
      tab[2] = tab[2] + 1;
    }
  if (tab[0] != tab[1])
    {
      my_putstr(PAR_MSG);
      return (1);
    }
  return (0);
}

int	check_expr_twice(char *expr, char *to_use, char *base, char *operators)
{
  int	tab[3];

  tab[0] = 0;
  if (my_strlen(operators) != 7)
    {
      my_putstr(OPERATORS_MSG);
      return (2);
    }
  while (expr[tab[0]] != EOS)
    tab[0] = tab[0] + 1;
  if ((expr[tab[0] - 1] == operators[3]) || (expr[tab[0] - 1] == operators[4])
      || (expr[tab[0] - 1] == operators[5])
      || (expr[tab[0] - 1] == operators[6])
      || (expr[tab[0] - 1] == operators[7]))
    return (2);
}

char	my_get_to_use(char *expr, char *to_use, char *base, char *operators)
{
  int	tab[3];

  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  if (check_expr_twice(expr, to_use, base,  operators) == 2)
   {
     my_putstr(ERROR_MSG);
     return (1);
   }
  while (operators[tab[2]] != EOS)
    {
      to_use[tab[0]] = operators[tab[2]];
      tab[2] = tab[2] + 1;
      tab[0] = tab[0] + 1;
    }
  while (base[tab[1]] != EOS)
    {
      to_use[tab[0]] = base[tab[1]];
      tab[1] = tab[1] + 1;
      tab[0] = tab[0] + 1;
    }
  check_base_ops(expr, to_use);
}

int	check_base_ops(char *expr, char *to_use)
{
  int	tab[3];

  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  while (expr[tab[1]] != EOS)
    {
      while (to_use[tab[0]] != EOS)
	{
	  if (to_use[tab[0]] == expr[tab[1]])
	    {
	      tab[0] = 0;
	      tab[2] = tab[2] + 1;
	      break;
	    }
	  tab[0] = tab[0] + 1;
	}
      tab[1] = tab[1] + 1;
    }
  if (tab[2] != my_strlen(expr))
    {
      my_putstr(ERROR_MSG);
      return (1);
    }
  par_checker(expr, to_use);
}

int	is_expr_valid(int ac, char **av)
{
  char	*expr;
  char	*to_use;

  if ((ac != 4) || (av[1][0] == EOS) || (av[2][0] == EOS) || (av[3][0] == EOS))
    {
      my_putstr(USAGE_MSG);
      return (1);
    }
  expr = get_expr(my_getnbr(av[3]));
  if (my_strlen(expr) < my_getnbr(av[3]))
    {
      my_putstr(R_MSG);
      return (1);
    }
  if ((expr[0] == av[2][1]) || (expr[0] == av[2][4]) || (expr[0] == av[2][5])
      || (expr[0] == av[2][6]))
    {
      my_putstr(ERROR_MSG);
      return (1);
    }
  to_use = malloc(my_strlen(av[1]) + my_strlen(av[2]));
  if (to_use != NULL)
    my_get_to_use(expr, to_use, av[1], av[2]);
  free(to_use);
  return (expr);
}
