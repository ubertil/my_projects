/*
** find_room.c for find_room in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Apr 15 12:08:03 2016 louis-emile uberti-ares
** Last update Sun Apr 24 12:37:22 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "visu.h"

int		find_room(t_pos *rooms, char *str)
{
  int		nb;
  t_pos		*tmp;

  nb = 0;
  tmp = rooms;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->room_name, str) == 0)
	return (nb);
      ++nb;
      tmp = tmp->next;
    }
  return (-1);
}
