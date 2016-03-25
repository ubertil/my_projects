/*
** check_descente.c for check_descente in /home/wadel_n/test/tetris
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Thu Mar 17 10:01:05 2016 nicolas wadel
** Last update Mon Mar 21 17:00:20 2016 nicolas wadel
*/

#include "../include/tetris.h"

void		get_new_shape(t_tetris *game)
{
  which_tetrimino(game, 1);
  get_shape(game);
}

int		**add_shape_to_field(t_tetris *game)
{
  int		i;
  int		idx;

  i = 0;
  while (i < game->pieces[game->current].height)
    {
      idx = 0;
      while (idx < game->pieces[game->current].width)
	{
	  if (game->shapeint[i][idx] != 0)
	    game->board[i + game->starty][idx + game->startx]
	      = game->shapeint[i][idx];
	  idx++;
	}
      i++;
    }
  get_new_shape(game);
  game->starty = 0;
  game->startx = game->board_rows / 2
    - game->pieces[game->current].width / 2;
  return (game->board);
}
