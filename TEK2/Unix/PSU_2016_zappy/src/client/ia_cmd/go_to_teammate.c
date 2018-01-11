/*
** go_to_teammate.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:46:50 2017 Lous-Emile Uberti-Ares
** Last update Thu Jun 29 14:27:17 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include "client/client.h"
#include "client/ia.h"

bool		go_to_teammate(t_client *client, const char *cmd)
{
  if (cmd && cmd[0] == '0')
    {
      client->ia->current = REACHED_DESTINATION;
    }
  else
    {
      move_to(client, cmd[0] - 48, true);
      client->ia->current = REACHED_DESTINATION;
    }
  return (true);
}
