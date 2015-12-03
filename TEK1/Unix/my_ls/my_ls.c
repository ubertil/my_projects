/*
** my_ls.c for my_ls in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Nov 18 11:49:04 2015 louis-emile uberti-ares
** Last update Sun Nov 29 21:31:45 2015 louis-emile uberti-ares
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include "include/my.h"

static const t_format	show[7] =
{
  {'d', &my_show_dir},
  {'l', &my_show_all},
  {'R', &my_show_recursive},
  {'r', &my_show_reverse},
  {'t', &my_show_time},
  {' ', &my_show_basic},
};

int		check_ls(t_dir *a)
{
  t_dir		*tmp;
  struct stat	sb;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (1);
  tmp = a;
  while (tmp != NULL)
    {
      if (stat(tmp->file, &sb) == -1)
	{
	  my_putstr("my_ls: cannot access ");
	  my_printf("%s: No such file or directory\n", tmp->file);
	  return (1);
	}
      tmp = tmp->next;
    }
  free(tmp);
  return (0);
}

int		my_core(t_stock *a)
{
  int		i;

  i = 0;
  a->parceur = 0;
  if (check_ls(a->dir) == 1)
    return (1);
  while (a->flags[a->parceur] != '\0')
    {
      if (a->flags[a->parceur] == '-')
	a->parceur = a->parceur + 1;
      while (show[i].format != a->flags[a->parceur])
	i = i + 1;
      show[i].func(a->dir);
      a->parceur = a->parceur + 1;
      i = 0;
    }
  return (0);
}
