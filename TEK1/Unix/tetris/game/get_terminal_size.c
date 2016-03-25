/*
** get_terminal_size.c for get_terminal_size in /home/uberti_l/rendu/PSU_2015_my_select
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Dec  8 11:34:28 2015 louis-emile uberti-ares
** Last update Mon Mar 21 17:12:01 2016 nicolas wadel
*/

#include "../include/tetris.h"
#include <ncurses.h>

int		get_terminal_size(t_tetris *game)
{
  if (37 + game->biggest[0] + game->board_rows > COLS
      || game->board_lines + 4 > LINES)
    {
      endwin();
      my_putstr_err("Error : Window is too small for the game.\nExiting.\n");
      my_putstr_err("Please consider setting a bigger terminal\n");
      return (1);
    }
  return (0);
}
