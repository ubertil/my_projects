/*
** main.c for main in /home/uberti_l/rendu/102cipher
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 16 10:51:37 2015 louis-emile uberti-ares
** Last update Sun Nov 29 16:58:20 2015 Nicolas Wadel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/cipher.h"

void		get_matrix_message(t_stock *a, char **av)
{
  int		i;
  int		k;
  char		*tmp;
  int		idx;

  i = 0;
  idx = 0;
  k = 0;
  tmp = malloc(my_strlen(av[1]) * sizeof(char *));
  while (av[1][i] != '\0')
    {
      if (av[1][i] >= '0' && av[1][i] <= '9')
	{
	  tmp[k] = av[1][i];
	  k = k + 1;
	  tmp[k] = '\0';
	}
      else
	{
	  a->matrix_message[idx] = atoi(tmp);
	  k = 0;
	  idx += 1;
	}
      i = i + 1;
    }
  a->matrix_message[idx] = atoi(tmp);
}

void		count_av(t_stock *a, char **av)
{
  int		idx;

  idx = 0;
  a->size_av1 = 1;
  while (av[1][idx] != '\0')
    {
      if (av[1][idx] == ' ')
	a->size_av1 = a->size_av1 + 1;
      idx = idx + 1;
    }
}

int		my_init(char **av)
{
  t_stock	*a;
  int		idx;

  idx = 0;
  a = malloc(sizeof(t_stock));
  a->mode = atoi(av[3]);
  if (a->mode == 0)
    {
      a->message = av[1];
      a->keyword = av[2];
      a->matrix_message = malloc((my_strlen(av[1]) + 2) * sizeof(int));
      while (av[1][idx] != '\0')

	{
	  a->matrix_message[idx] = av[1][idx];
	  idx = idx + 1;
	}
      a->encry_msg = malloc(my_strlen(av[1]) * sizeof(int));
      my_mode_encry(a);
    }
  else
    {
      a->keyword = av[2];
      a->message = malloc(my_strlen(av[1]) * sizeof(char));
      count_av(a, av);
      a->matrix_message = malloc((a->size_av1 + 1) * sizeof(int));
      get_matrix_message(a, av);
      my_mode_decry(a);
    }
  return (0);
}

int		main(int ac, char **av)
{
  if ((ac != 4) || (av[1][0] == '\0') || (av[2][0] == '\0') || (av[3][0] == '\0'))
    {
      printf("Usage : ./102cipher message key flag\n");
      exit (84);
    }
  if ((my_strlen(av[3]) != 1) || ((av[3][0] < '0') || (av[3][0] > '1')))
    {
      printf("Error : Please enter a correct flag\n");
      exit (84);
    }
  if (my_strlen(av[2]) > 16)
    {
      printf("Error : Maximum key lenght is 16\n");
      exit (84);
    }
  my_init(av);
  return (0);
}
