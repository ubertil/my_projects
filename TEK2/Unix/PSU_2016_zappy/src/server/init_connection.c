/*
** init_connection.c for init_connection.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:41:01 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:23:30 2017 Nicolas TROGNOT
*/

#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "server/file.h"

static int		init_loop_select(fd_set *readfds, int fd,
					 int *client_socket)
{
  int			i;
  int			sd;
  int			max_sd;
  struct timeval	tv;

  tv.tv_sec = 0;
  tv.tv_usec = 100000;
  FD_ZERO(readfds);
  FD_SET(fd, readfds);
  max_sd = fd;
  i = -1;
  while (++i < SOMAXCONN)
    {
      sd = client_socket[i];
      if(sd > 0)
	FD_SET(sd, readfds);
      if(sd > max_sd)
	max_sd = sd;
    }
  select(max_sd + 1, readfds, NULL,  NULL, &tv);
  return (max_sd);
}

static void		set_elem_from_fd(t_server *server,
					 int fd, int *elem)
{
  t_player		*t;

  t = server->players;
  while (t && t->fd != fd)
    t = t->next;
  if (!t)
    return ;
  t->elem_in_socket_array = elem;
}

static void		handle_clients(fd_set *readfds,
				       int *client_socket,
				       t_server *server)
{
  int			valread;
  int			i;
  int			sd;
  char			*buf;
  size_t		t;

  t = 64;
  i = -1;
  buf = NULL;
  while (++i < SOMAXCONN)
    {
      sd = client_socket[i];
      if (FD_ISSET(sd, readfds))
	{
	  if ((valread = getline(&buf, &t, get_file_from_fd(server, sd))) < 0)
	    close_connection(server, sd, &client_socket[i]);
	  else
	    {
	      set_elem_from_fd(server, sd, &client_socket[i]);
	      handle_command(server, sd, buf, valread);
	    }
	  free(buf);
	  buf = NULL;
	}
    }
}

static int		setup_select(t_server *server, const int fd)
{
  int			client_socket[SOMAXCONN];
  int			i;
  fd_set		readfds;
  struct timeval	t[2];
  double		tmp;

  gettimeofday(&t[0], NULL);
  tmp = t[0].tv_sec * 1000000 + t[0].tv_usec;
  server->freq_used = 1000000 / server->freq;
  i = -1;
  while (++i < SOMAXCONN)
    client_socket[i] = 0;
  server->time = 0;
  while (true)
    {
      gettimeofday(&t[1], NULL);
      server->prev_time = server->time;
      server->time = ((t[1].tv_sec * 1000000 + t[1].tv_usec) - tmp)
	/ server->freq_used;
      init_loop_select(&readfds, fd, client_socket);
      if (FD_ISSET(fd, &readfds))
	new_connection(server, fd, client_socket);
      handle_clients(&readfds, client_socket, server);
      exec_clients_command(server);
    }
  return (0);
}

int			init_connection(t_server *server)
{
  int			fd;
  struct protoent	*proto;
  struct sockaddr_in	sin;
  int			yes;

  if (((proto = getprotobyname("TCP")) == NULL) ||
      ((fd = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1))
    return (1);
  yes = 1;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->conn.port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (((setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))) == -1) ||
      ((bind(fd, (const struct sockaddr*)&sin, sizeof(sin))) == -1) ||
      (listen(fd, 42) == -1))
    return (1);
  setup_select(server, fd);
  close(fd);
  return (0);
}
