/*
** main.c for main in /home/uberti_l/rendu/104intersection
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Dec 14 10:03:52 2015 louis-emile uberti-ares
** Last update Fri Dec 25 16:10:42 2015 louis-emile uberti-ares
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int		print_first(int flag, int info)
{
  switch (flag)
    {
    case 1 :
      printf("sphere of radius %d\n", info);
      break;
    case 2 :
      printf("cylinder of radius %d\n", info);
      break;
    case 3 :
      printf("cone of %d degree angle", info);
      break;
    }
  return (0);
}

int		*get_tab(int ac, char **av, int *tab)
{
  int		i;

  i = 1;
  while (i < ac)
    {
      if (atof(av[i]) != atoi(av[i]))
	{
	  printf("Error : Float value not accepted\n");
	  exit(84);
	}
      else
	{
	  tab[i - 1] = atoi(av[i]);
	  i += 1;
	}
    }
  return (tab);
}

void		check_argv(int ac, char **av)
{
  int		i;
  int		idx;

  i = 1;
  idx = 0;
  while (i < ac)
    {
      while (av[i][idx] != '\0')
	{
	  if ((av[i][idx] < '0'|| av[i][idx] > '9') && (av[i][idx] != '-'))
	    {
	      printf("Error : Argument %d is not a number\n", i);
	      exit(84);
	    }
	  idx += 1;
	}
      i += 1;
      idx = 0;
    }
}

float		*fill_cylinder(int *tab, float *tab2, int nb)
{
  int		i;

  (nb == 1) ? (i = 3) : (i = 6);
  while (i != 0)
    {
    }
  return (tab2);
}

float		*fill_cone(int *tab, float *tab2, int nb)
{
  int		i;

  (nb == 1) ? (i = 3) : (i = 6);
  while (i != 0)
    {
    }
  return (tab2);
}

float		*fill_sphere(int *tab, float *tab2, int nb)
{
  int		i;

  (nb == 1) ? (i = 3) : (i = 6);
  while (i != 0)
    {
    }
  return (tab2);
}

void		print_intersection(int *tab)
{
  int		nb;
  float		*tab2;

  nb = 0;
  tab2 = malloc(6 *sizeof(float *));
  if (nb == 0)
    {
      printf("No intersection point.\n");
      exit(0);
    }
  else if (nb == 1)
    {
      switch (tab[0])
	{
	case 1:
	  tab2 = fill_sphere(tab, tab2, 1);
	  break;
	case 2:
	  tab2 = fill_cylinder(tab, tab2, 1);
	  break;
	case 3:
	  tab2 = fill_cone(tab, tab2, 1);
	  break;
	}
      printf("1 intersection point :\n");
      printf("(%0.3f, %0.3f, %0.3f)\n", tab2[0], tab2[1], tab2[2]);
      exit(0);
    }
  else if (nb == 2)
    {
      switch (tab[0])
	{
	case 1:
	  tab2 = fill_sphere(tab, tab2, 2);
	  break;
	case 2:
	  tab2 = fill_cylinder(tab, tab2, 2);
	  break;
	case 3:
	  tab2 = fill_cone(tab, tab2, 2);
	  break;
	}
      printf("2 intersection points :\n");
      printf("(%0.3f, %0.3f, %0.3f)\n", tab2[0], tab2[1], tab2[2]);
      printf("(%0.3f, %0.3f, %0.3f)\n", tab2[3], tab2[4], tab2[5]);
      exit(0);
    }
}

int		main(int ac, char **av)
{
  int		*tab;

  if (ac != 9)
    {
      printf("Error : Too few arguments\nMinimum is 9\n");
      exit (84);
    }
  else
    {
      check_argv(ac, av);
      tab = malloc(8 * sizeof(int *));
      tab = get_tab(ac, av, tab);
      if (tab[0] < 1 || tab[0] > 3)
	{
	  printf("Error : Unknown flag\n");
	  exit (84);
	}
      print_first(tab[0], tab[7]);
      printf("straight line going through the (%d,%d,%d) point and of direction vector (%d,%d,%d)\n",
	     tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
      print_intersection(tab);
    }
}
