/*
** action_cmd.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Thu Jun 22 16:21:41 2017 alexis papadimitriou
** Last update Fri Jun 30 11:40:11 2017 Lous-Emile Uberti-Ares
*/

#include <string.h>
#include "client/client.h"
#include "common/define_commands.h"
#include "common/utils/utils.h"

bool	look(t_client *client)
{
  secure_write(client->sock_id, LOOK_STR, sizeof(LOOK_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	get_inventory(t_client *client)
{
  secure_write(client->sock_id, INVENTORY_STR, sizeof(INVENTORY_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	broadcast_text(t_client *client, const char *msg)
{
  secure_write(client->sock_id, BROADCAST_STR, sizeof(BROADCAST_STR) - 1);
  secure_write(client->sock_id, " ", 1);
  secure_write(client->sock_id, msg, strlen(msg));
  secure_write(client->sock_id, "\n", 1);
  return (true);
}
