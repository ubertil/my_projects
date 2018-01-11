/*
** take_stone.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 14:09:53 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 14:10:23 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include "client/ia.h"
#include "client/client.h"

bool		take_stone(t_client *client, const char *cmd)
{
  char		*input;

  take_object(client, cmd);
  input = get_command(client, NULL);
  client->ia->current = NB_STONES;
  if (input)
    free(input);
  get_inventory(client);
  return (true);
}
