/*
** init_z_buffer.c for init_z_buffer in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 19 06:08:34 2016 louis-emile uberti-ares
** Last update Sun May 22 17:18:03 2016 louis-emile uberti-ares
*/

#include <math.h>
#include "raytracer2.h"

int		check_z_buffer(t_rtc *rtc,
			       double info[3][3], double *distlast)
{
  double	dist;

  dist = ((info[1][0] - rtc->cam_pos[0]) * (info[1][0] - rtc->cam_pos[0]) +
	  (info[1][1] - rtc->cam_pos[1]) * (info[1][1] - rtc->cam_pos[1]) +
	  (info[1][2] - rtc->cam_pos[2]) * (info[1][2] - rtc->cam_pos[2]));
  if (dist < *distlast * *distlast)
    {
      *distlast = sqrt(dist);
      return (0);
    }
  *distlast = dist;
  return (1);
}
