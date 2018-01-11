/*
** get_command.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Jun 30 10:59:45 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 12:17:55 2017 Lous-Emile Uberti-Ares
*/

#include <string.h>
#include <stdlib.h>
#include "client/client.h"
#include "client/ia.h"

char		*get_command(t_client *client, bool (*func)(t_client *client))
{
  char		*input;
  size_t	len;

  len = 0;
  input = NULL;
  FD_ZERO(&client->rdfs);
  FD_SET(client->sock_id, &client->rdfs);
  if (func)
    func(client);
  while (!FD_ISSET(client->sock_id, &client->rdfs))
    continue;
  getline(&input, &len, client->srv_f);
  if (strcmp(input, "dead\n") == 0)
    {
      free(input);
      return (NULL);
    }
  return (input);
}
