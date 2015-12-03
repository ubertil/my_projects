/*
** main.c for main in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Nov 18 10:28:26 2015 louis-emile uberti-ares
** Last update Sun Nov 29 18:33:08 2015 louis-emile uberti-ares
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

void		free_all(t_dir **a)
{
  t_dir		*tmp;
  t_dir		*tmp2;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit (84);
  if ((tmp2 = malloc(sizeof(*tmp))) == NULL)
    exit (84);
  if (*a != NULL)
    {
      tmp = (*a)->next;
      while (tmp != NULL)
	{
	  tmp2 = tmp;
	  tmp = tmp->next;
	  free(tmp2);
	}
    }
  free(*a);
  free(tmp);
  free(tmp2);
  *a = NULL;
}

void		get_flags(t_stock *a, char **av, int ac)
{
  int		i;
  int		count;
  int		idx;

  i = 1;
  idx = 0;
  count = 0;
  while (i < ac)
    {
      if (av[i][0] == '-')
	while (av[i][idx] != '\0')
	  {
	    a->flags[count] = av[i][idx];
	    count = count + 1;
	    idx = idx + 1;
	  }
      idx = 0;
      i = i + 1;
    }
  if (count == 0)
    a->flags[0] = ' ';
}

void		my_malloc_flags(t_stock *a, char **av, int ac)
{
  static int	i;
  static int	count;
  static int	idx;

  i = 1;
  count = 1;
  idx = 0;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  while (av[i][idx] != '\0')
	    {
	      count = count + 1;
	      idx = idx + 1;
	    }
	}
      i = i + 1;
      idx = 0;
    }
  if ((a->flags = malloc(count * sizeof(char *))) == NULL)
    exit(84);
  get_flags(a, av, ac);
}

int		main(int ac, char **av)
{
  t_stock	*a;

  if ((a = malloc(sizeof(t_stock))) == NULL)
    return (1);
  if ((find_help(ac, av) == 1) || (parceur(ac, av) == 1))
    return (1);
  init_my_dir(ac, av, a);
  my_malloc_flags(a, av, ac);
  my_core(a);
  free_all(&a->dir);
  free(a->dir);
  free(a->flags);
  free(a);
  return(0);
}
