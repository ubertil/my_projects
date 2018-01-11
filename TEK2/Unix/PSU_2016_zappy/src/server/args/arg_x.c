/*
** arg_x.c for arg_x.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/args
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:22:13 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:22:14 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include <stdlib.h>
#include "server/server.h"

char	arg_x(t_server *server, char *arg)
{
  int	tmp;

  tmp = atoi(arg);
  if (tmp < 10 || tmp > 30)
    {
      printf("\n-x option only accepts integer values between 10 and 30\n");
      return (1);
    }
  server->width = tmp;
  return (0);
}
