/*
** get_argv.c for get_argv in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Nov 27 13:30:18 2015 louis-emile uberti-ares
** Last update Tue Dec  1 21:45:16 2015 louis-emile uberti-ares
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my_select.h"

void		print(t_arg *a)
{
  t_arg		*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit (84);
  tmp = a->next;
  while (tmp != a)
    {
      my_putstr(tmp->arg);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

t_arg		*init_arg()
{
  t_arg		*a;

  if ((a = malloc(sizeof(t_arg))) == NULL)
    return (NULL);
  a->prev = a;
  a->next = a;
  a->arg = 0;
  return (a);
}

void		init_my_argv(char *str,  t_arg *a)
{
  t_arg		*tmp;

  if ((tmp = malloc(sizeof(t_arg))) == NULL)
    exit (84);
  tmp->arg = str;
  tmp->prev = a->prev;
  tmp->next = a;
  a->prev->next = tmp;
  a->prev = tmp;
}
