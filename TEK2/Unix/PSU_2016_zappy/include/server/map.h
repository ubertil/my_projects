/*
** map.h for map.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:05:58 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:21:34 2017 Nicolas TROGNOT
*/

#ifndef MAP_H_
# define MAP_H_
# include "common/resources.h"

typedef struct		s_server t_server;

typedef struct		s_mineral
{
  int			odd[2];
  enum e_item		item;
}			t_mineral;

typedef struct		s_case
{
  int			content[NB_ITEM];
}			t_case;

typedef struct		s_map
{
  t_case		**cases;
}			t_map;

int			build_map(t_server *server);

#endif /* !MAP_H_ */
