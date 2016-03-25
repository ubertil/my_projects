/*
** move.c for move in /home/wadel_n/test/tetris/check
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Fri Mar 18 10:24:15 2016 nicolas wadel
** Last update Sun Mar 20 19:34:59 2016 nicolas wadel
*/

#include "../include/tetris.h"

int	**rotate(t_tetris *game)
{
  int	**save;

  if ((save = check_turn(game)) == NULL)
    return (NULL);
  game->shapeint = save;
  return (game->shapeint);
}

int	move_downward(t_tetris *game)
{
  if (check_downward(game) == 1)
    return (1);
  game->starty++;
  return (0);
}

int	move_left(t_tetris *game)
{
  if (check_leftward(game) == 1)
    return (1);
  game->startx--;
  return (0);
}

int	move_right(t_tetris *game)
{
  if (check_rightward(game) == 1)
    return (1);
  game->startx++;
  return (0);
}
