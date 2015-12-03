/*
** final_return.c for final_return in /home/uberti_l/rendu/PSU_2015_my_select
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Dec  2 15:16:36 2015 louis-emile uberti-ares
** Last update Wed Dec  2 15:23:32 2015 louis-emile uberti-ares
*/

#include "include/my_select.h"
#include <stdlib.h>

void		final_return(int *selection, char **av, int size)
{
  char		**new;
  int		i;

  i = 0;
  if ((new = malloc(size * sizeof(**new))) == NULL)
    exit (84);
  while (size != 0)
    {
      if ((new[i] = malloc(my_strlen(av[selection[i]]) * sizeof(*new))) == NULL)
	exit (84);
      new[i] = av[selection[i]];
      my_putstr(new[i]);
      i = i + 1;
      size = size - 1;
    }
}
