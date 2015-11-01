/*
** get_expr.c for get_expr in /home/uberti_l/rendu/Piscine_C_evalexpr/le_renouveau
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct 22 14:23:01 2015 louis-emile uberti-ares
** Last update Sun Nov  1 18:56:08 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

char	*get_expr(unsigned int size)
{
  int	tab[2];
  char	buffer[1];
  char	*expr;

  tab[0] = 0;
  tab[1] = 1;
  expr = malloc(size + 1);
  if (expr != NULL)
    {
      while ((tab[1] != 0) && (size != 0))
	{
	  tab[1] = read(0, buffer, 1);
	  if (tab[1] != 0)
	    {
	      expr[tab[0]] = buffer[0];
	      tab[0] = tab[0] + 1;
	    }
	  size = size - 1;
	}
      expr[size + 1] = EOS;
      return (expr);
    }
  else
    return(NULL);
}
