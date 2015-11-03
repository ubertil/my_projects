/*
** swap_elem.c for swap_elem in /home/uberti_l/Pushswap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov  3 10:42:54 2015 louis-emile uberti-ares
** Last update Tue Nov  3 11:10:04 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <time.h>
#include "include/my.h"

void	swap_elem(int *array, int index1, int index2)
{
  int	temp;

  temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

void	sort_numbers(int *array, int size)
{
  int	idx;

  idx = 0;
  while (idx != size - 1)
    {
      if (array[idx] > array[idx + 1])
	{
	  swap_elem(array, idx, (idx + 1));
	  sort_numbers(array , size);
	}
      idx = idx + 1;
    }
}

int	main(int ac, char **av)
{
  int	tab[my_getnbr(av[1])];
  int	idx;

  srand(time(NULL));
  idx = 0;
  while (idx != my_getnbr(av[1]))
    {
      tab[idx] = rand() % my_getnbr(av[2]);
      idx = idx + 1;
    }
  idx = 0;
  while (idx != my_getnbr(av[1]))
    {
      my_put_nbr(tab[idx]);
      my_putchar(',');
      idx = idx + 1;
    }
  sort_numbers(tab, my_getnbr(av[1]));
  idx = 0;
  my_putchar('\n');
  while (idx != my_getnbr(av[1]))
    {
      my_put_nbr(tab[idx]);
      my_putchar(',');
      idx = idx + 1;
    }
  return (0);
}
