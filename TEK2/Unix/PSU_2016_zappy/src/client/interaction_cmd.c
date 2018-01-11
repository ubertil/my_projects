/*
** interaction_cmd.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Thu Jun 22 16:34:30 2017 alexis papadimitriou
** Last update Fri Jun 30 11:41:13 2017 Lous-Emile Uberti-Ares
*/

#include "client/client.h"
#include "common/define_commands.h"
#include "common/utils/utils.h"

bool	get_available_slot(t_client *client)
{
  secure_write(client->sock_id, CONNECT_NBR_STR, sizeof(CONNECT_NBR_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	do_fork(t_client *client)
{
  secure_write(client->sock_id, FORK_STR, sizeof(FORK_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	eject(t_client *client)
{
  secure_write(client->sock_id, EJECT_STR, sizeof(EJECT_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}
