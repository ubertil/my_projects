/*
** get_grids_from_terminal.c for get_grid_from_terminal in /home/uberti_l/rendu/Prog_elem/sudoki-bi
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Feb 27 14:11:31 2016 louis-emile uberti-ares
** Last update Sun Feb 28 21:27:00 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <string.h>
#include "../include/sudoku.h"

void		get_grid_from_terminal(int row, char *line, t_sudoku *sudoku)
{
  int		i;
  int		idx;
  char		letter[1];

  i = 0;
  idx = 0;
  if (strcmp(line, "|------------------|\n") == 0)
      return;
  while (line[idx])
    {
      letter[0] = line[idx];
      if ((idx != 0) && (idx % 2 == 0) && (idx != 20))
	sudoku->grid[row][i++] = atoi(letter);
      idx++;
    }
}
