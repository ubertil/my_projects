/*
** check_room.c for check_room in /home/grella_c/rendu/CPE_2015_Lemin
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Wed Apr 20 13:05:43 2016 come grellard
** Last update Sun Apr 24 13:25:12 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "visu.h"

int		check_pos_room(t_pos *rooms, int pos_x, int pos_y)
{
  t_pos		*tmp;

  tmp = rooms;
  while (tmp)
    {
      if ((tmp->posxy.x == pos_x) && (tmp->posxy.y == pos_y))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		check_name_already_exist(char **tab, t_pos **rooms)
{
  t_pos		*tmp;

  tmp = *rooms;
  while (tmp)
    {
      if (my_strcmp(tab[0], tmp->room_name) == 0)
	{
	  free_args(tab);
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		check_room(char *str, t_pos *rooms)
{
  char		**tab;
  int		pos_x;
  int		pos_y;

  pos_x = 0;
  pos_y = 0;
  if (str == NULL)
    return (1);
  if ((tab = my_str_to_wordtab(str)) == NULL)
    return (84);
  if ((tab[1] == NULL) || (tab[2] == NULL) || (tab[3] != NULL)
      || ((pos_x = (my_hard_getnbr(tab[1]))) < 0 || pos_x > WIDTH)
      || ((pos_y = (my_hard_getnbr(tab[2]))) < 0 || pos_y > HEIGHT)
      || (check_name_already_exist(tab, &rooms) == 1)
      || (check_pos_room(rooms, pos_x, pos_y) == 1))
    {
      free_args(tab);
      return (1);
    }
  free_args(tab);
  return (0);
}
