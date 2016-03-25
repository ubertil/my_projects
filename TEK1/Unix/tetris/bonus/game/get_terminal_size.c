/*
** get_terminal_size.c for get_terminal_size in /home/uberti_l/rendu/PSU_2015_my_select
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Dec  8 11:34:28 2015 louis-emile uberti-ares
** Last update Fri Mar 25 16:52:15 2016 louis-emile uberti-ares
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../include/tetris.h"

int		get_terminal_size(t_tetris *game)
{
  if (37 + game->biggest[0] + game->board_rows > COLS
      || game->board_lines + 4 > LINES)
    {
      endwin();
      (game->music_play == 1) ? (force_quit_music()) : (0);
      my_putstr_err("Error : Window is too small for the game.\nExiting.\n");
      my_putstr_err("Please consider setting a bigger terminal\n");
      exit(0);
    }
  return (0);
}
