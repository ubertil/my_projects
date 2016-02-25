/*
** ini_loader.c for ini_loader in /home/uberti_l/rendu/Infographie/gfx_raytracer1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 15 11:40:07 2016 louis-emile uberti-ares
** Last update Tue Feb 16 19:50:34 2016 louis-emile uberti-ares
*/

#include <lapin.h>
#include "include/raytracer.h"

static const t_scene	fill[] =
  {
    {"Sphere", &from_ini_to_sphere},
    {"Cube", &from_ini_to_cube},
    {"Torus", &from_ini_to_torus},
    {"Light", &from_ini_to_light},
    {"Cylinder", &from_ini_to_cylinder},
    {"Cone", &from_ini_to_cone},
    {"Plane", &from_ini_to_plane},
  };

void		get_camera(t_bunny_ini *ini, t_ray *ray)
{
  my_putstr("--> Camera detected\n");
  ray->cam->x = my_getnbr((char *)bunny_ini_get_field(ini, "data", "camera", 0));
  ray->cam->y = my_getnbr((char *)bunny_ini_get_field(ini, "data", "camera", 1));
  ray->cam->z = my_getnbr((char *)bunny_ini_get_field(ini, "data", "camera", 2));
}

char		*get_form(int nb_form)
{
  char		*str;

  if ((str = bunny_malloc(7)) == NULL)
    return (NULL);
  str[0] = '\0';
  str = my_strcpy(str, "forme");
  str[5] = (nb_form + 48);
  str[6] = '\0';
  return (str);
}

void		fill_my_object(t_bunny_ini *ini, t_ray *ray)
{
  int		nb_form;
  int		i;
  char		*form;

  ray->width = my_getnbr((char *)bunny_ini_get_field(ini, "data", "WIDTH", 0));
  ray->height = my_getnbr((char *)bunny_ini_get_field(ini, "data", "HEIGHT", 0));
  nb_form = my_getnbr((char *)bunny_ini_get_field(ini, "data", "nb_form", 0));
  i = 0;
  form = get_form(nb_form);
  while (nb_form != 1)
    {
      form[5] = (nb_form + 48);
      while (my_strcmp(fill[i].object,
		       (char *)bunny_ini_get_field(ini, form, "object", 0)) != 0)
	  i += 1;
      my_putstr("--> ");
      my_putstr(fill[i].object);
      my_putstr(" detected : Object n°");
      my_put_nbr(ray->ini_idx);
      fill[i].func(ini, ray, form);
      i = 0;
      ray->ini_idx += 1;
      nb_form -= 1;
    }
}

void		ini_loader(int ac, char **av, t_ray *ray)
{
  t_bunny_ini		*ini;
  int			i;

  i = 1;
  my_putstr("Getting scene(s) from the given ini file(s)...\n");
  ray->ini_idx = 1;
  while (i != ac)
    {
      if (((ini = bunny_load_ini(av[i])) == NULL) || (av[i][0] == '\0'))
	{
	  my_putstr_err("Error: ");
	  if (av[i][0] != '\0')
	    my_putstr_err(av[i]);
	  my_putstr_err(" is not an ini file. Going to the next one\n");
	  i += 1;
	}
      else
	{
	  get_camera(ini, ray);
	  fill_my_object(ini, ray);
	  bunny_delete_ini(ini);
	  i += 1;
	}
    }
  my_putstr("\n\nIni file successfully loaded\nLaunching raytracer 1...\n");
}
