/*
** main_test.c for main_test.c in /home/wadel_n/test/tetris/check
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Thu Mar 17 11:28:28 2016 nicolas wadel
** Last update Fri Mar 25 17:35:01 2016 louis-emile uberti-ares
*/

#include "../include/tetris.h"

void	other_check(t_tetris *game, char *key)
{
  if (my_strcmp(key, game->left_key) == 0)
    game->check = move_left(game);
  if (my_strcmp(key, game->right_key) == 0)
    game->check = move_right(game);
  prompt_game(game);
}

void	play_tetris(t_tetris *game, char *key)
{
  int	**save;

  prompt_game(game);
  if (my_strcmp(key, game->turn_key) == 0)
    {
      save = rotate(game);
      if (save != game->shapeint && game->pieces[game->current].width
	  < game->board_rows && game->pieces[game->current].height
	  < game->pieces[game->current].width)
	game->shapeint = save;
    }
  else if ((my_strcmp(key, game->drop_key) == 0)
	   || (game->timer[4] % (20000 - game->level * 100) == 0))
    {
      if (move_downward(game) == 1)
	{
	  add_shape_to_field(game);
	  while ((game->board = check_line_completed(game))
		 && game->freeit == 0)
	    (void)-1;
	}
    }
  other_check(game, key);
}
