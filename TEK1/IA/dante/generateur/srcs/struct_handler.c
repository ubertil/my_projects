/*
** struct_handler.c for struct_handler.c in /home/trognot/rendu/IA/dante/generator/perfect
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 02:14:02 2016 nicolas trognot
** Last update Thu May 12 02:14:02 2016 nicolas trognot
*/

#include <stdlib.h>
#include "generateur.h"

t_maze		*init_maze(int w, int h)
{
  t_maze	*maze;
  int		j;
  int		i;

  if ((maze = malloc(sizeof(t_maze))) == NULL)
    return (NULL);
  maze->w = w;
  maze->h = h;
  if ((maze->cells = malloc(sizeof(char *) * maze->h)) == NULL)
    return (NULL);
  j = -1;
  while (++j < maze->h)
    {
      if ((maze->cells[j] = malloc(sizeof(char) * maze->w)) == NULL)
	return (NULL);
      i = -1;
      while (++i < maze->w)
	maze->cells[j][i] = (j % 2 == 1 || i % 2 == 1) ? (1) : (0);
    }
  return (maze);
}
