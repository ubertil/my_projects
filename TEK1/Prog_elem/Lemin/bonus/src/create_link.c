/*
** create_matrix.c for create_matrix in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 14 14:10:08 2016 louis-emile uberti-ares
** Last update Sun Apr 24 17:12:10 2016 nicolas wadel
*/

#include <stdlib.h>
#include "visu.h"

t_link		*add_to_list(t_visu *visu, t_link **old, char *str)
{
  int		n1;
  int		n2;
  t_link	*link;

  if ((link = malloc(sizeof(t_link))) == NULL
      || check_link(str) == 1
      || ((link->s1 = get_first_room(str)) == NULL)
      || ((link->s2 = get_second_room(str)) == NULL))
    return (NULL);
  n1 = find_room(visu->rooms, link->s1);
  n2 = find_room(visu->rooms, link->s2);
  if ((n1 == -1) || (n2 == -1))
    return (NULL);
  link->next = *old;
  return (link);
}

int		add_link(t_visu *visu, char *str)
{
  if ((visu->link = add_to_list(visu, &visu->link, str)) == NULL)
    return (1);
  return (0);
}
