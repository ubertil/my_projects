/*
** get_matrix.c for get_matrix.c in /home/uberti_l/rendu/CPE_2015_bsq
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Dec 17 11:20:52 2015 louis-emile uberti-ares
** Last update Thu Dec 17 16:04:34 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/bsq.h"

int		get_minimum(int first, int second, int third)
{
  int		minimum;

  minimum = first;
  if (minimum > second)
    minimum = second;
  if (minimum > third)
    minimum = third;
  return (minimum + 1);
}

void		set_sub_matrix(t_bsq *bsq)
{
  unsigned int	row;
  unsigned int	columns;

  row = 0;
  columns = 0;
  while (row < bsq->nb_lines)
    {
      bsq->S[row][0] = bsq->M[row][0];
      row += 1;
    }
  while (columns < bsq->lenght)
    {
      bsq->S[0][columns] = bsq->M[0][columns];
      columns += 1;
    }
}

void		find_coordinates(t_bsq *bsq)
{
  bsq->max = bsq->S[0][0];
  while (bsq->lines < bsq->nb_lines)
    {
      bsq->idx = 0;
      while (bsq->idx <bsq->lenght)
	{
	  if (bsq->max < bsq->S[bsq->lines][bsq->idx])
	    {
	      bsq->max = bsq->S[bsq->lines][bsq->idx];
	      bsq->row = bsq->lines;
	      bsq->columns = bsq->idx;
	    }
	  bsq->idx += 1;
	}
      bsq->lines += 1;
    }
}

void	find_square(t_bsq *bsq)
{
  set_sub_matrix(bsq);
  bsq->lines = 1;
  while (bsq->lines < bsq->nb_lines)
    {
      bsq->idx = 1;
      while (bsq->idx < bsq->lenght)
	{
	  if (bsq->M[bsq->lines][bsq->idx] == 0)
	    bsq->S[bsq->lines][bsq->idx] =
	      get_minimum(bsq->S[bsq->lines][bsq->idx - 1],
			  bsq->S[bsq->lines - 1][bsq->idx],
			  bsq->S[bsq->lines - 1][bsq->idx - 1]);
	  bsq->idx += 1;
	}
      bsq->lines += 1;
    }
  bsq->lines = 0;
  bsq->idx = 0;
  bsq->columns = 0;
  bsq->row = 0;
}
