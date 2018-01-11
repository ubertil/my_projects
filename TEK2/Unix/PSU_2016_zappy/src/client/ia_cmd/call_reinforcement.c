/*
** call_reinforcement.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:46:29 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 14:23:56 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include <stdio.h>
#include "client/client.h"
#include "common/utils/utils.h"

bool		call_reinforcement(t_client *client, UNUSED const char *cmd)
{
  char		*msg;

  asprintf(&msg, "%s %d", "ASSEMBLE", rot13(client->level));
  broadcast_text(client, msg);
  client->ia->current = NB_PLAYERS;
  free(msg);
  look(client);
  return (true);
}
