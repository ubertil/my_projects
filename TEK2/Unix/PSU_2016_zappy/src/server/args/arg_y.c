/*
** arg_y.c for arg_y.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/args
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:22:20 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:22:29 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include <stdio.h>
#include "server/server.h"

char	arg_y(t_server *server, char *arg)
{
  int	tmp;

  tmp = atoi(arg);
  if (tmp < 10 || tmp > 30)
    {
      printf("\n-y option only accepts integer values between 10 and 30\n");
      return (1);
    }
  server->height = atoi(arg);
  return (0);
}
