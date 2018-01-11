/*
** handle_connection.c for handle_connection.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:14:16 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:16:27 2017 Nicolas TROGNOT
*/

#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include "server/commands.h"
#include "server/server.h"
#include "common/protocol.h"
#include "common/define_commands.h"

static const t_command_def	g_cmds[] =
  {
    {FORWARD_STR, FORWARD_TIME},
    {RIGHT_STR, RIGHT_TIME},
    {LEFT_STR, LEFT_TIME},
    {LOOK_STR, LOOK_TIME},
    {INVENTORY_STR, INVENTORY_TIME},
    {BROADCAST_STR, BROADCAST_TIME},
    {CONNECT_NBR_STR, CONNECT_NBR_TIME},
    {FORK_STR, FORK_TIME},
    {EJECT_STR, EJECT_TIME},
    {TAKE_STR, TAKE_TIME},
    {SET_STR, SET_TIME},
    {INCANTATION_STR, INCANTATION_TIME}
  };

int		get_cmd_cost(char *buf)
{
  int		i;

  i = -1;
  while (++i < NB_COMMANDS)
    if (strncmp(buf, g_cmds[i].cmd, strlen(g_cmds[i].cmd)) == 0)
      return (g_cmds[i].cost);
  return (-1);
}

void		add_command_to_client(t_server *server, const int fd,
				      char *buf)
{
  int		i;
  int		j;
  t_player	*tmp;

  tmp = server->players;
  while (tmp && tmp->fd != fd)
    tmp = tmp->next;
  if (!tmp)
    return ;
  i = tmp->command_idx;
  j = -1;
  while (++j < 10)
    {
      if (tmp->commands[i].cmd == NULL)
	{
	  tmp->commands[i].cmd = strdup(buf);
	  tmp->commands[i].cost = get_cmd_cost(buf);
	  tmp->commands[i].beg = server->time;
	  return ;
	}
      else
	i = (i + 1) % 10;
    }
}

static void	serve_all_client(t_server *server)
{
  t_player	*this;

  this = server->players;
  while (this)
    {
      if (this->is_graphical == 0 && this->team_name != NULL)
	cmd_pnw(server, this);
      this = this->next;
    }
}

int		handle_command(t_server *server, const int fd,
			       char *buf, int valread)
{
  t_player	*p;

  buf[valread - 1] = '\0';
  p = server->players;
  while (p && p->fd != fd)
    p = p->next;
  if (!p)
    return (1);
  if (p->team_name == NULL && confirm_player(server, buf, fd) == 0)
    {
      if (strcmp(buf, IS_GRAPHIC_NN) == 0)
	{
	  cmd_msz(server);
	  cmd_bct_all_map(server);
	  cmd_tna(server);
	  serve_all_client(server);
	}
    }
  else
    add_command_to_client(server, fd, buf);
  return (0);
}

void		pop_client(t_server *server, const int fd)
{
  t_player      *current;
  t_player      *prev;

  current = server->players;
  prev = NULL;
  while (current && current->fd != fd)
    {
      prev = current;
      current = current->next;
    }
  if (!current)
    return ;
  if (prev)
    prev->next = current->next;
  else
    server->players = current->next;
  current->next = NULL;
}

int		close_connection(t_server *server, const int fd,
				 int *c)
{
  t_player	*tmp;

  tmp = server->players;
  while (tmp->fd != fd && tmp->next != NULL)
    tmp = tmp->next;
  if (tmp)
    {
      free(tmp->team_name);
      tmp->team_name = NULL;
    }
  *c = 0;
  release_inventory(server, tmp);
  dprintf(fd, "dead\n");
  close(fd);
  fclose(tmp->file);
  cmd_pdi(server, tmp);
  pop_client(server, fd);
  return (0);
}

int			new_connection(t_server *server, const int infd,
				       int *client_socket)
{
  int			new_socket;
  int			addrlen;
  struct sockaddr_in	address;
  int			i;

  addrlen = sizeof(address);
  if ((new_socket = accept(infd, (struct sockaddr *)&address,
			   (socklen_t *)&addrlen)) < 0)
    return (-1);
  if (add_player(server, new_socket) == 0)
    {
      write(new_socket, P_WELCOME, strlen(P_WELCOME));
      i = -1;
      while (++i < SOMAXCONN)
	if (client_socket[i] == 0)
	  {
	    client_socket[i] = new_socket;
	    return (new_socket);
	  }
      return (new_socket);
    }
  return (-1);
}
