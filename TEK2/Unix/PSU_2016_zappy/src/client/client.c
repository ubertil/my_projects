/*
** client.c for exam in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy/include/client
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 11:51:45 2017 alexis papadimitriou
** Last update Sun Jul  2 19:02:52 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "client/client.h"
#include "common/utils/errors.h"

static bool	init_connection(t_client *client, const char *ip,
				uint16_t port)
{
  client->config.sin_family = AF_INET;
  client->config.sin_port = htons(port);
  if (ip)
    client->config.sin_addr.s_addr = inet_addr(ip);
  else
    client->config.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (!(client->proto = getprotobyname("TCP")) ||
      (client->sock_id = socket(AF_INET, SOCK_STREAM, client->proto->p_proto))
      == -1 ||
      connect(client->sock_id, (struct sockaddr *)&client->config,
	      sizeof(client->config)) == -1 ||
      (client->srv_f = fdopen(client->sock_id, "r")) == NULL)
    return (false);
  return (true);
}

t_client	*init_client(const char *team_name, const char *ip,
			     uint16_t port)
{
  t_client	*new;

  if (((new = malloc(sizeof(t_client))) == NULL) ||
      ((new->ia = init_ia()) == NULL))
    return (p_error(CLIENT_MLLC_ERR));
  new->team_name = team_name;
  new->level = 1;
  if (!init_connection(new, ip, port))
    return (p_error(CLIENT_SCKT_ERR));
  return (new);
}

void		free_client(t_client *client)
{
  fclose(client->srv_f);
  close(client->sock_id);
  free_ia(client->ia);
  free(client);
}
