/*
** from_ini_to_obj2.c for from_ini_to_obj2 in /home/uberti_l/rendu/Infographie/gfx_raytracer1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 15 13:50:33 2016 louis-emile uberti-ares
** Last update Thu Feb 18 17:28:18 2016 louis-emile uberti-ares
*/

#include <lapin.h>
#include <stdio.h>
#include "include/raytracer.h"

void		from_ini_to_cone(t_bunny_ini *ini, t_ray *ray, char *form)
{
  printf("\nForm = %s\n", form);
  ray->obj->cone.pos[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "x", 0));
  printf("Form = %s\n", form);
  ray->obj->cone.pos[1] = 1.0;
  printf("<<<%s>>>   >>>%s<<<<\n",form,  bunny_ini_get_field(ini, form, "y", 0));
  ray->obj->cone.pos[2] =
    my_getdouble(bunny_ini_get_field(ini, form, "z", 0));
  ray->obj->cone.angle =
    my_getdouble(bunny_ini_get_field(ini, form, "angle", 0));
  ray->obj->cone.color =
    get_ini_color((char *)bunny_ini_get_field(ini, form, "color", 0));
  ray->obj->cone.next = &ray->obj->cone;
}

void		from_ini_to_plane(t_bunny_ini *ini, t_ray *ray, char *form)
{
  ray->obj->plane.a[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "a", 0));
  ray->obj->plane.a[1] =
    my_getdouble(bunny_ini_get_field(ini, form, "b", 0));
  ray->obj->plane.a[2] =
    my_getdouble(bunny_ini_get_field(ini, form, "c", 0));
  ray->obj->plane.x[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "x", 0));
  ray->obj->plane.x[1] =
    my_getdouble(bunny_ini_get_field(ini, form, "y", 0));
  ray->obj->plane.x[2] =
    my_getdouble(bunny_ini_get_field(ini, form, "z", 0));
  ray->obj->plane.color =
    get_ini_color((char *)bunny_ini_get_field(ini, form, "color", 0));
  ray->obj->plane.next = &ray->obj->plane;
}
