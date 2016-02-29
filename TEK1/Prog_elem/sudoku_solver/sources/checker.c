/*
** checker.c for checker in /home/wadel_n/test/sudoku/sudoki-bi/sources
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sun Feb 28 20:10:24 2016 nicolas wadel
** Last update Sun Feb 28 20:56:31 2016 louis-emile uberti-ares
*/

#include "../include/sudoku.h"

int	line_checker(int line, int nb, int pos, t_sudoku *sudoku)
{
  int	i;

  i = 0;
  while (i < pos)
    if (sudoku->grid[line][i++] == nb)
      return (1);
  i = pos + 1;
  while (i < 9)
    if (sudoku->grid[line][i++] == nb)
      return (1);
  return (0);
}

int	column_checker(int column, int nb, int pos, t_sudoku *sudoku)
{
  int	i;

  i = 0;
  while (i < pos)
    if (sudoku->grid[i++][column] == nb)
      return (1);
  i = pos + 1;
  while (i < 9)
    if (sudoku->grid[i++][column] == nb)
      return (1);
  return (0);
}

int	step_2(int x, int y, int nb, t_sudoku *sudoku)
{
  int	i;
  int	idx;
  int	a;
  int	b;

  i = x + 1;
  a = y - (y % 3) + 3;
  while (i < a)
    {
      idx = y + 1;
      b = x - (x % 3) + 3;
      while (idx < b)
	if (sudoku->grid[i][idx++] == nb)
	  return (1);
      i++;
    }
  return (0);
}

int	block_checker(int x, int y, int nb, t_sudoku *sudoku)
{
  int	i;
  int	a;
  int	idx;
  int	b;

  i = y - (y % 3);
  a = i;
  while (i < a + 3 && i < y)
    {
      idx = x - (x % 3);
      b = idx;
      while (idx < b + 3 && idx < x)
	if (sudoku->grid[i][idx++] == nb)
	  return (1);
      i++;
    }
  if (step_2(x, y, nb, sudoku) == 1)
    return (1);
  return (0);
}
