/*
** free_all.c for free_all in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 20 15:30:28 2016 louis-emile uberti-ares
** Last update Sun Apr 24 14:33:31 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "visu.h"

void		free_args(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

void		free_all(t_visu *visu)
{
  t_pos		*curr;
  t_link	*tmp;

  while ((tmp = visu->link) != NULL)
    {
      visu->link = visu->link->next;
      free(tmp->s1);
      free(tmp->s2);
    }
  free(tmp);
  while ((curr = visu->rooms) != NULL)
    {
      visu->rooms = visu->rooms->next;
      free(curr->room_name);
      free(curr);
    }
  free(curr);
  free(visu->rooms);
  free(visu->ants);
  free(visu->link);
  bunny_stop(visu->win);
  bunny_free(visu);
}
