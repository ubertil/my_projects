/*
** sudoku.h for sudoku in /home/uberti_l/rendu/Prog_elem/sudoki-bi/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Feb 27 09:26:36 2016 louis-emile uberti-ares
** Last update Sun Feb 28 21:08:27 2016 louis-emile uberti-ares
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_
#include <stdio.h>

typedef struct		s_sudoku
{
  int			grid[9][9];
  int			nb_grids;
  int			idx;
  size_t		size;
}			t_sudoku;

void			get_grid_from_terminal(int row, char *line,
						t_sudoku *sudoku);
void			print_grids(t_sudoku *sudoku);
int			sudoku_core(t_sudoku *sudoku, int pos);
int			check_grids(t_sudoku *sudoku);
int			sudoku_solver(t_sudoku *sudoku, int pos);
int			check_line(int line, int nb, t_sudoku *sudoku);
int			check_block(int x, int y, int nb, t_sudoku *sudoku);
int			check_column(int column, int nb, t_sudoku *sudoku);
int			check_map_line(t_sudoku *sudoku);
int			check_map_column(t_sudoku *sudoku);
int			check_map_block(t_sudoku *sudoku);
int			line_checker(int line, int nb, int pos, t_sudoku *sudoku);
int			column_checker(int column, int nb, int pos, t_sudoku *sudoku);
int			block_checker(int x, int y, int nb, t_sudoku *sudoku);
int			step_2(int x, int y, int nb, t_sudoku *sudoku);

#endif /* !SUDOKU_H_ */
