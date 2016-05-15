/*
** music.c for start_music in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 21 18:22:41 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:33:06 2016 louis-emile uberti-ares
*/

#include "visu.h"

int		close_music(t_visu *visu)
{
  bunny_delete_sound((t_bunny_sound *)visu->lemin);
  return (0);
}

int		start_music(t_visu *visu, char *str)
{
  if (str != NULL && my_strcmp(str, "--abel") == 0)
    {
      if ((visu->lemin = bunny_load_music("./ressources/abel.ogg")) == NULL)
	return (-1);
    }
  else
    if ((visu->lemin = bunny_load_music("./ressources/lemin.ogg")) == NULL)
      return (-1);
  bunny_sound_play((t_bunny_sound *)visu->lemin);
  bunny_sound_loop((t_bunny_sound *)visu->lemin, 1);
  return (0);
}
