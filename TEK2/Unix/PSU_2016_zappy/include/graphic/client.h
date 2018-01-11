/*
** client.h for client.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:08:10 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:08:23 2017 Nicolas TROGNOT
*/

#ifndef CLIENT_H_
# define CLIENT_H_
# include <netdb.h>
# include <stdio.h>

typedef struct		s_client
{
  int			port;
  char			*ip_address;
  struct sockaddr_in	config;
  struct protoent	*proto;
  int32_t		sock_id;
  FILE			*srv_f;
  fd_set		rdfs;
  char			*buf;
}			t_client;

void			free_client(t_client *client);
t_client		*init_client(t_client *client,
				     int port, const char *ip_address);

#endif /* !CLIENT_H_ */
