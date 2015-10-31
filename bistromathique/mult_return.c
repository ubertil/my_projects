/*
** mult_return.c for mult_return.c in /home/uberti_l/rendu/Piscine_C_evalexpr/multiplication
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 31 17:20:43 2015 louis-emile uberti-ares
** Last update Sat Oct 31 18:04:13 2015 louis-emile uberti-ares
*/

#include "include/bistromathique.h"
#include "include/my.h"

char	*my_final_return(t_mult *a, char *final)
{
  int	i;

  if (final[0] == '-')
    i = 1;
  else
    i = 0;
  while (a->tmp1 != EOS)
    {
      final[i] = a->tmp1[i];
      i = i + 1;
    }
  free(a);
  return (final);
}
