/*
** my_flags.c for my_flags in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Nov 26 16:28:08 2015 louis-emile uberti-ares
** Last update Sun Nov 29 21:55:25 2015 louis-emile uberti-ares
*/

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "include/my.h"

void		my_show_dir(t_dir *a)
{
  t_dir		*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit (84);
  tmp = a;
  while (tmp != NULL)
    {
      my_printf("\033[34;01m%s\033[00m  ", tmp->file);
      tmp = tmp->next;
    }
  my_putchar('\n');
}

void		my_show_all(t_dir *a)
{
  int		count;
  t_dir		*tmp;
  struct dirent	*dent;
  DIR		*dir;

  count = 0;
  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit (84);
  tmp = a;
  while (tmp != NULL)
    {
      dir = opendir(tmp->file);
      if (dir != NULL)
	while ((dent = readdir(dir)) != NULL)
	    count = count + get_total(dent->d_name);
      count = count / 2;
      my_printf("total %d\n", count);
      display_core(tmp->file);
      tmp = tmp->next;
    }
  free(tmp);
}

void		my_show_recursive(t_dir *a)
{
}

void		my_show_reverse(t_dir *a)
{
}

void		my_show_time(t_dir *a)
{
  t_dir		*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit (84);
  tmp = a;
  while (tmp != NULL)
    {
    }
  free(tmp);
}
