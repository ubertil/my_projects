/*
** highscore.c for highscore in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar 17 13:54:27 2016 Louis-Emile Uberti
** Last update Thu Mar 17 18:59:07 2016 Louis-Emile Uberti
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/tetris.h"

void		save_highscore(t_tetris *game)
{
  int		fd;

  fd = open(".savedata", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR |
	    S_IRGRP | S_IROTH);
  if (fd == -1)
    return;
  else
    {
      write(fd, "Highscore=\n", 11);
      write(fd, &game->highscore, 4);
      close(fd);
    }
}

void		load_highscore(t_tetris *game)
{
  int		fd;
  char		*line;

  if ((fd = open(".savedata", O_RDONLY)) == -1)
    game->highscore = 0;
  else
    {
      line = get_next_line(fd);
      free(line);
      read(fd, &game->highscore, 4);
      close(fd);
    }
}
