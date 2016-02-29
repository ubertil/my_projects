/*
** check_column.c for check_column in /home/wadel_n/test/sudoku
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sat Feb 27 09:21:41 2016 nicolas wadel
** Last update Sat Feb 27 14:31:23 2016 louis-emile uberti-ares
*/

#include "../include/sudoku.h"

int	check_column(int column, int nb, t_sudoku *sudoku)
{
  int	i;

  i = 0;
  while (i < 9)
    if (sudoku->grid[i++][column] == nb)
      return (1);
  return (0);
}
