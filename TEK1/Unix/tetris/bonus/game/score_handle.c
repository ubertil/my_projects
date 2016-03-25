/*
** score_handle.c for score_handle in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Mar 16 15:59:04 2016 Louis-Emile Uberti
** Last update Sun Mar 20 04:29:49 2016 louis-emile uberti-ares
*/

#include "../include/tetris.h"

void		score_handle(t_tetris *game)
{
  if (game->score_lines % 5 == 0)
    game->level += 1;
}
