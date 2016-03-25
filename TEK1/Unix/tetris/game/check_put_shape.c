/*
** check_put_shape.c for check_put_shape in /home/wadel_n/test/tetris/check/test
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sat Mar 19 16:10:02 2016 nicolas wadel
** Last update Sun Mar 20 19:31:36 2016 nicolas wadel
*/

#include "../include/tetris.h"

int	check_put_shape(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  while (i < game->pieces[game->current].height)
    {
      idx = 0;
      while (idx < game->pieces[game->current].width)
	{
	  if (game->board[i + game->starty][idx + game->startx] != 0
	      && game->shapeint[i][idx] != 0)
	    return (1);
	  idx++;
	}
      i++;
    }
  return (0);
}
