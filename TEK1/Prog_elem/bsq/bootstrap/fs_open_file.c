/*
** fs_open_file.c for fs_open_file in /home/uberti_l/rendu/CPE_2015_bsq/bootstrap
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 24 14:19:49 2015 louis-emile uberti-ares
** Last update Mon Nov 30 10:30:04 2015 louis-emile uberti-ares
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	fs_open_file(char *filepath)
{
  int	fd;

  fd = open(filepath, O_RDONLY);
  if (fd == - 1)
    write(1, "FAILURE\n", 8);
  else
    write(1, "SUCCESS\n", 8);
  return (fd);
}
