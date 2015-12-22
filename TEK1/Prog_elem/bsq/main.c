/*
** main.c for main in /home/uberti_l/rendu/CPE_2015_bsq
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Dec 15 21:45:18 2015 louis-emile uberti-ares
** Last update Mon Dec 21 20:32:48 2015 louis-emile uberti-ares
*/

#include "include/bsq.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void		get_map(char *file, int size)
{
  unsigned int	i;
  t_bsq		*bsq;

  if ((bsq = malloc(sizeof(t_bsq))) == NULL)
    exit(84);
  i = 0;
  init_my_bsq(bsq, file);
  while (file[i] != '\n')
    i += 1;
  i += 1;
  while (file[i] != '\0')
    {
      if (file[i] == 'o')
	bsq->M[bsq->lines][bsq->idx] = 1;
      else if (file[i] == '\n')
	{
	  bsq->lines += 1;
	  bsq->idx = -1;
	}
      i += 1;
      bsq->idx += 1;
    }
  bsq->size = size;
  my_core(bsq, file);
}

int		get_file(int size, int fd)
{
  char		*file;

  if ((file = malloc(size + 1)) == NULL)
    exit(84);
  read(fd, file, size);
  close(fd);
  file[size] = '\0';
  get_map(file, size);
  return (0);
}

int		main(int ac, char **av)
{
  struct stat	sb;
  int		fd;

  if (ac != 2)
    {
      my_putstr_err("Usage : ./bsq [map]\n");
      return (1);
    }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr_err("Error : Cannot open the file ");
      my_putstr_err(av[1]);
      my_putstr_err("\n");
      return (3);
    }
  if (stat(av[1], &sb) < 0)
    {
      my_putstr_err("Error while trying to use stat struct\n");
      return (2);
    }
  get_file(sb.st_size, fd);
  return (0);
}
