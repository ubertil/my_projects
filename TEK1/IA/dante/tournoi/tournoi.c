/*
** main.c for astar in /home/uberti_l/rendu/Init_ia/dante
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Apr 16 11:50:47 2016 louis-emile uberti-ares
** Last update Fri May 27 17:12:57 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include "astar.h"

int		main(int ac, char **av)
{
  t_maze	*maze;

  if (ac != 2)
    return (my_putstr_err(USAGE));
  if ((maze = init_maze()) == NULL)
    return (my_putstr_err(ERR_MALLOC));
  if (open_file(maze, av[1]) == 0)
    return (my_putstr_err(WRONG_FORMAT));
  if (solve_maze(maze) == 1)
    display_maze(maze);
  else
    printf("%s\n", NOTHING);
  free_all(maze);
  return (0);
}
