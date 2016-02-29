/*
** check_map.c for check_map in /home/wadel_n/test/sudoku/sudoki-bi/sources
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sun Feb 28 10:45:30 2016 nicolas wadel
** Last update Sun Feb 28 21:08:08 2016 louis-emile uberti-ares
*/

#include "../include/sudoku.h"

int	check_map_line(t_sudoku *sudoku)
{
  int	i;
  int	j;
  int	nb;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  nb = sudoku->grid[i][j];
	  if (nb != 0)
	    if (line_checker(i, nb, j, sudoku) == 1)
	      return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_map_column(t_sudoku *sudoku)
{
  int	i;
  int	j;
  int	nb;

  j = 0;
  while (j < 9)
    {
      i = 0;
      while (i < 9)
	{
	  nb = sudoku->grid[i][j];
	  if (nb != 0)
	    if (column_checker(j, nb, i, sudoku) == 1)
	      return (1);
	  i++;
	}
      j++;
    }
  return (0);
}

int	check_map_block(t_sudoku *sudoku)
{
  int	x;
  int	y;
  int	nb;

  y = 0;
  while (y < 9)
    {
      x = 0;
      while (x < 9)
	{
	  nb = sudoku->grid[y][x];
	  if (nb != 0)
	    if (block_checker(x, y, nb, sudoku) == 1)
	      return (1);
	  x++;
	}
      y++;
    }
  return (0);
}
