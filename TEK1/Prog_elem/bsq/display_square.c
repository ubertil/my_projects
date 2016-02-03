/*
** display_square.c for display_square in /home/uberti_l/rendu/CPE_2015_bsq
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Dec 17 14:42:27 2015 louis-emile uberti-ares
** Last update Sun Dec 20 17:19:48 2015 louis-emile uberti-ares
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/bsq.h"

int	display_it(t_bsq *bsq, char *file)
{
  int	i;

  i = 0;
  if ((bsq->final = malloc(bsq->size)) == NULL)
    exit(84);
  while (file[i] != '\n')
    i += 1;
  i += 1;
  while (file[i] != '\0')
    {
      bsq->final[i] = file[i];
      i += 1;
    }
  write(1, bsq->final, bsq->size);
  free(bsq->final);
  return (0);
}

void	get_final_map(t_bsq *bsq, char *file)
{
  int	i;

  i = 0;
  while (file[i] != '\n')
    i += 1;
  i += 1;
  while (file[i] != '\0')
    {
      if ((bsq->lines >= bsq->row - bsq->max && bsq->lines <= bsq->row) &&
	  (bsq->idx > bsq->columns - bsq->max && bsq->idx <= bsq->columns + 1))
	file[i] = 'x';
      else if (file[i] == '\n')
	{
	  bsq->lines += 1;
	  bsq->idx = -1;
	}
      bsq->idx += 1;
      i += 1;
    }
  display_it(bsq, file);
}


void	display_square(t_bsq *bsq, char *file)
{
  get_final_map(bsq, file);
  free_all(bsq, file);
  exit(0);
}
