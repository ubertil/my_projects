/*
** escape_game.c for escape_game in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Mar 15 20:36:25 2016 Louis-Emile Uberti
** Last update Fri Mar 25 17:09:55 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/tetris.h"

void	init_escape(t_tetris *game)
{
  game->quit = subwin(stdscr, 7, 34, (LINES / 2) - 3, (COLS / 2) - 17);
  wborder(game->quit, '|', '|', '-', '-', '/', '\\', '\\', '/');
  put_spaces((COLS / 2) - 16, (LINES / 2) - 2,
	     (COLS / 2) + 16, (LINES / 2) + 3);
  mvprintw((LINES / 2) - 1, (COLS / 2) - 16, "  Do You Really Want To Quit ? ");
  mvprintw((LINES / 2) + 1, (COLS / 2) - 10, "YES");
  attron(A_UNDERLINE);
  mvprintw((LINES / 2) + 1, (COLS / 2) + 6, "NO");
  wrefresh(game->quit);
}

void    put_spaces(int x, int y, int end_x, int end_y)
{
  int   save;

  save = x;
  while (y < end_y)
    {
      x = save;
      while (x < end_x)
	mvprintw(y, x++, " ");
      y++;
    }
}

int     select_choice(t_tetris *game, char *key, int i)
{
  if ((my_strcmp(key, game->left_key) == 0)
      || (my_strcmp(key, game->right_key)) == 0)
    {
      if (i == 0)
	{
	  attroff(A_UNDERLINE);
	  mvprintw((LINES / 2) + 1, (COLS / 2) + 6, "NO");
	  attron(A_UNDERLINE);
	  mvprintw((LINES / 2) + 1, (COLS / 2) - 10, "YES");
	  i = 1;
	}
      else if (i == 1)
	{
	  attroff(A_UNDERLINE);
	  mvprintw((LINES / 2) + 1, (COLS / 2) - 10, "YES");
	  attron(A_UNDERLINE);
	  mvprintw((LINES / 2) + 1, (COLS / 2) + 6, "NO");
	  i = 0;
	}
    }
  refresh();
  return (i);
}

void		escape_game(t_tetris *game)
{
  char		key[20];
  int		i;
  int		nb;

  i = 0;
  init_escape(game);
  (game->music_play == 1) ? (force_quit_music()) : (0);
  while (my_strcmp(key, "\r") != 0)
    {
      get_terminal_size(game);
      nb = read(0, key, 10);
      key[nb] = '\0';
      i = select_choice(game, key, i);
      refresh();
    }
  game->music_play = 0;
  attroff(A_UNDERLINE);
  werase(game->quit);
  delwin(game->quit);
  if (game->pause == 1 && i == 0)
    return;
  (i == 1) ? (endwin(), save_highscore(game),
	      free_all(game), exit(0)) : (game->music_play = 1,
					  music(), the_game(game));
}
