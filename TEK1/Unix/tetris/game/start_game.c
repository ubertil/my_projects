/*
** print_hud.c for print_hud in /home/wadel_n/test/tetris
**
** Made by nicolas wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Mon Mar 14 16:45:42 2016 nicolas wadel
** Last update Mon Mar 21 18:34:26 2016 nicolas wadel
** Last update Sun Mar 20 04:06:49 2016 nicolas wadel
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/tetris.h"

void	init_board(t_tetris *game)
{
  int	i;
  int	idx;

  i = 0;
  while (i < game->board_lines)
    {
      idx = 0;
      while (idx < game->board_rows)
	game->board[i][idx++] = 0;
      i++;
    }
}

void	malloc_board(t_tetris *game)
{
  int	i;

  i = 0;
  if ((game->board = malloc(sizeof(int *) * game->board_lines)) == NULL)
    {
      terminal_mode(2);
      exit(84);
    }
  while (i < game->board_lines)
    {
      if ((game->board[i] = malloc(sizeof(int) * game->board_rows)) == NULL)
	{
	  terminal_mode(2);
	  exit(84);
	}
      i += 1;
    }
  init_board(game);
}

int	hud_core(t_tetris *game)
{
  game->next = subwin(stdscr, game->biggest[0] + 4, game->biggest[1] + 4,
		      0, game->board_rows + 30);
  wborder(game->next, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvprintw(0,  32 + game->board_rows, "NEXT");
  wrefresh(game->next);
  game->field = subwin(stdscr, game->board_lines + 2,
		       game->board_rows + 2, 0, 26);
  wborder(game->field, '|', '|', '-', '-', '-', '-', '-', '-');
  wrefresh(game->field);
  game->credits = subwin(stdscr, 11, 24, 7, 0);
  wborder(game->credits, '|', '|', '-', '-', '/', '\\', '\\', '/');
  refresh();
  prompt_tetris();
  return (0);
}

void		the_game(t_tetris *game)
{
  char		key[11];
  int		nb;

  while (check_put_shape(game) != 1)
    {
      nb = read(0, key, 10);
      key[nb] = '\0';
      if (my_strcmp(key, game->pause_key) == 0)
	pause_screen(game);
      if (my_strcmp(key, game->quit_key) == 0)
	escape_game(game);
      if (get_terminal_size(game) == 1)
	return;
      timer(game);
      prompt_credits(game);
      prompt_next_tetrimino(game);
      play_tetris(game, key);
      prompt_game(game);
      wborder(game->field, '|', '|', '-', '-', '-', '-', '-', '-');
      refresh();
    }
  game_over(game);
}

int	normal_game(t_tetris *game)
{
  initscr();
  timeout(0);
  srand(time(0));
  keypad(stdscr, TRUE);
  terminal_mode(1);
  terminal_mode(2);
  if (has_colors() == FALSE)
    {
      endwin();
      my_putstr_err("Error: Your terminal doesn't support colors! Exiting..\n");
      return (1);
    }
  if ((max_next_size(game) == 1) || (get_terminal_size(game) == 1))
    return (1);
  start_color();
  set_colors();
  noecho();
  curs_set(0);
  hud_core(game);
  which_tetrimino(game, 0);
  malloc_board(game);
  game->startx = game->board_rows / 2 - (game->pieces[game->current].width / 2);
  game->shapeint = get_shape(game);
  the_game(game);
  return (0);
}
