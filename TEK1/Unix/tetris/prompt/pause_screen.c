/*
** pause_screen.c for pause_screen in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Mar 16 14:14:47 2016 Louis-Emile Uberti
** Last update Mon Mar 21 17:14:59 2016 nicolas wadel
*/

#include <ncurses.h>
#include "../include/tetris.h"

void		init_pause(t_tetris *game)
{
  game->pause_screen = subwin(stdscr, 7, 34, (LINES / 2) - 3, (COLS / 2) - 17);
  wborder(game->pause_screen, '|', '|', '-', '-', '/', '\\', '\\', '/');
  put_spaces((COLS / 2) - 16, (LINES / 2) - 2,
	     (COLS / 2) + 16, (LINES / 2) + 3);
  mvprintw((LINES / 2), (COLS / 2) - 7, "Game Paused");
  wrefresh(game->pause_screen);
  game->pause = 0;
}

int		pause_screen(t_tetris *game)
{
  char		key[20];

  init_pause(game);
  key[0] = '\0';
  while (my_strcmp(key, game->pause_key) != 0 && get_terminal_size(game) == 0)
    {
      if (my_strcmp(key, game->quit_key) == 0)
	{
	  game->pause = 1;
	  escape_game(game);
	  return (0);
	}
      getstr(key);
    }
  werase(game->pause_screen);
  delwin(game->pause_screen);
  return (0);
}
