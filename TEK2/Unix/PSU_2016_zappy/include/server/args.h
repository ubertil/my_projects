/*
** args.h for args.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:02:50 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:04:08 2017 Nicolas TROGNOT
*/

#ifndef ARGS_H_
# define ARGS_H_
# define NB_ARGS 6
# include "server.h"

typedef struct		s_arg
{
  char			c;
  char			(*func)(t_server *server, char *arg);
}			t_arg;

char			arg_p(t_server *server, char *arg);
char			arg_x(t_server *server, char *arg);
char			arg_y(t_server *server, char *arg);
char			arg_n(t_server *server, char *arg);
char			arg_c(t_server *server, char *arg);
char			arg_f(t_server *server, char *arg);

#endif /* !ARGS_H_ */
