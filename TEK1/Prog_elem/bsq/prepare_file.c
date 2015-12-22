/*
** prepare_file.c for prepare_file.c in /home/uberti_l/rendu/CPE_2015_BSQ
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Dec 21 20:27:19 2015 louis-emile uberti-ares
** Last update Mon Dec 21 20:34:57 2015 louis-emile uberti-ares
*/

#include "include/bsq.h"
#include <stdlib.h>
#include <unistd.h>

void		get_info_about_file(char *file, t_bsq *bsq)
{
  unsigned int	i;
  int		break_value;

  i = 0;
  bsq->nb_lines = 0;
  bsq->lenght = 0;
  while (file[i] != '\0')
    {
      if (file[i] != '\n' && file[i] != 'o' && file[i] != '.'
	  && bsq->nb_lines > 1)
	break_value = 1;
      if (file[i] == '\n')
	bsq->nb_lines += 1;
      if (bsq->nb_lines == 1)
	bsq->lenght += 1;
      i += 1;
    }
  if (break_value == 1)
    {
      write(2, "Error : File is not a proper map\n", 34);
      free(file);
      exit(84);
    }
  bsq->nb_lines = bsq->nb_lines - 1;
  bsq->lenght = bsq->lenght - 1;
}


void		prepare_my_file(t_bsq *bsq)
{
  unsigned int	tmp;
  unsigned int	i;

  i = 0;
  tmp = bsq->nb_lines;
  if ((bsq->M = malloc(sizeof(int *) * bsq->nb_lines)) == NULL)
    exit(84);
  if ((bsq->S = malloc(sizeof(int *) * bsq->nb_lines)) == NULL)
    exit(84);
  while (tmp != 0)
    {
      if ((bsq->M[i] = malloc(sizeof(int) * bsq->lenght)) == NULL)
	exit(84);
      if ((bsq->S[i] = malloc(sizeof(int) * bsq->lenght)) == NULL)
	exit(84);
      tmp -= 1;
      i += 1;
    }
}

void	init_my_bsq(t_bsq *bsq, char *file)
{
  bsq->idx = 0;
  bsq->lines = 0;
  get_info_about_file(file, bsq);
  prepare_my_file(bsq);
}
