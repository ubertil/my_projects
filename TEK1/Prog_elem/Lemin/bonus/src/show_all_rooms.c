/*
** show_all_rooms.c for show_all_rooms in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 21 11:56:14 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:33:39 2016 louis-emile uberti-ares
*/

#include "visu.h"

void			show_all_rooms(t_visu *visu)
{
  t_pos			*tmp;
  t_bunny_position	pos;
  double		i;

  tmp = visu->rooms;
  i = -1;
  while (tmp)
    {
      pos.x = tmp->posxy.x - 40;
      pos.y = tmp->posxy.y - 47;
      if (tmp->nb == 2)
	blit_alpha(visu->pix, visu->room_end, &pos);
      else if (tmp->nb == 1)
	blit_alpha(visu->pix, visu->room, &pos);
      else if (tmp->nb == 0)
	{
	  tekcircle(visu->pix, &tmp->posxy, 40, WHITE);
	  i = -1;
	  while (++i < 40)
	    tekcircle(visu->pix, &tmp->posxy, i, RED);
	}
      tmp = tmp->next;
    }
}
