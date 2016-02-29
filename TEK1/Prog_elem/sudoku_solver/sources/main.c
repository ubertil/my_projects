/*
** main.c for main in /home/uberti_l/rendu/Prog_elem/sudoki-bi/sources
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Feb 27 09:28:05 2016 louis-emile uberti-ares
** Last update Sun Feb 28 21:52:54 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/sudoku.h"

int		main(void)
{
  t_sudoku	*sudoku;

  if ((sudoku = malloc(sizeof(t_sudoku))) == NULL)
    return (1);
  sudoku->nb_grids = 0;
  sudoku->idx = 0;
  if (check_grids(sudoku) == 1)
    {
      fprintf(stdin, "MAP ERROR\n\n");
      free(sudoku);
      return (1);
    }
  if (sudoku->idx != 1)
    {
      fprintf(stdin, "MAP ERROR\n\n");
      free(sudoku);
      return (1);
    }
  free(sudoku);
  return (0);
}
