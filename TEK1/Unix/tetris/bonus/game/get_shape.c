/*
** get_shape.c for get_shape in /home/wadel_n/test/tetris/check/test
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Fri Mar 18 10:59:23 2016 nicolas wadel
** Last update Tue Mar 22 11:35:55 2016 nicolas wadel
*/

#include <stdlib.h>
#include "../include/tetris.h"

int	get_hight(t_tetris *game)
{
  int	i;

  i = 0;
  while (game->pieces[game->current].form[i] != NULL)
    i++;
  return (i);
}

int	get_len(t_tetris *game)
{
  int	i;
  int	idx;
  int	output;

  i = 0;
  output = 0;
  while (game->pieces[game->current].form[i] != NULL)
    {
      idx = 0;
      while (game->pieces[game->current].form[i][idx] != '\0')
	idx++;
      output < idx ? output = idx : 0;
      i++;
    }
  return (output);
}

int	**get_shape(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  game->pieces[game->current].height = get_hight(game);
  game->pieces[game->current].width = get_len(game);
  free(game->shapeint);
  if ((game->shapeint =
       malloc(sizeof(int *) * game->pieces[game->current].height)) == NULL)
    exit(84);
  while (i < game->pieces[game->current].height)
    if ((game->shapeint[i++] =
	 malloc(sizeof(int) * game->pieces[game->current].width)) == NULL)
      exit(84);
  i = -1;
  while (++i < game->pieces[game->current].height)
    {
      idx = -1;
      while (++idx < game->pieces[game->current].width)
	{
	  if (game->pieces[game->current].form[i][idx] == '*')
	    game->shapeint[i][idx] = game->pieces[game->current].color;
	  else
	    game->shapeint[i][idx] = 0;
	}
    }
  return (game->shapeint);
}
