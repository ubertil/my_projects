/*
** check_block.c for check_block in /home/wadel_n/test/sudoku
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sat Feb 27 09:24:24 2016 nicolas wadel
** Last update Sat Feb 27 14:32:07 2016 louis-emile uberti-ares
*/

#include "../include/sudoku.h"

int	check_block(int x, int y, int nb, t_sudoku *sudoku)
{
  int	i;
  int	a;
  int	idx;
  int	b;


  i = y - (y % 3);
  a = i;
  while (i < a + 3)
    {
      idx = x - (x % 3);
      b = idx;
      while (idx < b + 3)
	if (sudoku->grid[i][idx++] == nb)
	  return (1);
      i++;
    }
  return (0);
}
