/*
** fs_understand_return_of_read.c for fs_understand_return_of_read in /home/uberti_l/rendu/CPE_2015_bsq/bootstrap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 24 14:30:17 2015 louis-emile uberti-ares
** Last update Tue Nov 24 14:43:04 2015 louis-emile uberti-ares
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

void	fs_understand_return_of_read(int fd, char *buffer, int size)
{
  int	ret;

  ret = read(fd, buffer, 1);
  if (ret == 0)
    my_putstr("read n'a plus rien à lire");
  else if (ret == - 1)
    my_putstr("read a fail\n");
  else if (ret < size)
    my_putstr("read n'a pas remplis tout le buffer\n");
  else
    my_putstr("read a remplit tout le buffer\n");
  close(fd);
}
