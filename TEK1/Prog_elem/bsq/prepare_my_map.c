/*
** prepare_my_map.c for prepare_my_map in /home/uberti_l/rendu/CPE_2015_bsq
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 30 12:36:20 2015 louis-emile uberti-ares
** Last update Tue Dec  1 11:25:12 2015 louis-emile uberti-ares
*/

#include "include/bsq.h"
#include <stdlib.h>
#include <unistd.h>

void		free_all(t_stock *a)
{
  int		tmp;
  unsigned int	i;

  tmp = a->nb_lines;
  i = 0;
  while (tmp != 0)
    {
      free(a->map[i]);
      tmp = tmp - 1;
      i = i + 1;
    }
  free(a->map);
  free(a);
}

void		disp_map(t_stock *a)
{
  int		nb_lines;
  int		line;
  int		idx;

  nb_lines = a->nb_lines;
  line = 0;
  idx = 0;
  while (line != nb_lines)
    {
      my_putchar(a->map[line][idx]);
      if (a->map[line][idx] == '\n')
	{
	  line = line + 1;
	  idx = 0;
	}
      else if (a->map[line][idx] != '\n')
	idx = idx + 1;
    }
  free_all(a);
}

void		fill_my_map(t_stock *a)
{
  int		ret;
  char		buffer[1];
  int		line;
  int		lenght;

  line = 0;
  lenght = 0;
  ret = 1;
  buffer[0] = 0;
  while (buffer[0] != '\n')
    read(a->fd, buffer, 1);
  while ((ret = read(a->fd, buffer, 1)) == 1)
    {
      a->map[line][lenght] = buffer[0];
      if (buffer[0] == '\n')
	{
	  line = line + 1;
	  lenght = 0;
	}
      else if (buffer[0] != '\n')
	lenght = lenght + 1;
    }
  close(a->fd);
  disp_map(a);
}
