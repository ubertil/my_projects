/*
** assemble_all_colors.c for assemble_all_colors in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May 21 16:34:48 2016 louis-emile uberti-ares
** Last update Sat May 21 23:10:35 2016 louis-emile uberti-ares
*/

#include <math.h>
#include "raytracer2.h"

double		assemble_all_colors(t_rtc *rtc, double *color,
				    double info[2][3], double norm[3])
{
  double	light_v[3];
  double	spec[3];
  double	light[2];
  double	ret;

  vector(light_v, rtc->light_pos, info[1]);
  normalize(light_v);
  spec[0] = light_v[0] - 2 * dot(light_v, norm) * norm[0];
  spec[1] = light_v[1] - 2 * dot(light_v, norm) * norm[1];
  spec[2] = light_v[2] - 2 * dot(light_v, norm) * norm[2];
  if ((light[0] = color[1] * dot(light_v, norm)) < 0.)
    {
      light[0] = 0.;
      light[1] = 0.;
    }
  else if ((light[1] = color[2] * pow(dot(norm, spec), color[3])) < 0)
    light[1] = 0.;
  ret = (color[0] + light[0] + light[1]);
  return ((ret > 1) ? (1.) : (ret));
}
