/*
** main.c for main in /home/uberti_l/rendu/CPE_2015_bsq
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 24 15:55:53 2015 louis-emile uberti-ares
** Last update Tue Dec  1 11:23:50 2015 louis-emile uberti-ares
*/

#include <unistd.h>
#include "include/bsq.h"
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int		init_my_map(t_stock *a)
{
  int		tmp;
  int		i;

  tmp = a->nb_lines;
  i = 0;
  if ((a->map = malloc(sizeof(char **) * a->nb_lines)) == NULL)
    return (1);
  while (tmp != 0)
    {
      if ((a->map[i] = malloc((sizeof(char *)) * a->lenght)) == NULL)
	exit (84);
      tmp = tmp - 1;
      i = i + 1;
    }
  fill_my_map(a);
  return (0);
}

unsigned int		get_lenght(int fd)
{
  unsigned int		i;
  char			buffer[1];

  i = 0;
  buffer[0] = 0;
  while (buffer[0] != '\n')
    read(fd, buffer, 1);
  read(fd, buffer, 1);
  while (buffer[0] != '\n')
    {
      read(fd, buffer, 1);
      i = i + 1;
    }
  return (i);
}

int		get_lines(int fd)
{
  int		i;
  int		ret;
  char		buffer[1];

  i = -1;
  ret = 1;
  buffer[0] = 0;
  while ((ret = read(fd, buffer, 1)) == 1)
    (buffer[0] == '\n') ? (i = i + 1) : (0);
  return (i);
}

int		init_my_struct(char **av)
{
  t_stock	*a;

  if ((a = malloc(sizeof(*a))) == NULL)
    return (1);
  a->fd = open(av[1], O_RDONLY);
  if (a->fd == -1)
    {
      my_putstr("./bsq : cannot access ");
      my_putstr(av[1]);
      my_putstr(" : No such file\n");
      return (1);
    }
  a->lenght = get_lenght(a->fd);
  close(a->fd);
  a->fd = open(av[1], O_RDONLY);
  a->nb_lines = get_lines(a->fd);
  close(a->fd);
  a->fd = open(av[1], O_RDONLY);
  init_my_map(a);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      my_putstr("Error : Please enter a file\n");
      return (1);
    }
  init_my_struct(av);
  return (0);
}
