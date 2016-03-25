/*
** get_tetrimino.c for get_tetrimino in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Mar  1 13:03:45 2016 louis-emile uberti-ares
** Last update Sun Mar 20 22:59:27 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/tetris.h"

int		line_extract(t_tetris *game, int fd, int idx)
{
  int		i;
  int		y;
  char		*line;

  y = 0;
  i = 0;
  if ((game->pieces[idx].form = malloc(8 * (game->pieces->height + 1))) == NULL)
    return (1);
  while (y != game->pieces[idx].height)
    {
      if (((line = get_next_line(fd)) == NULL) ||
	   (my_strlen(line) > game->pieces[idx].width))
	return (1);
      if (y > game->pieces[idx].height)
	return (1);
      game->pieces[idx].form[i++] = my_strdup(line);
      y += 1;
      free(line);
    }
  game->pieces[idx].form[i] = NULL;
  if (check_shape(game, idx) == 1)
      return (1);
  return (0);
}

int		extract_number(t_tetris *game, char *line, int idx)
{
  int		i;
  int		return_value;
  char		**argv;

  i = 0;
  return_value = 0;
  argv = my_str_to_wordtab(line);
  if (((argv[0][0] < '0') || (argv[0][0] > '9'))
      || ((argv[1][0] < '0') || (argv[1][0] > '9'))
      || ((argv[2][0] < '0') || (argv[2][0] > '9')))
    return_value = 1;
  if (return_value == 0)
    {
      game->pieces[idx].width = my_getnbr(argv[0]);
      game->pieces[idx].height = my_getnbr(argv[1]);
      ((game->pieces[idx].color = my_getnbr(argv[2])) > 7)
	? (return_value = 1) : (0);
    }
  if (argv[3] != NULL)
    return_value = 1;
  while (argv[i] != NULL)
    free(argv[i++]);
  return (return_value);
}

int		open_tetrimino(t_tetris *game, char *file, int idx)
{
  int		fd;
  char		*line;

  chdir("tetriminos");
  fd = open(file, O_RDONLY);
  if ((line = get_next_line(fd)) == NULL)
    return (1);
  if (extract_number(game, line, idx) == 1)
    {
      close(fd);
      free(line);
      return (1);
    }
  free(line);
  if (line_extract(game, fd, idx) == 1)
    {
      game->pieces[idx].form[0] = NULL;
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

void		get_tetrimino(t_tetris *game, char **argv)
{
  int		i;

  i = 0;
  while (argv[i] != NULL)
    {
      (game->verbose == 1) ? (my_putstr("Tetriminos : Name ")) : (0);
      (game->verbose == 1) ? (print_name_before_tetrimino(argv[i])) : (0);
      if (open_tetrimino(game, argv[i], i) == 1)
	(game->verbose == 1) ? (my_putstr(" : Error\n"),
				game->pieces[i].width = 0,
				game->pieces[i].height = 0) : (0);
      else if (game->verbose == 1)
	{
	  my_putstr(" : Size ");
	  my_put_nbr(game->pieces[i].width);
	  my_putchar('*');
	  my_put_nbr(game->pieces[i].height);
	  my_putstr(" : Color ");
	  my_put_nbr(game->pieces[i].color);
	  my_putstr(" :\n");
	  draw_shape(game, i);
	}
      i += 1;
    }
}
