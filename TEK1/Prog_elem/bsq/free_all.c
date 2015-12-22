/*
** free_matrix.c for free_matrix in /home/uberti_l/rendu/CPE_2015_bsq
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Dec 16 13:30:25 2015 louis-emile uberti-ares
** Last update Thu Dec 17 15:54:37 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/bsq.h"

void		free_all(t_bsq *bsq, char *file)
{
  unsigned int	lines;

  lines = 0;
  while (lines < bsq->nb_lines)
    {
      free(bsq->M[lines]);
      free(bsq->S[lines]);
      lines += 1;
    }
  free(bsq->M);
  free(bsq->S);
  free(file);
  free(bsq);
}
