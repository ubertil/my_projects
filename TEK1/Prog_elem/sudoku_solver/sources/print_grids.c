/*
** print_grids.c for print_grids in /home/uberti_l/rendu/Prog_elem/sudoki-bi/sources
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Feb 27 09:43:21 2016 louis-emile uberti-ares
** Last update Sun Feb 28 19:17:11 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include "../include/sudoku.h"

void		print_grids(t_sudoku *sudoku)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  if (sudoku->nb_grids > 0)
    printf("####################\n");
  printf("%s", "|------------------|\n");
  while (y != 9)
    {
      x = 0;
      printf("|");
      while (x != 9)
	printf(" %d", sudoku->grid[y][x++]);
      printf("|\n");
      y += 1;
    }
  printf("%s\n", "|------------------|");
  sudoku->nb_grids += 1;
}
