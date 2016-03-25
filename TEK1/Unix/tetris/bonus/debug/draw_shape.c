/*
** draw_shape.c for draw_shape in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar  3 15:36:42 2016 louis-emile uberti-ares
** Last update Sun Mar 20 21:33:35 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "../include/tetris.h"

int	find_dot(char *str, int i)
{
  int	max;

  while (str[i] != '\0')
    {
      if (str[i] == '.')
	max = i;
      i += 1;
    }
  return (max);
}

void	print_name_before_tetrimino(char *str)
{
  int	i;
  int	max;

  i = 0;
  max = find_dot(str, i);
  while (i != max)
    my_putchar(str[i++]);
}

int	check_shape(t_tetris *game, int tab)
{
  int	i;
  int	idx;

  i = 0;
  idx = 0;
  while (game->pieces[tab].form[i] != NULL)
    {
      while (game->pieces[tab].form[i][idx] != '\0')
	{
	  if (game->pieces[tab].form[i][idx] != ' '
	      && game->pieces[tab].form[i][idx] != '*')
	    {
	      game->pieces[tab].form[0] = NULL;
	      free_wrong_shape(game, tab);
	      return (1);
	    }
	  idx += 1;
	}
      idx = 0;
      i += 1;
    }
  return (0);
}

void	draw_shape(t_tetris *game, int idx)
{
  int	i;

  i = 0;
  if (game->pieces[idx].form[0] == NULL)
    return;
  while (game->pieces[idx].form[i] != NULL)
    {
      my_putstr(game->pieces[idx].form[i++]);
      my_putchar('\n');
    }
}
