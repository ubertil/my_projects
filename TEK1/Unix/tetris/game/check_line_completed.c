/*
** check_line_completed.c for check_line_completed in /home/wadel_n/test/tetris/check/test
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Fri Mar 18 14:03:25 2016 nicolas wadel
** Last update Mon Mar 21 19:02:18 2016 nicolas wadel
*/

#include "../include/tetris.h"

int	**erase_uper_field(t_tetris *game, int result)
{
  int	i;

  i = 0;
  game->freeit = 0;
  while (result > 0)
    {
      game->board[result] = game->board[result - 1];
      result--;
    }
  while (i < game->board_rows)
    game->board[0][i++] = 0;
  game->score_lines += 1;
  if (game->score_lines % 5 == 0 && game->level < 20)
    game->level += 1;
  game->score += 1 * game->level;
  return (game->board);
}

int	**check_line_completed(t_tetris *game)
{
  int	i;
  int	idx;
  int	check;

  i = 0;
  while (i < game->board_lines)
    {
      check = 0;
      idx = 0;
      while (idx < game->board_rows)
	{
	  if (game->board[i][idx] != 0)
	    check++;
	  idx++;
	  if (check == game->board_rows)
	    return (erase_uper_field(game, i));
	}
      i++;
    }
  game->freeit = 1;
  return (game->board);
}
