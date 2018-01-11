/*
** graph.c for graph in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Apr 23 23:00:54 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 17:24:16 2017 Lous-Emile Uberti-Ares
*/

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

void		close_graph(const int fd)
{
  if (fd != -1)
    {
      write(fd, GRAPH_END, 2);
      close(fd);
    }
}

_Bool		open_graph(int *fd)
{
  if ((*fd = open(GRAPH_FILE, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
    return (false && dprintf(2, GRAPH_ERR));
  write(*fd, GRAPH_START, 33);
  return (true);
}

_Bool		add_to_graph(const int fd, const char *start, const char *end,
			     const e_type type)
{
  char		*line;

  if (start == NULL)
    asprintf(&line, GRAPH_LINK, "_start", end);
  else
    asprintf(&line, GRAPH_LINK, start, end);
  write(fd, line, strlen(line));
  if (type == F_LINKED)
    asprintf(&line, STYLE_FUNC, end);
  else if (type == F_NOT_LINKED)
    asprintf(&line, STYLE_END_NODE, end);
  else if (type == SYS)
    asprintf(&line, STYLE_SYSCALL, end);
  write(fd, line, strlen(line));
  return (true);
}
