/*
** prompt_game.c for prompt_game in /home/wadel_n/test/tetris/check
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Fri Mar 18 10:37:25 2016 nicolas wadel
** Last update Sun Mar 20 19:36:49 2016 nicolas wadel
*/

#include <ncurses.h>
#include "../include/tetris.h"

void	prompt_shape(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  while (i < game->pieces[game->current].height)
    {
      idx = 0;
      while (idx < game->pieces[game->current].width)
	{
	  attron(COLOR_PAIR(game->shapeint[i][idx]));
	  if (game->shapeint[i][idx] != 0)
	    mvprintw(i + game->starty + 1, idx + game->startx + 27, "*");
	  idx++;
	}
      i++;
    }
  attron(COLOR_PAIR(7));
}

void	prompt_game(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  while (i < game->board_lines)
    {
      idx = 0;
      while (idx < game->board_rows)
	{
	  attron(COLOR_PAIR((game->board[i][idx])));
	  if (game->board[i][idx] != 0)
	    mvprintw(i + 1, idx + 27, "*");
	  else
	    mvprintw(i + 1, idx + 27, " ");
	  idx++;
	}
      i++;
    }
  attron(COLOR_PAIR(7));
  prompt_shape(game);
}
