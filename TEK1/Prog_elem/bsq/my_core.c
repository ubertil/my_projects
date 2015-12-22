/*
** my_core.c for my_core in /home/uberti_l/rendu/CPE_2015_bsq
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Dec 17 12:18:44 2015 louis-emile uberti-ares
** Last update Sun Dec 20 17:13:04 2015 louis-emile uberti-ares
*/

#include "include/bsq.h"

void	my_core(t_bsq *bsq, char *file)
{
  bsq->lines = 0;
  bsq->idx = 0;
  find_square(bsq);
  find_coordinates(bsq);
  bsq->lines = 0;
  bsq->idx = 0;
  display_square(bsq, file);
}
