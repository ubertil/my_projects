/*
** go_to_stone.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:49:36 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 12:17:38 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include "client/client.h"
#include "client/ia.h"

bool		go_to_stone(t_client *client, const char *cmd)
{
  char		*input;

  move_to(client, rand() % 15, false);
  client->ia->current = STONE_ON_TILE;
  input = get_command(client, NULL);
  free(input);
  look(client);
  (void)cmd;
  return (true);
}
