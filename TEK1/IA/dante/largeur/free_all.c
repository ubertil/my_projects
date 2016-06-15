/*
** free_all.c for free_all in /home/uberti_l/rendu/Init_ia/dante
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 27 14:28:19 2016 louis-emile uberti-ares
** Last update Fri May 27 14:34:08 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "largeur.h"

void		free_tab(char **tab, const int y)
{
  int		i;

  i = -1;
  while (++i < y)
    free(tab[i]);
  free(tab);
}

void		free_all(t_maze *maze)
{
  free_tab(maze->cells, maze->h);
  free(maze->file);
  free(maze);
}
