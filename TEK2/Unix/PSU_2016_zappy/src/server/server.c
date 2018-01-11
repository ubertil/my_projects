/*
** server.c for server.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:09:54 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:10:06 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "server/server.h"

void		load_default_values(t_server *server)
{
  server->conn.port = 4242;
  server->freq = 100;
  server->width = 15;
  server->height = 15;
  server->names = NULL;
  server->players = NULL;
  server->map.cases = NULL;
  server->client_nb = 1;
}

int		init_server(t_server *server)
{
  if (build_map(server) != 0)
    return (1);
  return (0);
}

void		free_server(t_server *server)
{
  int		i;
  t_name	*n;
  t_player	*p;

  i = -1;
  while (++i < server->height)
    free(server->map.cases[i]);
  free(server->map.cases);
  while ((n = server->names) != NULL)
    {
      server->names = server->names->next;
      free(n->name);
      free(n);
    }
  while ((p = server->players) != NULL)
    {
      server->players = server->players->next;
      free(p->team_name);
      free(p);
    }
}
