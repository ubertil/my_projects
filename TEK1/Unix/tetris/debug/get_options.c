/*
** get_options.c for get_options in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 14:48:43 2016 louis-emile uberti-ares
** Last update Sun Mar 20 21:02:52 2016 louis-emile uberti-ares
*/

#include "../include/tetris.h"

static const	t_options options[] =
  {
    {"-kl", &bind_left},
    {"-kr", &bind_right},
    {"-kd", &bind_drop},
    {"-kt", &bind_turn},
    {"-kq", &bind_quit},
    {"-kp", &bind_pause},
    {"-w", &hide_next},
    {"--without-next", &hide_next},
    {"-l", &select_level},
    {"--key-left=", &bind_left},
    {"--key-right=", &bind_right},
    {"--key-drop=", &bind_drop},
    {"--key-turn=", &bind_turn},
    {"--key-quit=", &bind_quit},
    {"--key-pause=", &bind_pause},
    {"--level=", &select_level},
    {"--map-size=", &set_map_size},
  };

int		strict_parcer(t_tetris *game, char **av)
{
  int		idx;

  idx = 0;
  while ((idx <= 10) && (my_strcmp(av[game->idx], options[idx].str) != 0))
    idx += 1;
  if (idx <= 5)
    return (idx);
  else
    {
      idx = 6;
      while (idx < 17 && unstrict_cmp(av[game->idx], options[idx].str) != 0)
	idx += 1;
    }
  return (idx);
}

int		get_options(int ac, char **av, t_tetris *game)
{
  int		idx;

  game->idx = 1;
  while (game->idx < ac)
    {
      idx = 0;
      game->option_done = 0;
      idx = strict_parcer(game, av);
      (idx <= 5) ? (options[idx].f(game, av[game->idx + 1])) : (0);
      if (idx > 5 && idx < 17 && my_strcmp(av[game->idx], "--debug") != 0)
	options[idx].f(game, av[game->idx]);
      if ((game->option_done == 0) &&
	  ((my_strcmp(av[game->idx], "--debug") != 0)
	   && (my_strcmp(av[game->idx], "-d") != 0)))
	{
	  my_putstr_err("Error : Wrong option ");
	  my_putstr_err(av[game->idx]);
	  my_putstr_err("\nGoing to the help section...\n\n");
	  print_help(av);
	  return (1);
	}
     game->idx += 1;
    }
  return (0);
}
