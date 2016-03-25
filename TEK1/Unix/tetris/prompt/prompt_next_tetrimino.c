/*
** prompt_next_tetrimino.c for prompt_next_tetrimino.c in /Users/uberti_l/rendu/Unix/PSU_2015_tetris/prompt
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Mar 18 23:27:19 2016 Louis-Emile Uberti
** Last update Sun Mar 20 20:17:07 2016 louis-emile uberti-ares
*/

#include <ncurses.h>
#include "../include/tetris.h"

void		prompt_next_tetrimino(t_tetris *game)
{
  int		idx;
  int		line;

  idx = 0;
  line = 2;
  if (game->hide_next == 1)
    return;
  else
    {
      put_spaces(game->board_rows + 32, 1,
		 game->board_rows + 32 + game->biggest[0],
		 2 + game->biggest[1]);
      attron(COLOR_PAIR(game->pieces[game->next_piece].color));
      while (game->pieces[game->next_piece].form[idx] != NULL)
	mvprintw(line++, 32 + game->board_rows,
		 game->pieces[game->next_piece].form[idx++]);
      attroff(COLOR_PAIR(game->pieces[game->next_piece].color));
    }
  wrefresh(game->next);
}
