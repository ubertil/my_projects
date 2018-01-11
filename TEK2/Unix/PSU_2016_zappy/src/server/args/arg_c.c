/*
** arg_c.c for arg_c.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/args
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:23:20 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:23:21 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include <stdlib.h>
#include "server/server.h"

char	arg_c(t_server *server, char *arg)
{
  int	tmp;

  tmp = atoi(arg);
  if (tmp < 1)
    {
      printf("\n-c option only accepts integer ");
      printf("values greater or equal to 1\n");
      return (1);
    }
  server->client_nb = atoi(arg);
  return (0);
}
