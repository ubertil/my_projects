/*
** main.c for main in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 13:56:22 2016 louis-emile uberti-ares
** Last update Mon Mar 21 18:24:28 2016 nicolas wadel
*/

#include <stdlib.h>
#include "include/tetris.h"

void		no_tetriminos(t_tetris *game)
{
  my_putstr_err("Error: No tetriminos !\nExiting\n");
  free_all(game);
  exit(84);
}

void		init_default_values(t_tetris *game)
{
  game->pause = 0;
  game->timer[0] = 0;
  game->timer[1] = 0;
  game->timer[2] = 0;
  game->timer[3] = 0;
  game->timer[4] = 1;
  game->hide_next = 0;
  game->starty = 0;
  game->board_rows = 10;
  game->board_lines = 20;
  game->level = 1;
  game->verbose = 0;
  game->score = 0;
  load_highscore(game);
  game->nb_pieces = 0;
  game->quit_key = my_strdup("q");
  game->pause_key = my_strdup(" ");
}

int		init_game(int ac, char **av, t_tetris *game, char **env)
{
  int		i;

  i = 1;
  game->nb_args = ac;
  init_default_values(game);
  if (setup_term(game, env) == 1)
    return (1);
  if (ac > 1)
    if (get_options(ac, av, game) == 1)
      return (0);
  while (i != ac)
    {
      if ((my_strcmp(av[i], "-d") == 0)
	  ^ (my_strcmp(av[i], "--debug") == 0))
	{
	  debug_mode(game);
	  return (0);
	}
      i += 1;
    }
  if (check_tetriminos(game) == 1)
    return (1);
  (game->nb_pieces > 0) ? (normal_game(game)) : (no_tetriminos(game));
  return (0);
}

int		main(int ac, char **av, char **env)
{
  int		i;
  t_tetris	*game;

  i = 1;
  if (env[0] == NULL)
    return (0);
  if (ac > 1)
    while (i != ac)
      {
	if (my_strcmp(av[1], "--help") == 0)
	  {
	    print_help(av);
	    return (0);
	  }
	i += 1;
      }
  if ((game = malloc(sizeof(t_tetris))) == NULL)
    return (1);
  init_game(ac, av, game, env);
  return (0);
}
