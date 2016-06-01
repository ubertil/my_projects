/*
** tekray.c for tekray in /home/uberti_l/rendu/Infographie/gfx_raytracer1/tcore
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Feb  4 16:55:27 2016 louis-emile uberti-ares
** Last update Thu May 19 23:08:36 2016 louis-emile uberti-ares
*/

#include <math.h>
#include "raytracer2.h"

void	tekray(const t_bunny_position *screen_info,
	       double *x, double *y, double *z)
{
  *x = screen_info[1].x - screen_info[0].x / 2;
  *y = screen_info[1].y - screen_info[0].y / 2;
  *z = -(screen_info[0].x / (2 * tan(FOV / 2)));
}
