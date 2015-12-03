/*
** fs_cat_500_bytes.c for fs_cat_500_bytes in /home/uberti_l/rendu/CPE_2015_bsq/bootstrap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 24 14:46:31 2015 louis-emile uberti-ares
** Last update Tue Nov 24 15:25:29 2015 louis-emile uberti-ares
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	my_putstr(char *str)
{
  if (*str)
    {
      write (1, str, 1);
      my_putstr(str + 1);
    }
}

void	fs_print_first_line(char *filepath)
{
  int	fd;
  char	buffer[1];

  fd = fs_open_file(filepath);
  while (buffer[0] != '\n')
    {
      read(fd, buffer, 1);
      write(1, buffer, 1);
    }
  close(fd);
}

void	fs_cat_500_bytes(char *filepath)
{
  int	fd;
  char	buffer[500];

  fd = fs_open_file(filepath);
  read(fd, buffer, 500);
  my_putstr(buffer);
  close(fd);
}

void	fs_cat_x_bytes(char *filepath, int x)
{
  int	fd;
  char	*buffer;

  buffer = malloc(x * sizeof(char));
  fd = fs_open_file(filepath);
  read(fd, buffer, x);
  my_putstr(buffer);
  close(fd);
}

int	main(int ac, char **av)
{
  fs_print_first_line(av[1]);
}
