/*
** file.c for file.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:19:30 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:19:30 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"

FILE		*get_file_from_fd(t_server *server, int fd)
{
  t_player	*tmp;

  tmp = server->players;
  while (tmp)
    {
      if (tmp->fd == fd)
	return (tmp->file);
      tmp = tmp->next;
    }
  return (NULL);
}
