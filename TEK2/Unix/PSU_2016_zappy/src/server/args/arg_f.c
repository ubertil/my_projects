/*
** arg_f.c for arg_f.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/args
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:21:48 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:21:50 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include <stdio.h>
#include "server/server.h"

char	arg_f(t_server *server, char *arg)
{
  int	tmp;

  tmp = atoi(arg);
  if (tmp < 2 || tmp > 10000)
    {
      printf("\n-f option only accepts integer values between 2 and 10000\n");
      return (1);
    }
  server->freq = atoi(arg);
  return (0);
}
