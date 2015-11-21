/*
** 101pong.c for 101pong in /home/uberti_l/rendu/101pong
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov  2 20:20:17 2015 louis-emile uberti-ares
** Last update Mon Nov  9 13:11:14 2015 louis-emile uberti-ares
** Last update Tue Nov  3 16:32:48 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include/pong.h"
#include "include/my.h"

t_stock	*speed_vector(t_stock *a)
{
  a->x = a->x1 - a->x0;
  a->y = a->y1 - a->y0;
  a->z = a->z1 - a->z0;
  return (a);
}

t_stock	*ball_coordinates(t_stock *a)
{
  a->xt = (a->n * (a->x)) + a->x1;
  a->yt	= (a->n * (a->y)) + a->y1;
  a->zt = (a->n * (a->z)) + a->z1;
  return (a);
}

int	my_final_display(t_stock *a)
{
  printf("The speed vector coordinates are :\n(");
  printf("%0.2f;%0.2f;%0.2f)\n", a->x, a->y, a->z);
  printf("At time t+");
  printf("%d", a->n);
  printf(", ball coordinates will be :\n(");
  printf("%0.2f;%0.2f;%0.2f)\n", a->xt, a->yt, a->zt);
  if (a->mode == 0)
    {
      printf("The ball won't reach the bat.\n");
      free(a);
      return (0);
    }
  else
    {
      printf("%s%0.2f degrees\n", "The incidence angle is :\n", a->angle);
      free(a);
      return (0);
    }
}

int	my_calculus(t_stock *a)
{
  a = speed_vector(a);
  a = ball_coordinates(a);
  if (a->z * a->z1 >= 0)
    a->mode = 0;
  else
    {
      a->mode = 1;
      a->norme_v = sqrt(pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2));
      a->angle = (((acos(a->z / a->norme_v) * 180) / M_PI) - 90);
      a->angle = sqrt(pow(a->angle, 2));
    }
  my_final_display(a);
  return (0);
}

void	my_init(char **av)
{
  t_stock	*a;

  a = malloc(sizeof(t_stock));
  if (a == NULL)
    exit (84);
  else
    {
      a->x0 = atof(av[1]);
      a->y0 = atof(av[2]);
      a->z0 = atof(av[3]);
      a->x1 = atof(av[4]);
      a->y1 = atof(av[5]);
      a->z1 = atof(av[6]);
      a->n = atof(av[7]);
    }
  my_calculus(a);
}
