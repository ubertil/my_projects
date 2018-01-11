/*
** arg_n.c for arg_n.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/args
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:21:57 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:22:00 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server/server.h"

char		arg_n(t_server *server, char *arg)
{
  t_name	*name;
  t_name	*tmp;

  tmp = server->names;
  while (tmp)
    {
      if (strcmp(arg, tmp->name) == 0)
	{
	  printf("\nError : each team name must be unique\n");
	  return (1);
	}
      tmp = tmp->next;
    }
  if ((name = malloc(sizeof(t_name))) == NULL ||
      (name->name = strdup(arg)) == NULL)
    return (1);
  name->next = server->names;
  server->names = name;
  return (0);
}
