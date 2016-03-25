/*
** check_lefward.c for leftward in /home/wadel_n/test/tetris/check
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Thu Mar 17 11:40:55 2016 nicolas wadel
** Last update Tue Mar 22 11:54:03 2016 nicolas wadel
*/

#include "../include/tetris.h"

int	check_leftward(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  while (i < game->pieces[game->current].height)
    {
      idx = 0;
      while (idx < game->pieces[game->current].width)
	{
	  if (game->startx < 1
	      || (game->shapeint[i][idx] != 0 &&
		  game->board[i + game->starty][idx + game->startx - 1] != 0))
	    return (1);
	  idx++;
	}
      i++;
    }
  return (0);
}

int	check_rightward(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  while (i < game->pieces[game->current].height)
    {
      idx = 0;
      while (idx < game->pieces[game->current].width)
	{
	  if (game->startx + game->pieces[game->current].width + 1
	      > game->board_rows ||
	      (game->shapeint[i][idx] != 0 &&
	       game->board[i + game->starty][idx + game->startx + 1] != 0))
	    return (1);
	  idx++;
	}
      i++;
    }
  return (0);
}

int	check_downward(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  game->score += game->level;
  while (i < game->pieces[game->current].height)
    {
      idx = 0;
      while (idx < game->pieces[game->current].width)
	{
	  if (game->starty + game->pieces[game->current].height + 1
	      > game->board_lines
	      || (game->shapeint[i][idx] != 0 &&
		  game->board[i + game->starty + 1][idx + game->startx] != 0))
	    return (1);
	  idx++;
	}
      i++;
    }
  return (0);
}
