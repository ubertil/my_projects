/*
** debug_mode.c for debug_mode in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 16:38:49 2016 louis-emile uberti-ares
** Last update Sun Mar 20 01:33:03 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "../include/tetris.h"

void		keypad_print(char *key)
{
  int		i;

  i = 0;
  if (my_strcmp(key, " ") == 0)
    {
      my_putstr("(space)");
      return;
    }
  while (key[i] != '\0')
    {
      if (key[i] == '\e')
	my_putstr("^E");
      else
	my_putchar(key[i]);
      i++;
    }
}

void		print_values(t_tetris *game)
{
  my_putstr("\nNext : ");
  (game->hide_next == 1) ? (my_putstr("No\n")) : (my_putstr("Yes\n"));
  my_putstr("Level : ");
  my_put_nbr(game->level);
  my_putstr("\nSize : ");
  my_put_nbr(game->board_lines);
  my_putchar('*');
  my_put_nbr(game->board_rows);
  my_putstr("\nTetriminos : ");
}

void		print_bindings(t_tetris *game)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  keypad_print(game->left_key);
  my_putstr("\nKey Right : ");
  keypad_print(game->right_key);
  my_putstr("\nKey Turn : ");
  keypad_print(game->turn_key);
  my_putstr("\nKey Drop : ");
  keypad_print(game->drop_key);
  my_putstr("\nKey Quit : ");
  keypad_print(game->quit_key);
  my_putstr("\nKey Pause : ");
  keypad_print(game->pause_key);
}

void			terminal_mode(int mode)
{
  static struct termios	old;
  static struct termios	new;


  if (mode == 2)
    {
      new.c_cc[VMIN] = 0;
      ioctl(0, TCSETS, &new);
    }
  if (mode == 1)
    {
      ioctl(0, TCGETS, &old);
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VTIME] = 0;
      new.c_cc[VMIN] = 1;
      ioctl(0, TCSETS, &new);
    }
  if (mode == 0)
    ioctl(0, TCSETS, &old);
}

void			debug_mode(t_tetris *game)
{
  char			bin[1];

  print_bindings(game);
  print_values(game);
  game->verbose = 1;
  check_tetriminos(game);
  my_putstr("Press a key to start Tetris\n");
  terminal_mode(1);
  read(0, bin, 1);
  terminal_mode(0);
  if (game->nb_pieces > 0)
    normal_game(game);
  else
    {
      my_putstr_err("Error: No tetriminos !\nExiting\n");
      free_all(game);
      exit(84);
    }
}
