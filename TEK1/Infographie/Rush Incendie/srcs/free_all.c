/*
** free_all.c for free_all in /home/uberti_l/rendu/gfx_incendie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Dec  4 23:15:24 2015 louis-emile uberti-ares
** Last update Sat Dec  5 00:59:16 2015 louis-emile uberti-ares
*/

#include <lapin.h>
#include "flame.h"

void		free_all(t_fire *fire)
{
  bunny_delete_clipable(&fire->pix->clipable);
  bunny_stop(fire->win);
  bunny_free(&fire->win);
  bunny_free(fire);
}
