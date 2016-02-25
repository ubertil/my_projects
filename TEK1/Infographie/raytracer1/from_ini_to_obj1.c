/*
** from_ini_to_obj1.c for from_ini_to_obj1 in /home/uberti_l/rendu/Infographie/gfx_raytracer1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 15 13:50:02 2016 louis-emile uberti-ares
** Last update Thu Feb 18 17:04:12 2016 louis-emile uberti-ares
*/

#include <lapin.h>
#include "include/raytracer.h"

void		from_ini_to_sphere(t_bunny_ini *ini, t_ray *ray, char *form)
{
  ray->obj->sphere.pos[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "x", 0));
  ray->obj->sphere.pos[1] =
    my_getdouble(bunny_ini_get_field(ini, form, "y", 0));
  ray->obj->sphere.pos[2] =
    my_getdouble(bunny_ini_get_field(ini, form, "z", 0));
  ray->obj->sphere.radius =
    my_getdouble(bunny_ini_get_field(ini, form, "radius", 0));
  ray->obj->sphere.color =
    get_ini_color((char *)bunny_ini_get_field(ini, form, "color", 0));
  ray->obj->sphere.next = &ray->obj->sphere;
}

void		from_ini_to_cube(t_bunny_ini *ini, t_ray *ray, char *form)
{
  ray->obj->cube.pos[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "x", 0));
  ray->obj->cube.pos[1] =
    my_getdouble(bunny_ini_get_field(ini, form, "y", 0));
  ray->obj->cube.pos[2] =
    my_getdouble(bunny_ini_get_field(ini, form, "z", 0));
  ray->obj->cube.color =
    get_ini_color((char *)bunny_ini_get_field(ini, form, "color", 0));
  ray->obj->cube.next = &ray->obj->cube;
}

void		from_ini_to_torus(t_bunny_ini *ini, t_ray *ray, char *form)
{
  ray->obj->torus.pos[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "x", 0));
  ray->obj->torus.pos[1] =
    my_getdouble(bunny_ini_get_field(ini, form, "y", 0));
  ray->obj->torus.pos[2] =
    my_getdouble(bunny_ini_get_field(ini, form, "z", 0));
  ray->obj->torus.s_radius =
    my_getdouble(bunny_ini_get_field(ini, form, "small_radius", 0));
  ray->obj->torus.l_radius =
    my_getdouble(bunny_ini_get_field(ini, form, "large_radius", 0));
  ray->obj->torus.color =
    get_ini_color((char *)bunny_ini_get_field(ini, form, "color", 0));
  ray->obj->torus.next = &ray->obj->torus;
}

void		from_ini_to_light(t_bunny_ini *ini, t_ray *ray, char *form)
{
  ray->obj->lux.pos[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "x", 0));
  ray->obj->lux.pos[1] =
    my_getdouble(bunny_ini_get_field(ini, form, "y", 0));
  ray->obj->lux.pos[2] =
    my_getdouble(bunny_ini_get_field(ini, form, "z", 0));
  ray->obj->lux.color =
    get_ini_color((char *)bunny_ini_get_field(ini, form, "color", 0));
  ray->obj->lux.next = &ray->obj->lux;
}

void		from_ini_to_cylinder(t_bunny_ini *ini, t_ray *ray, char *form)
{
  ray->obj->cylinder.pos[0] =
    my_getdouble(bunny_ini_get_field(ini, form, "x", 0));
  ray->obj->cylinder.pos[1] =
    my_getdouble(bunny_ini_get_field(ini, form, "y", 0));
  ray->obj->cylinder.r =
    my_getdouble(bunny_ini_get_field(ini, form, "r", 0));
  ray->obj->cylinder.color =
    get_ini_color((char *)bunny_ini_get_field(ini, form, "color", 0));
  ray->obj->cylinder.next = &ray->obj->cylinder;
}
