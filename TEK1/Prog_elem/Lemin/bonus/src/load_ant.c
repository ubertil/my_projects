/*
** load_ant.c for load_ant in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 21 21:23:21 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:33:23 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "visu.h"

int		load_ant(t_visu *visu, char *str)
{
  if (str != NULL && my_strcmp(str, "--abel") == 0)
    {
      if ((visu->ant =
	   bunny_load_pixelarray("./ressources/abel_le_grand.png")) == NULL)
	return (-1);
    }
  else
    if ((visu->ant =
	 bunny_load_pixelarray("./ressources/fourmis.png")) == NULL)
      return (-1);
  return (0);
}
