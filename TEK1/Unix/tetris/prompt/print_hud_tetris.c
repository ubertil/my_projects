/*
** print_hud_tetris.c for print_hud_tetris in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Mar 15 20:28:24 2016 Louis-Emile Uberti
** Last update Sun Mar 20 18:30:12 2016 louis-emile uberti-ares
*/

#include <ncurses.h>
#include "../include/tetris.h"

void	set_colors(void)
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void	prompt_tetris_next_next(void)
{
  attron(COLOR_PAIR(5));
  mvprintw(0, 19, "***");
  mvprintw(1, 19, "*  ");
  mvprintw(2, 19, "***");
  mvprintw(3, 19, "  *");
  mvprintw(4, 19, "***");
  attroff(COLOR_PAIR(5));
}

void	prompt_tetris_next(void)
{
  attron(COLOR_PAIR(3));
  mvprintw(0, 9, "***");
  mvprintw(1, 10, "*");
  mvprintw(2, 10, "*");
  mvprintw(3, 10, "*");
  mvprintw(4, 10, "*");
  attron(COLOR_PAIR(2));
  mvprintw(0, 13, "***");
  mvprintw(1, 13, "* *");
  mvprintw(2, 13, " **");
  mvprintw(3, 13, "* *");
  mvprintw(4, 13, "* *");
  attron(COLOR_PAIR(4));
  mvprintw(0, 17, "*");
  mvprintw(1, 17, " ");
  mvprintw(2, 17, "*");
  mvprintw(3, 17, "*");
  mvprintw(4, 17, "*");
  prompt_tetris_next_next();
}

void	prompt_tetris(void)
{
  attron(COLOR_PAIR(1));
  mvprintw(0, 0, "***");
  mvprintw(1, 1, "*");
  mvprintw(2, 1, "*");
  mvprintw(3, 1, "*");
  mvprintw(4, 1, "*");
  attron(COLOR_PAIR(4));
  mvprintw(0, 5, "***");
  mvprintw(1, 5, "*");
  mvprintw(2, 5, "***");
  mvprintw(3, 5, "*");
  mvprintw(4, 5, "***");
  prompt_tetris_next();
}

void	prompt_credits(t_tetris *game)
{
  wborder(game->credits, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(game->credits);
  attron(COLOR_PAIR(7));
  if (game->score > game->highscore)
    game->highscore = game->score;
  mvprintw(9, 2, "High Score\t%d", game->highscore);
  mvprintw(10, 2, "Score\t        %d", game->score);
  mvprintw(12, 2, "Lines\t        %d", game->score_lines);
  mvprintw(13, 2, "Level\t        %d", game->level);
  mvprintw(15, 2, "Timer:   %d%d:%d%d", game->timer[0], game->timer[1],
	   game->timer[2], game->timer[3]);
  mvprintw(2 + game->board_lines, 0, "Uberti_l & Wadel_n ©Tetris 2016");
  attroff(COLOR_PAIR(7));
}
