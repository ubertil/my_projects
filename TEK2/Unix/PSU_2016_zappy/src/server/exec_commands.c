/*
** exec_commands.c for exec_commands.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:18:40 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:18:41 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server/commands.h"
#include "common/define_commands.h"

static const t_commands_ptr	g_cmds[] =
  {
    {FORWARD_STR, &cmd_forward},
    {RIGHT_STR, &cmd_right},
    {LEFT_STR, &cmd_left},
    {LOOK_STR, &cmd_look},
    {INVENTORY_STR, &cmd_inventory},
    {BROADCAST_STR, &cmd_broadcast},
    {CONNECT_NBR_STR, &cmd_connect_nbr},
    {FORK_STR, &cmd_fork},
    {EJECT_STR, &cmd_eject},
    {TAKE_STR, &cmd_take},
    {SET_STR, &cmd_set},
    {INCANTATION_STR, &cmd_incantation}
  };

void		exec_command(t_server *server, t_player *p, char *to_find,
			     int cmd_idx)
{
  while (++cmd_idx < NB_COMMANDS)
    {
      if ((to_find = malloc(strlen(g_cmds[cmd_idx].cmd) + 2)) == NULL)
	return ;
      to_find = memcpy(to_find, g_cmds[cmd_idx].cmd,
		       strlen(g_cmds[cmd_idx].cmd) + 1);
      to_find = strcat(to_find, " ");
      if (strcmp(p->commands[p->command_idx].cmd, g_cmds[cmd_idx].cmd) == 0)
	{
	  g_cmds[cmd_idx].func(server, p->commands[p->command_idx].cmd
			       + strlen(g_cmds[cmd_idx].cmd), p->fd);
	  return ;
	}
      else if (strncmp(p->commands[p->command_idx].cmd, to_find,
		       strlen(to_find)) == 0)
	{
	  g_cmds[cmd_idx].func(server, p->commands[p->command_idx].cmd
			       + strlen(to_find), p->fd);
	  return ;
	}
      free(to_find);
    }
  dprintf(p->fd, "ko\n");
}
