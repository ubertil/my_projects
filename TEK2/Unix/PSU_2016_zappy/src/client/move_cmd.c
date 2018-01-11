/*
** move_cmd.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Thu Jun 22 15:53:13 2017 alexis papadimitriou
** Last update Fri Jun 30 11:40:29 2017 Lous-Emile Uberti-Ares
*/

#include "client/client.h"
#include "common/define_commands.h"
#include "common/utils/utils.h"

bool	move_forward(t_client *client)
{
  secure_write(client->sock_id, FORWARD_STR, sizeof(FORWARD_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	move_right(t_client *client)
{
  secure_write(client->sock_id, RIGHT_STR, sizeof(RIGHT_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}

bool	move_left(t_client *client)
{
  secure_write(client->sock_id, LEFT_STR, sizeof(LEFT_STR) - 1);
  secure_write(client->sock_id, "\n", 1);
  return (true);
}
