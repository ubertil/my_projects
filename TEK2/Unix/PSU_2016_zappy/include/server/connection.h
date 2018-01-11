/*
** connection.h for connection.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:05:23 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:05:35 2017 Nicolas TROGNOT
*/

#ifndef CONNECTION_H_
# define CONNECTION_H_
# include <sys/epoll.h>

typedef struct		s_connection
{
  int			port;
  struct epoll_event	event;
  struct epoll_event	*events;
  int			efd;
}			t_connection;

int			init_connection(t_server *server);
int			close_connection(t_server *server, const int fd,
					 int *c);
int			new_connection(t_server *server, const int fd,
				       int *client_socket);
int			handle_command(t_server *server, const int fd,
					 char *buf, int valread);

#endif /* !CONNECTION_H_ */
