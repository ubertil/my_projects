/*
** resources_cmd.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Thu Jun 22 16:42:28 2017 alexis papadimitriou
** Last update Fri Jun 30 15:19:36 2017 grella_c
*/

#include <string.h>
#include "client/client.h"
#include "common/define_commands.h"
#include "common/utils/utils.h"

bool	take_object(t_client *client, const char *object)
{
  secure_write(client->sock_id, TAKE_STR, sizeof(TAKE_STR) - 1);
  secure_write(client->sock_id, " ", 1);
  secure_write(client->sock_id, object, strlen(object));
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	set_object(t_client *client, const char *object)
{
  secure_write(client->sock_id, SET_STR, sizeof(SET_STR) - 1);
  secure_write(client->sock_id, " ", 1);
  secure_write(client->sock_id, object, strlen(object));
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	do_incantation(t_client *client)
{
  secure_write(client->sock_id, INCANTATION_STR, sizeof(INCANTATION_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}
