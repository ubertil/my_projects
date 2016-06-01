/*
** phong_light.c for phong_light in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May 20 22:30:05 2016 louis-emile uberti-ares
** Last update Sun May 22 17:14:23 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static void	specular_light(double col[4][3], t_materials *mat, char *str)
{
  t_materials	*tmp;

  tmp = mat;
  col[2][0] = 1.;
  col[2][1] = 1.;
  col[2][2] = 1.;
  col[3][0] = 128;
  if (str == NULL)
    return ;
  while (tmp)
    {
      if (my_strcmp(str, tmp->name) == 0)
	{
	  col[2][0] = tmp->ks[0];
	  col[2][1] = tmp->ks[1];
	  col[2][2] = tmp->ks[2];
	  col[3][0] = tmp->ns;
	  return ;
	}
      tmp = tmp->next;
    }
}

static void	light_mat(double col[4][3], t_materials *mat,
			  char *str)
{
  t_materials	*tmp;

  tmp = mat;
  col[0][0] = 1.;
  col[0][1] = 1.;
  col[0][2] = 1.;
  col[1][0] = 1.;
  col[1][1] = 1.;
  col[1][2] = 1.;
  if (str == NULL)
    return ;
  while (tmp)
    {
      if (my_strcmp(str, tmp->name) == 0)
	{
	  col[0][0] = tmp->ka[0];
	  col[0][1] = tmp->ka[1];
	  col[0][2] = tmp->ka[2];
	  col[1][0] = tmp->kd[0];
	  col[1][1] = tmp->kd[1];
	  col[1][2] = tmp->kd[2];
	  return ;
	}
      tmp = tmp->next;
    }
}

t_color		phong(t_rtc *rtc, double info[2][3], char *mat,
		      t_triangles *tmp)
{
  double	all[4][3];
  double	phong[4];
  double	norm[3][3];
  t_color	final;

  light_mat(all, rtc->mat, mat);
  specular_light(all, rtc->mat, mat);
  get_normal(norm, tmp->pos);
  final.argb[RED_CMP] = 255 * all[1][0];
  final.argb[GREEN_CMP] = 255 * all[1][1];
  final.argb[BLUE_CMP] = 255 * all[1][2];
  phong[0] = all[0][0];
  phong[1] = all[1][0];
  phong[2] = all[2][0];
  phong[3] = all[3][0];
  final.argb[RED_CMP] += 255 * assemble_all_colors(rtc, phong, info, norm[2]);
  phong[0] = all[0][1];
  phong[1] = all[1][1];
  phong[2] = all[2][1];
  final.argb[GREEN_CMP] += 255 * assemble_all_colors(rtc, phong, info, norm[2]);
  phong[0] = all[0][2];
  phong[1] = all[1][2];
  phong[2] = all[2][2];
  final.argb[BLUE_CMP] += 255 * assemble_all_colors(rtc, phong, info, norm[2]);
  return (final);
}
