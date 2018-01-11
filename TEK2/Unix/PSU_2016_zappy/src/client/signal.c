/*
** signal.c for signal in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Jun 22 11:10:07 2017 Lous-Emile Uberti-Ares
** Last update Thu Jun 22 11:19:48 2017 alexis papadimitriou
*/

#include <signal.h>
#include <stdlib.h>
#include "client/client.h"

int			sighandler(int signum, t_client *_client)
{
  static t_client	*client = NULL;

  if (signum == -42)
    client = _client;
  else if (signum == SIGINT)
    {
      free_client(client);
      exit(EXIT_SUCCESS);
    }
  return (0);
}
