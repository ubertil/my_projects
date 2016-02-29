/*
** sudoku_core.c for sudoku_core in /home/uberti_l/rendu/Prog_elem/sudoki-bi
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Feb 28 19:23:56 2016 louis-emile uberti-ares
** Last update Sun Feb 28 21:08:17 2016 louis-emile uberti-ares
*/

#include "../include/sudoku.h"

void		print_fake_map(t_sudoku *sudoku)
{
  if (sudoku->nb_grids > 0)
    printf("####################\n");
  printf("|------------------|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("|------------------|\n");
  sudoku->nb_grids += 1;
}

int		sudoku_core(t_sudoku *sudoku, int pos)
{
  if ((check_map_line(sudoku) == 1) ||
      (check_map_column(sudoku) == 1) ||
      (check_map_block(sudoku) == 1))
    print_fake_map(sudoku);
  else
    {
      sudoku_solver(sudoku, pos);
      print_grids(sudoku);
    }
  return (0);
}
