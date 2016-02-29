/*
** check_line.c for check_line in /home/wadel_n/test/sudoku
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sat Feb 27 09:19:22 2016 nicolas wadel
** Last update Sat Feb 27 14:31:12 2016 louis-emile uberti-ares
*/

#include "../include/sudoku.h"

int	check_line(int line, int nb, t_sudoku *sudoku)
{
  int	i;

  i = 0;
  while (i < 9)
    if (sudoku->grid[line][i++] == nb)
      return (1);
  return (0);
}
