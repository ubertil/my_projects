/*
** game_over.c for game_over in /home/wadel_n/rendu/PSU/PSU_2015_tetris
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sun Mar 20 03:50:08 2016 nicolas wadel
** Last update Sun Mar 20 17:31:37 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "../include/tetris.h"

void		game_over(t_tetris *game)
{
  WINDOW	*over;
  char		bin[1];

  over = subwin(stdscr, 7, 34, (LINES / 2) - 3, (COLS / 2) - 17);
  wborder(over, '|', '|', '-', '-', '/', '\\', '\\', '/');
  put_spaces((COLS / 2) - 16, (LINES / 2) - 2,
	     (COLS / 2) + 16, (LINES / 2) + 3);
  mvprintw((LINES / 2) - 1, (COLS / 2) - 16, "GAME OVER ");
  mvprintw((LINES / 2) + 1, (COLS / 2) - 16, "Press Enter to quit");
  wrefresh(over);
  refresh();
  game_over_sound();
  terminal_mode(0);
  read(0, bin, 1);
  while (bin[0] != '\r')
    read(0, bin, 1);
  werase(over);
  delwin(over);
  endwin();
  save_highscore(game);
  free_all(game);
  exit(0);
}
