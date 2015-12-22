/*b
** parceur.c for parceur in /home/uberti_l/rendu/103architect
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Dec  9 13:27:20 2015 louis-emile uberti-ares
** Last update Tue Dec 15 17:18:06 2015 louis-emile uberti-ares
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/architect.h"

int		check_ratio(int ac, char **av)
{
  int		f_num;
  int		n_num;
  int		i;

  f_num = 0;
  n_num = 0;
  i = 1;
  while (i < ac)
    {
      if ((av[i][0] == '-') && (av[i][1] == 's' || av[i][1] == 'r' ||
			       av[i][1] == 'h' || av[i][1] == 't'))
	f_num += 1;
      if ((av[i][1] >= '0' && av[i][1] <= '9') || (av[i][0] >= '0' && av[i][0] <= '9'))
	n_num += 1;
      i = i + 1;
    }
  if (f_num >= n_num)
    {
      printf("Error : Too many flags compared to numbers\n");
      exit (84);
    }
  return (0);
}

void		insert_flags(char flag, t_fla **f)
{
  t_fla		*tmp;

  if ((flag != 't') && (flag != 'h') && (flag != 'r') && (flag != 's'))
    {
      printf("Error : Unknown flag used\nPlease check your arguments twice\n");
      exit(84);
    }
  tmp = malloc(sizeof(*tmp));
  tmp->flags = flag;
  tmp->next = *f;
  *f = tmp;
}

t_fla		*get_flags(int ac, char **av)
{
  int		i;
  int		no_flags;
  t_fla		*f;

  i = 1;
  no_flags = 1;
  f = malloc(sizeof(t_fla));
  f = NULL;
  while (i < ac)
    {
      if ((av[i][0] == '-') && (av[i][1] < '0' || av[i][1] > '9'))
	{
	  insert_flags(av[i][1], &f);
	  no_flags = 0;
	}
      i += 1;
    }
  if (no_flags == 1)
    {
      printf("Error : No flags were given !\nPlease retry using the appropriate ones\n");
      exit (84);
    }
  return (f);
}

void		insert_numbers(char *number, t_num **n)
{
  t_num		*tmp;
  float		to_put;

  to_put = atof(number);
  tmp = malloc(sizeof(*tmp));
  tmp->number = to_put;
  tmp->next = *n;
  *n = tmp;
}

t_num		*get_numbers(int ac, char **av)
{
  int		i;
  int		no_numbers;
  t_num		*n;

  i = 1;
  no_numbers = 1;
  n = NULL;
  while (i < ac)
    {
      if (av[i][0] >= '0' && av[i][0] <= '9')
	{
	  insert_numbers(av[i], &n);
	  no_numbers = 0;
	}
      i = i + 1;
    }
  if (no_numbers == 1)
    {
      printf("Error : No numbers were given !\nPlease retry using the appropriate ones\n");
      exit (84);
    }
  return (n);
}

t_info		*parseur_argv(int ac, char **av)
{
  t_info	*info;

  if (ac < 5)
    {
      printf("Error : Too few arguments entered\nPlease enter at least 4\n");
      exit (84);
    }
  else
    {
      info = malloc(sizeof(t_info));
      info->flags = get_flags(ac, av);
      info->numbers = get_numbers(ac, av);
      check_ratio(ac, av);
      return (info);
    }
}
