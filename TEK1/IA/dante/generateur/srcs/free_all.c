/*
** free_all.c for free_all in /home/uberti_l/rendu/Init_ia/dante
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 27 13:42:44 2016 louis-emile uberti-ares
** Last update Fri May 27 13:44:06 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "generateur.h"

void	free_all(t_maze *maze)
{
  int	y;

  y = -1;
  while (++y < maze->h)
    free(maze->cells[y]);
  free(maze->cells);
  free(maze);
}
