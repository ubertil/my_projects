/*
** arg_p.c for arg_p.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/args
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:22:06 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:22:07 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "server/server.h"

char	arg_p(t_server *server, char *arg)
{
  server->conn.port = atoi(arg);
  return (0);
}
