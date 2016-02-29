/*
** check_grids.c for check_grids in /home/uberti_l/rendu/Prog_elem/sudoki-bi/sources
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Feb 27 10:05:21 2016 louis-emile uberti-ares
** Last update Sun Feb 28 21:47:04 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/sudoku.h"

int		check_first_line(char *line)
{
  if (strcmp(line, "|------------------|\n") == 0)
    return (0);
  else
    return (1);
}

int		check_valid_line(char *line)
{
  int		i;

  i = 0;
  if (strlen(line) > 21)
    return (1);
  while (line[i] != '\0')
    {
      if (((i == 0) || (i == 19)) && (line[i] == '|'))
	i += 1;
      else
	{
	  if ((i % 2 != 0) && (line[i] != ' '))
	      return (1);
	  else if (((i % 2 == 0) && ((line[i] < '0') || (line[i] > '9')))
		   && (i != 20))
	    {
	      if (line[i] == ' ')
		line[i] = '0';
	      else
		return (1);
	    }
	  i += 1;
	}
    }
  return (0);
}

int		check_grids(t_sudoku *sudoku)
{
  char		*line;

  line = NULL;
  while ((getline(&line, &sudoku->size, stdin)) > 0)
    {
      if (sudoku->idx == 10)
	{
	  sudoku_core(sudoku, 0);
	  getline(&line, &sudoku->size, stdin);
	  sudoku->idx = 0;
	}
      if ((sudoku->idx == 0) || (sudoku->idx % 11 == 0))
	{
	  if (check_first_line(line) == 1)
	    return (1);
	}
      else if (check_valid_line(line) == 1)
	return (1);
      get_grid_from_terminal(sudoku->idx - 1, line, sudoku);
      sudoku->idx += 1;
    }
  free(line);
  return (0);
}
