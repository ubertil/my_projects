/*
** show_all_links.c for show_all_links in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 21 13:38:29 2016 louis-emile uberti-ares
** Last update Sun Apr 24 12:46:54 2016 louis-emile uberti-ares
*/

#include "visu.h"

t_bunny_position	get_first_position(t_visu *visu, char *s1)
{
  t_bunny_position	tmp;
  t_pos			*pos;

  pos = visu->rooms;
  while (my_strcmp(pos->room_name, s1) != 0)
    pos = pos->next;
  tmp.x = pos->posxy.x;
  tmp.y = pos->posxy.y;
  return (tmp);
}

void			show_all_links(t_visu *visu)
{
  t_link		*tmp;
  t_bunny_position	pos[2];
  t_bunny_position	posxy;

  tmp = visu->link;
  while (tmp)
    {
      posxy = get_first_position(visu, tmp->s1);
      pos[0].x = posxy.x;
      pos[0].y = posxy.y;
      posxy = get_first_position(visu, tmp->s2);
      pos[1].x = posxy.x;
      pos[1].y = posxy.y;
      tekline(visu->pix, pos, WHITE);
      tmp = tmp->next;
    }
}
