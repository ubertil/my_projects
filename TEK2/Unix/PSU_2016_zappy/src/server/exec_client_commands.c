/*
** exec_client_commands.c for exec_client_commands.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:23:51 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:24:19 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include <string.h>
#include "common/define_commands.h"
#include "common/resources.h"
#include "server/commands.h"
#include "server/server.h"

static void		do_it(t_server *server, t_player *tmp)
{
  exec_command(server, tmp, NULL, -1);
  free(tmp->commands[tmp->command_idx].cmd);
  tmp->commands[tmp->command_idx].cmd = NULL;
  tmp->command_idx = (tmp->command_idx + 1) % 10;
  if (tmp->commands[tmp->command_idx].cmd != NULL)
    tmp->commands[tmp->command_idx].beg = server->time;
}

void		exec_clients_command(t_server *server)
{
  t_player		*tmp;

  tmp = server->players;
  while (tmp)
    {
      if (tmp->commands[tmp->command_idx].cmd != NULL)
	{
	  if (strcmp(tmp->commands[tmp->command_idx].cmd, INCANTATION_STR)
	      == 0 && tmp->is_incanting == 0)
	    {
	      check_incantation(server, tmp->fd);
	      tmp->is_incanting = 1;
	    }
	  if (server->time >= tmp->commands[tmp->command_idx].beg +
	      tmp->commands[tmp->command_idx].cost)
	    do_it(server, tmp);
	}
      if (tmp->is_graphical == 0)
	tmp->inventory[FOOD] -= (server->time - server->prev_time);
      if (tmp->inventory[FOOD] <= 0)
	close_connection(server, tmp->fd, tmp->elem_in_socket_array);
      tmp = tmp->next;
    }
}
