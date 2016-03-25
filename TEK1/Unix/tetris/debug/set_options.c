/*
** set_options.c for set_options in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 16:30:10 2016 louis-emile uberti-ares
** Last update Sat Mar 19 22:15:17 2016 Louis-Emile Uberti
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/tetris.h"

void		select_level(t_tetris *game, char *str)
{
  int		i;

  i = 0;
  while (str[i] != '=')
    i += 1;
  if ((str[i + 1] != '\0') && (isnbr_from(str, i + 1) == 0))
    game->level = getnbr_from(str, i + 1);
  (game->level > 40) ? (game->level = 40) : (0);
  if (game->level == 0)
    game->level = 1;
  game->option_done = 1;
}

void		set_map_size(t_tetris *game, char *str)
{
  int		i;

  i = 0;
  game->option_done = 1;
  while (str[i] != '=')
    i += 1;
  if ((str[i + 1] != '\0') && (isnbr_from(str, i + 1) == 0))
    game->board_lines = getnbr_from(str, i + 1);
  else
    return;
  while (str[i] != ',')
    i += 1;
  if ((str[i + 1] != '\0') && (isnbr_from(str, i + 1) == 0))
    game->board_rows = getnbr_from(str, i + 1);
  else
    game->board_lines = 20;
}

void		hide_next(t_tetris *game, char *str)
{
  game->hide_next = 1;
  if ((my_strcmp(str, "-w") != 0) && ((my_strcmp(str, "--without-next")) != 0))
    game->option_done = 0;
  else
    game->option_done = 1;
  (void)str;
}

void		bind_turn(t_tetris *game, char *key)
{
  if (my_strncmp(key, "--k", 2) == 0)
    {
      free(game->turn_key);
      game->turn_key = dupkey(key);
    }
  else if (key != NULL)
    {
      free(game->turn_key);
      game->turn_key = my_strdup(key);
      game->idx += 1;
    }
  game->option_done = 1;
}
