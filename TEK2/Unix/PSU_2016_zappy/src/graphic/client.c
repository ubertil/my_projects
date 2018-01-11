/*
** client.c for client.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:31:35 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:31:40 2017 Nicolas TROGNOT
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "graphic/client.h"

void		free_client(t_client *client)
{
  close(client->sock_id);
  fclose(client->srv_f);
  free(client->buf);
  free(client->ip_address);
  free(client);
}

static t_client		*init_connection(t_client *client)
{
  client->config.sin_family = AF_INET;
  client->config.sin_port = htons(client->port);
  client->config.sin_addr.s_addr = inet_addr(client->ip_address);
  if (!(client->proto = getprotobyname("TCP")) ||
      (client->sock_id = socket(AF_INET, SOCK_STREAM, client->proto->p_proto))
      == -1 ||
      connect(client->sock_id, (struct sockaddr *)&client->config,
	      sizeof(client->config)) == -1 ||
      (client->srv_f = fdopen(client->sock_id, "r")) == NULL)
    return (NULL);
  client->buf = NULL;
  return (client);
}

t_client	*init_client(t_client *client,
			     int port, const char *ip_address)
{
  if (ip_address)
    {
      free(client->ip_address);
      if ((client->ip_address = strdup(ip_address)) == NULL)
	return (NULL);
    }
  client->port = port;
  return (init_connection(client));
}
