/*
** incantation.h for incantation.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/common
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:14:03 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:14:19 2017 Nicolas TROGNOT
*/

#ifndef INCANTATION_H_
# define INCANTATION_H_
# define NB_INCANTATION 7
# include "common/resources.h"

typedef struct		s_incantation
{
  int			nb_player;
  int			amount[NB_ITEM - 1];
}			t_incantation;

#endif /* !INCANTATION_H_ */
