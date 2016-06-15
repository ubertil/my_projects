/*
** maze_checker.c for maze_checker in /home/uberti_l/rendu/Init_ia/dante
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 27 14:46:13 2016 louis-emile uberti-ares
** Last update Fri May 27 15:03:54 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "astar.h"

int	maze_checker(char *maze, const int ret)
{
  int	i;

  i = -1;
  maze[ret] = '\0';
  while (maze[++i] != '\0')
    if (maze[i] != 'X' && maze[i] != '*' && maze[i] != '\n')
      {
	free(maze);
	return (my_putstr_err(WRONG_FORMAT));
      }
  return (0);
}
