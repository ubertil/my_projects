/*
** struct_handler.c for struct_handler.c in /home/trognot/rendu/IA/dante/profondeur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 19 02:51:05 2016 nicolas trognot
** Last update Fri May 27 17:09:31 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "profondeur.h"
#include "tools.h"

int		transfer_wt_to_cells(t_maze *maze,
				     char **wt)
{
  int		i;
  int		j;

  i = 0;
  while (wt[i])
    i++;
  maze->h = i;
  if ((maze->cells = malloc(sizeof(char *) * i)) == NULL)
    return (1);
  i = -1;
  while (++i < maze->h)
    if ((maze->cells[i] = strdup(wt[i])) == NULL)
      return (1);
  i = -1;
  while (++i < maze->h)
    {
      j = -1;
      while (++j < maze->w)
	maze->cells[i][j] = (maze->cells[i][j] == '*') ? (0) : (1);
    }
  free_tab(wt, maze->h);
  if (maze->w > 1000 || maze->h > 1000)
    return (my_putstr_err(TOO_MUCH));
  return (0);
}

int		open_file(t_maze *maze, char *filepath)
{
  char		**wt;
  struct stat	my_stat;
  int		ret;

  if ((maze->file_fd = open(filepath, O_RDONLY)) == -1 ||
      (fstat(maze->file_fd, &my_stat)) == -1 ||
      (maze->file = malloc(sizeof(char) * (my_stat.st_size + 1))) == NULL ||
      (ret = read(maze->file_fd, maze->file, my_stat.st_size)) <= 0 ||
      (maze_checker(maze->file, ret) == -1))
    return (0);
  wt = my_str_to_wordtab(maze->file);
  ret = 0;
  while (wt[ret])
    {
      maze->w = strlen(wt[ret]);
      if (ret > 0)
	if (strlen(wt[ret - 1]) != strlen(wt[ret]))
	  return (0);
      ret++;
    }
  if (transfer_wt_to_cells(maze, wt))
    return (0);
  return (1);
}

t_maze		*init_maze()
{
  t_maze	*maze;

  if ((maze = malloc(sizeof(t_maze))) == NULL)
    return (NULL);
  return (maze);
}
