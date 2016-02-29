/*
** check_grid.c for check_grid in /home/wadel_n/test/sudoku
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sat Feb 27 09:41:30 2016 nicolas wadel
** Last update Sat Feb 27 14:33:34 2016 louis-emile uberti-ares
*/

#include "../include/sudoku.h"

int	sudoku_solver(t_sudoku *sudoku, int pos)
{
  int	x;
  int	y;
  int	i;

  if (pos == 9*9)
    return (0);
  x = pos % 9;
  y = pos / 9;
  i = 1;
  if (sudoku->grid[y][x] != 0)
    return (sudoku_solver(sudoku, pos + 1));
  while (i <= 9)
    {
      if (check_line(y, i, sudoku) == 0 && check_column(x, i,  sudoku) == 0
	  && check_block(x, y, i, sudoku) == 0)
	{
	  sudoku->grid[y][x] = i;
	  if (sudoku_solver(sudoku, pos + 1) == 0)
	    return (0);
	}
      i++;
    }
  sudoku->grid[y][x] = 0;
  return (1);
}
