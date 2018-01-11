/*
** transaction.c for transaction.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:32:11 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:11:57 2017 Nicolas TROGNOT
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "common/protocol.h"
#include "common/utils/utils.h"
#include "graphic/transaction.h"
#include "graphic/client.h"
#include "graphic/command_handler.h"

static char			*append_buf(char *str, char *c,
					    int n)
{
  char				*tmp;

  c[n] = '\0';
  if (str == NULL)
    {
      if ((tmp = strdup(c)) == NULL)
	return (NULL);
      return (tmp);
    }
  if ((tmp = malloc(strlen(str) + strlen(c) + 1)) == NULL)
    return (NULL);
  tmp = strcpy(tmp, str);
  tmp = strcat(tmp, c);
  tmp[strlen(str) + strlen(c)] = '\0';
  free(str);
  return (tmp);
}

bool			manage_transaction(t_core *c,
					   struct timeval *timeout)
{
  char			buf[READ_SIZE + 1];
  int			n;

  FD_ZERO(&c->client->rdfs);
  FD_SET(c->client->sock_id, &c->client->rdfs);
  if (select(c->client->sock_id + 1,
	     &c->client->rdfs, NULL, NULL, timeout) == -1)
    return (false);
  if (FD_ISSET(c->client->sock_id, &c->client->rdfs))
    {
      if ((n = read(c->client->sock_id, &buf, READ_SIZE)) == -1)
	return (false);
      c->client->buf = append_buf(c->client->buf, buf, n);
      if (buf[n - 1] == '\n')
	{
	  c->client->buf[strlen(c->client->buf) - 1] = '\0';
	  if (!handle_commands(c))
	    return (false);
	  free(c->client->buf);
	  c->client->buf = NULL;
	}
    }
  return (true);
}

bool		init_transaction(t_core *core)
{
  char		*input;
  size_t	len;

  len = 64;
  input = NULL;
  if (getline(&input, &len, core->client->srv_f) < 1 ||
      strcmp(input, P_WELCOME))
    return (false);
  secure_write(core->client->sock_id, IS_GRAPHIC_NN, strlen(IS_GRAPHIC_NN));
  secure_write(core->client->sock_id, "\n", 1);
  return (true);
}
