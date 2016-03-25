/*
** which_tetrimino.c for which_tetrimino in /home/uberti_l/rendu/Unix/PSU_2015_tetris/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Mar 20 19:01:59 2016 louis-emile uberti-ares
** Last update Sun Mar 20 23:02:03 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "../include/tetris.h"

void	which_tetrimino(t_tetris *game, int touchdown)
{
  if (touchdown == 0)
    {
      while ((game->current = rand() % game->nb_pieces) == 0)
	game->current = 1 + rand() % game->nb_pieces;
      while ((game->next_piece = rand() % game->nb_pieces)
	     == game->current)
	game->next_piece = rand() % game->nb_pieces;
    }
  else if (touchdown == 1)
    {
      game->current = game->next_piece;
      while ((game->next_piece = rand() % game->nb_pieces) == game->current)
	game->next_piece = rand() % game->nb_pieces;
    }
  if (game->pieces[game->current].width == 0)
    which_tetrimino(game, 0);
}
