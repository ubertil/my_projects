/*
** free_all.c for free_all in /home/uberti_l/rendu/PSU_2015_my_select
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Dec  1 21:46:05 2015 louis-emile uberti-ares
** Last update Tue Dec  1 22:06:55 2015 louis-emile uberti-ares
*/

#include "include/my_select.h"
#include <stdlib.h>

void		free_all(t_arg *a)
{
  t_arg		*tmp;

  tmp = a;
  while (tmp != NULL)
    {
      tmp = a;
      a = a->next;
      free(tmp);
    }
  free(a);
}
