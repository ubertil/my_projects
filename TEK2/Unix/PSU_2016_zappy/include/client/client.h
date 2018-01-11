/*
** client.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy/include/client
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 10:50:08 2017 alexis papadimitriou
** Last update Fri Jun 30 11:46:27 2017 Lous-Emile Uberti-Ares
*/

#ifndef CLIENT_H_
# define CLIENT_H_
# include <stdint.h>
# include <netdb.h>
# include <stdio.h>
# include <stdbool.h>
# include "ia.h"
# include "common/resources.h"

typedef struct		s_client
{
  int32_t		sock_id;
  struct sockaddr_in	config;
  struct protoent	*proto;
  FILE			*srv_f;
  fd_set		rdfs;
  bool			connected;
  const char		*team_name;
  t_ia			*ia;
  int			level;
}			t_client;

t_client		*init_client(const char *team_name, const char *ip,
				     uint16_t port);
int			sighandler(int signum, t_client *_client);
void			free_client(t_client *client);
void			client_loop(t_client *client);
bool			move_forward(t_client *client);
bool			move_right(t_client *client);
bool			move_left(t_client *client);
bool			look(t_client *client);
bool			get_inventory(t_client *client);
bool			broadcast_text(t_client *client, const char *msg);
bool			get_available_slot(t_client *client);
bool			do_fork(t_client *client);
bool			do_eject(t_client *client);
bool			take_object(t_client *client, const char *object);
bool			set_object(t_client *client, const char *object);
bool			do_incantation(t_client *client);

#endif /* !CLIENT_H_ */
