/*
** load_screen.c for load_screen in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Apr 22 12:17:28 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:34:00 2016 louis-emile uberti-ares
*/

#include "visu.h"

int		load_screen(t_visu *visu, char *str)
{
  if (str != NULL && my_strcmp(str, "--abel") == 0)
    {
      if (((visu->screen =
	    bunny_load_pixelarray("./ressources/abel_screen.png")) == NULL)
	  || ((visu->room =
	       bunny_load_pixelarray("./ressources/poulet.png")) == NULL)
	  || ((visu->room_end =
	       bunny_load_pixelarray("./ressources/bucket.png")) == NULL))
	return (-1);
    }
  else
    if (((visu->screen =
	  bunny_load_pixelarray("./ressources/lemin_screen.png")) == NULL)
	|| ((visu->room =
	     bunny_load_pixelarray("./ressources/fourmilliere.png")) == NULL)
	|| ((visu->room_end =
	     bunny_load_pixelarray("./ressources/fourmilliere.png")) == NULL))
      return (-1);
  return (0);
}
