/*
** diretion.h for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 14:37:08 2017 Lous-Emile Uberti-Ares
** Last update Thu Jun 29 12:07:09 2017 Lous-Emile Uberti-Ares
*/

#ifndef DIRECTION_H_
# define DIRECTION_H_
# include <stdbool.h>

typedef struct		s_client t_client;

typedef struct		s_dir
{
  int			dir[3];
  bool			(*f)(t_client *client);
}			t_dir;

typedef struct		s_destination
{
  bool			(*func)(t_client *client);
  struct s_destination	*next;
}			t_destination;

typedef struct		s_path
{
  int			path_nb;
  t_destination		*dest;
}			t_path;

bool			move_to(t_client *client, const int to_go,
				bool broadcast);

#endif /* !DIRECTION_H_ */
