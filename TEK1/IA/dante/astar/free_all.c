/*
** free_all.c for free_all.c in /home/uberti_l/rendu/Init_ia/dante
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 27 14:12:12 2016 louis-emile uberti-ares
** Last update Fri May 27 14:19:51 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "astar.h"

void		free_all(t_maze *maze)
{
  t_list	*free_open;
  t_list	*free_close;

  free(maze->file);
  free_tab(maze->cells, maze->h);
  while ((free_open = maze->open) != NULL)
    {
      maze->open = maze->open->next;
      free(free_open->node);
      free(free_open);
    }
  while ((free_close = maze->close) != NULL)
    {
      maze->close = maze->close->next;
      free(free_close->node);
      free(free_close);
    }
  free(maze);
}
