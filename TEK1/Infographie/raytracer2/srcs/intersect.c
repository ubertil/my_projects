/*
** intersect.c for intersect in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May 14 03:56:24 2016 louis-emile uberti-ares
** Last update Sun May 22 15:49:32 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

int		intersect(t_rtc *rtc, t_triangles *triangles,
			  double info[2][3], double *dist)
{
  double	all[5][3];
  double	values[5];

  vector(all[0], triangles->pos[1], triangles->pos[0]);
  vector(all[1], triangles->pos[2], triangles->pos[0]);
  cross(all[2], info[0], all[1]);
  values[0] = dot(all[0], all[2]);
  if (values[0] > -EPSILON && values[0] < EPSILON)
    return (-1);
  values[1] = 1 / values[0];
  info[1][0] = rtc->cam_pos[0] - (values[1] * info[0][0]);
  info[1][1] = rtc->cam_pos[1] - (values[1] * info[0][1]);
  info[1][2] = rtc->cam_pos[2] - (values[1] * info[0][2]);
  vector(all[3], rtc->cam_pos, triangles->pos[0]);
  values[2] = values[1] * dot(all[3], all[2]);
  if (values[2] < 0.0 || values[2] > 1.0)
    return (-1);
  cross(all[4], all[3], all[0]);
  values[3] = values[1] * dot(info[0], all[4]);
  if (values[3] < 0.0 || values[2] + values[3] > 1.0)
    return (-1);
  values[4] = values[1] * dot(all[1], all[4]);
  if (values[4] > EPSILON)
    return (check_z_buffer(rtc, info, dist));
  return (-1);
}
