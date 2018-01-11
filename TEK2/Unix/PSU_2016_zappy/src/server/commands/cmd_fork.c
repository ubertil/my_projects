/*
** cmd_fork.c for cmd_fork.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:25:59 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:26:06 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"

void		cmd_fork(t_server *server, char *arg, const int fd)
{
  (void)server;
  (void)arg;
  (void)fd;
  printf("Cmd Fork\n");
}
