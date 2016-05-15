/*
** make_ants_move.c for make_ant_move in /home/grella_c/rendu/CPE_2015_Lemin/bonus
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Sat Apr 23 18:11:50 2016 come grellard
** Last update Sun Apr 24 15:05:58 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include "visu.h"

void	idxs_to_zero(t_visu *visu)
{
  int	i;

  i = 0;
  while (i < visu->nb_ants)
    {
      visu->ants[i].idx = 0;
      i += 1;
    }
}

void	lens_to_one(t_visu *visu)
{
  int	i;

  i = 0;
  while (i < visu->nb_ants)
    {
      visu->ants[i].idx = 0;
      visu->ants[i].len = 1;
      i += 1;
    }
}

int			disp_ant(t_visu *visu, int num_ant)
{
  t_bunny_position	pos;
  int			check;

  check = 0;
  pos.x = visu->ants[num_ant].dest.x - 40;
  pos.y = visu->ants[num_ant].dest.y - 45;
  if (visu->ants[num_ant].idx < visu->ants[num_ant].len)
    {
      check = 1;
      if (visu->ants[num_ant].way[visu->ants[num_ant].idx].x != 0)
	blit_alpha(visu->pix, visu->ant,
		   &visu->ants[num_ant].way[visu->ants[num_ant].idx]);
      visu->ants[num_ant].idx += 1;
    }
  else
    blit_alpha(visu->pix, visu->ant, &pos);
  return (check);
}

void	make_ants_move(t_visu *visu)
{
  int	check;
  int	num_ant;

  check = 1;
  idxs_to_zero(visu);
  while (check > 0)
    {
      check = 0;
      num_ant = -1;
      set_background(visu->pix, BLACK);
      show_all_links(visu);
      show_all_rooms(visu);
      while (++num_ant < visu->nb_ants)
	check += disp_ant(visu, num_ant);
      bunny_blit(&visu->win->buffer, &visu->pix->clipable, NULL);
      bunny_display(visu->win);
      usleep(1000);
    }
  lens_to_one(visu);
  usleep(100000);
}
