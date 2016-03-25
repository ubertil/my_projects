/*
** check_rotation.c for check_rotation in /home/wadel_n/test/tetris/check
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Thu Mar 17 19:16:04 2016 nicolas wadel
** Last update Sun Mar 20 19:50:04 2016 nicolas wadel
*/

#include <stdlib.h>
#include <ncurses.h>
#include "../include/tetris.h"

int	**malloc_new_shape(t_tetris *game)
{
  int	i;
  int	**new_shape;
  int	tmp;

  i = 0;
  if ((new_shape =
	 malloc(sizeof(int *)* game->pieces[game->current].width)) == NULL)
    return (NULL);
  while (i < game->pieces[game->current].width)
    if ((new_shape[i++] =
	   malloc(sizeof(int) * game->pieces[game->current].height)) == NULL)
      return (NULL);
  tmp = game->pieces[game->current].width;
  game->pieces[game->current].width = game->pieces[game->current].height;
  game->pieces[game->current].height = tmp;
  return (new_shape);
}

int	**rotate_new_shape(int **new_shape, t_tetris *game)
{
  int	x;
  int	y;
  int	tmp;
  int	idx;
  int	i;

  i = 0;
  while (i < game->pieces[game->current].width)
    {
      idx = 0;
      while (idx < game->pieces[game->current].height)
	{
	  x = idx;
	  y = i;
	  tmp = y;
	  y = x;
	  x = game->pieces[game->current].width - 1 - tmp;
	  new_shape[y][x] = game->shapeint[i][idx];
	  idx++;
	}
      i++;
    }
  return (new_shape);
}

int	**backerror(t_tetris *game)
{
  int	tmp;

  tmp = game->pieces[game->current].width;
  game->pieces[game->current].width = game->pieces[game->current].height;
  game->pieces[game->current].height = tmp;
  return (game->shapeint);
}

int	**check_turn(t_tetris *game)
{
  int	**new_shape;
  int	i;
  int	idx;

  i = 0;
  if ((new_shape = malloc_new_shape(game)) == NULL)
    exit(84);
  new_shape = rotate_new_shape(new_shape, game);
  while (i < game->pieces[game->current].height)
    {
      idx = 0;
      while (idx < game->pieces[game->current].width)
	{
	  if (new_shape[i][idx] != 0 &&
	      game->board[i + game->starty][idx + game->startx] != 0)
	    return (backerror(game));
	  idx++;
	}
      i++;
    }
  game->shapeint = new_shape;
  return (game->shapeint);
}
