/*
** client_loop.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 14:21:49 2017 alexis papadimitriou
**
** Last update Fri Jun 30 13:41:33 2017 grella_c
** Last update Thu Jun 22 14:14:51 2017 Lous-Emile Uberti-Ares
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "client/client.h"
#include "common/utils/utils.h"
#include "common/protocol.h"

static const		char *g_act[MAX_IA_ACTIONS] =
  {
    "Checking number of food",
    "Checking number of stones for incantation",
    "Checking number of players for incantation",
    "Incantation started !",
    "Calling renforcements !",
    "Talking and listening to my team",
    "Reached my target destination",
    "Is there food here ?",
    "Going to get food",
    "Taking the food",
    "Joining my teammates",
    "Taking the stone",
    "Is there stones here ?",
    "Going to get stones",
    "Setting stones"
  };

static bool		manage_header(t_client *client)
{
  char			*input;
  size_t		len;

  len = 64;
  input = NULL;
  if (getline(&input, &len, client->srv_f) < 1 || strcmp(input, P_WELCOME))
    return (false);
  free(input);
  input = NULL;
  secure_write(client->sock_id, client->team_name, strlen(client->team_name));
  secure_write(client->sock_id, "\n", 1);
  if (getline(&input, &len, client->srv_f) < 1 || atoi(input) < 1)
    return (false);
  free(input);
  input = NULL;
  if (getline(&input, &len, client->srv_f) < 1)
    return (false);
  free(input);
  return (true);
}

static bool		read_from_server(t_client *client)
{
  size_t		len;
  int32_t		size;

  len = 64;
  client->ia->input = NULL;
  if ((size = getline(&client->ia->input, &len, client->srv_f)) < 1 ||
      !strcmp(client->ia->input, "dead\n"))
    return (false);
  dprintf(1, "%s\n", g_act[client->ia->current]);
  client->ia->func[client->ia->current](client, client->ia->input);
  free(client->ia->input);
  client->ia->input = NULL;
  return (true);
}

void			client_loop(t_client *client)
{
  struct timeval	timeout;

  timeout.tv_sec = 0;
  timeout.tv_usec = 10000;
  client->connected = manage_header(client);
  get_inventory(client);
  while (client->connected)
    {
      FD_ZERO(&client->rdfs);
      FD_SET(client->sock_id, &client->rdfs);
      if (select(client->sock_id + 1, &client->rdfs, NULL, NULL, &timeout)
	  == -1)
	return ;
      if (FD_ISSET(client->sock_id, &client->rdfs))
	client->connected = read_from_server(client);
    }
}
