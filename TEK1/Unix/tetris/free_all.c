/*
** free_all.c for free_all in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Mar 14 15:36:22 2016 louis-emile uberti-ares
** Last update Sat Mar 19 23:57:03 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/tetris.h"

void		free_wrong_shape(t_tetris *game, int idx)
{
  int		i;

  i = 0;
  while (game->pieces[idx].form[i] != NULL)
    free(game->pieces[idx].form[i++]);
}

void		free_board(t_tetris *game)
{
  int		i;

  i = 0;
  while (i < game->board_rows)
    free(game->board[i++]);
  free(game->board);
}

void		free_pieces(t_tetris *game)
{
  int		i;

  i = 0;
  while (i != game->nb_pieces)
    (game->pieces[i++].form != NULL) ? (free_wrong_shape(game, i)) : (0);
}

void		free_all(t_tetris *game)
{
  // free_board(game);
  free(game->left_key);
  free(game->right_key);
  free(game->turn_key);
  free(game->quit_key);
  free(game->drop_key);
  free(game->pause_key);
  free(game->pieces);
  free(game);
}
