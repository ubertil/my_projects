/*
** check_tetriminos.c for check_tetriminos in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Feb 24 10:28:03 2016 louis-emile uberti-ares
** Last update Sun Mar 20 22:16:52 2016 louis-emile uberti-ares
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "../include/tetris.h"

int		check_good(char **argv)
{
  int		i;
  int		compare;

  i = 0;
  while (argv[i + 1] != NULL)
    {
      compare = my_strcmp(argv[i], argv[i + 1]);
      if (compare == 1)
	return (0);
      i += 1;
    }
  return (1);
}

char		**order_them(char **argv)
{
  int		i;
  int		compare;
  char		*str;

  i = 0;
  while (argv[i + 1] != NULL)
    {
      compare = my_strcmp(argv[i], argv[i + 1]);
      if (compare == 1)
	{
	  str = my_strdup(argv[i]);
	  free(argv[i]);
	  argv[i] = my_strdup(argv[i + 1]);
	  free(argv[i + 1]);
	  argv[i + 1] = my_strdup(str);
	  free(str);
	}
      i += 1;
    }
  if (check_good(argv) == 0)
    order_them(argv);
  return (argv);
}

char		**ascii_order(DIR *dir, t_tetris *game)
{
  char		**argv;
  char		**to_return;
  int		i;
  struct dirent	*dent;

  i = 0;
  while ((dent = readdir(dir)) != NULL)
    (quick_match(dent->d_name, ".tetrimino") == 1) ? (i += 1) : (0);
  dir = opendir("tetriminos");
  if ((argv = malloc(sizeof(char *) * (i + 2))) == NULL)
    exit(84);
  argv[i] = NULL;
  i = 0;
  while ((dent = readdir(dir)) != NULL)
    if (quick_match(dent->d_name, ".tetrimino") == 1)
      argv[i++] = my_strdup(dent->d_name);
  (game->verbose == 1) ? (my_put_nbr(i)) : (0);
  game->nb_pieces = i;
  (game->verbose == 1) ? (my_putchar('\n')) : (0);
  (game->nb_pieces > 0) ? (to_return = order_them(argv)) : (0);
  closedir(dir);
  free(dent);
  return (to_return);
}

int		check_tetriminos(t_tetris *game)
{
  DIR		*dir;
  int		i;
  char		**argv;

  if ((dir = opendir("tetriminos")) == NULL)
    {
      my_putstr_err("Error : Can't open the directory 'tetriminos'\n");
      return (1);
    }
  if ((argv = ascii_order(dir, game)) == NULL)
    return (1);
  if ((game->pieces = malloc(sizeof(t_pieces) * game->nb_pieces)) == NULL)
    return (1);
  (game->nb_pieces > 0) ? (get_tetrimino(game, argv)) : (0);
  chdir("..");
  i = 0;
  if (game->nb_pieces > 0)
    while (argv[i] != NULL)
      free(argv[i++]);
  (game->nb_pieces > 0) ? (free(argv)) : (0);
  closedir(dir);
  return (0);
}
