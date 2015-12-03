/*
** prepare_my_dir.c for prepare_my_dir in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Nov 27 13:30:18 2015 louis-emile uberti-ares
** Last update Sun Nov 29 18:41:41 2015 louis-emile uberti-ares
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

int		prepare_my_dir(char *path, t_dir **a)
{
  t_dir		*tmp;

  tmp = malloc(sizeof(*tmp));
  if (tmp == NULL)
    return (1);
  tmp->file = path;
  tmp->next = *a;
  *a = tmp;
  return (0);
}

int		init_my_dir(int ac, char **av, t_stock *a)
{
  int		i;
  int		idx;

  i = ac;
  idx = 0;
  a->dir = NULL;
  while (i > 1)
    {
      if (av[i - 1][0] != '-')
	{
	  prepare_my_dir(av[i - 1], &a->dir);
	  idx = idx + 1;
	}
      i = i - 1;
    }
  if (idx == 0)
    prepare_my_dir(".", &a->dir);
  return (0);
}
