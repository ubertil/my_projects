/*
** next_box_size.c for next_box_size in /Users/uberti_l/rendu/Unix/PSU_2015_tetris/prompt
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Mar 18 16:20:50 2016 Louis-Emile Uberti
** Last update Sun Mar 20 00:45:59 2016 louis-emile uberti-ares
*/

#include "../include/tetris.h"

int		max_next_size(t_tetris *game)
{
  int		i;

  i = 0;
  game->biggest[0] = game->pieces[i].width;
  game->biggest[1] = game->pieces[i].height;
  while (i < game->nb_pieces)
    {
      if (game->biggest[0] < game->pieces[i].width)
	game->biggest[0] = game->pieces[i].width;
      if (game->biggest[1] < game->pieces[i].height)
	game->biggest[1] = game->pieces[i].height;
      i += 1;
    }
  if ((game->biggest[0] > game->board_rows)
      || (game->biggest[1] > game->board_lines)
      || (game->biggest[0] + game->board_rows + 31 > COLS)
      || (game->biggest[1] + game->board_lines + 1 > LINES))
    {
      endwin();
      my_putstr_err("Error: Window is too small for the game\nExiting.\n");
      my_putstr_err("Please consider setting a bigger terminal\n");
      return (1);
    }
  return (0);
}
