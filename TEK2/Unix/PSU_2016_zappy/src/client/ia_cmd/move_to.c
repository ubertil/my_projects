/*
** move_to.c for move_to in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 14:29:15 2017 Lous-Emile Uberti-Ares
** Last update Sun Jul  2 19:07:30 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include "client/client.h"
#include "client/direction.h"
#include "common/utils/utils.h"

static const t_dir	g_direction[3] =
  {
    {{1, 2, 8}, move_forward},
    {{3, 4, 5}, move_left},
    {{6, 7, -1}, move_right}
  };

bool			add_command_to_path(t_destination **target,
					    bool (*func)(t_client *client))
{
  t_destination		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (false);
  new->func = func;
  new->next = *target;
  *target = new;
  return (true);
}

bool			find_path(t_client *client, const int to_go)
{
  int			forward;
  int			pos;
  int			nb;

  pos = 0;
  forward = 1;
  while ((forward + 1) * (forward + 2) < to_go)
    {
      if (!add_command_to_path(&client->ia->target, move_forward))
	return (false);
      pos += forward * (forward + 1);
      ++forward;
    }
  nb = ABS(to_go - pos);
  if (pos > to_go && !add_command_to_path(&client->ia->target, move_left))
    return (false);
  else if (!add_command_to_path(&client->ia->target, move_right))
    return (false);
  while (nb-- > 0)
    if (!add_command_to_path(&client->ia->target, move_forward))
      return (false);
  return (true);
}

bool			path_to_target(t_client *client, const int to_go)
{
  bool			ret;

  ret = true;
  if (client->ia->target == NULL)
    ret = find_path(client, to_go);
  if (!ret)
    return (ret);
  ret = client->ia->target->func(client);
  client->ia->target = client->ia->target->next;
  return (ret);
}

bool			move_to(t_client *client, const int to_go,
				bool broadcast)
{
  int			i;
  int			j;

  i = -1;
  if (broadcast)
    {
      while (++i < 3)
	{
	  j = -1;
	  while (++j < 3)
	    if (to_go == g_direction[i].dir[j])
	      return (g_direction[i].f(client));
	}
      return (true);
    }
  else
    return (path_to_target(client, to_go));
}
