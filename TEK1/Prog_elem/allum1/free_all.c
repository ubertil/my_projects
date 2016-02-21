/*
** free_all.c for free_all in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  8 15:35:50 2016 louis-emile uberti-ares
** Last update Mon Feb  8 15:50:10 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/allum.h"

void		free_all(t_allum *allum)
{
  int		i;

  i = 0;
  while (i != 6)
    {
      free(allum->board[i]);
      i += 1;
    }
  free(allum->board);
  free(allum->lines);
  free(allum);
}
