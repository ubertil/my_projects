/*
** main.c for main in /home/uberti_l/rendu/Infographie/skill_test/chromatic_2020
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Feb  5 15:14:51 2016 louis-emile uberti-ares
** Last update Mon Feb 15 21:41:42 2016 louis-emile uberti-ares
*/

#include <lapin.h>
#include "include/raytracer.h"

t_bunny_response	main_loop(void *_ray)
{
  t_ray			*ray;

  ray = _ray;
  bunny_blit(&ray->win->buffer, &ray->pix->clipable, NULL);
  bunny_display(ray->win);
  return (GO_ON);
}

int			init_my_struct(t_ray *ray)
{
  if ((ray->obj = bunny_malloc(sizeof(ray->obj))) == NULL)
    return (1);
  if ((ray->cam = bunny_malloc(sizeof(ray->cam))) == NULL)
    return (1);
  return (0);
}

int			main(int ac, char **av)
{
  t_ray			*ray;

  if (ac < 2)
    {
      my_putstr_err("Error : No .ini file.\nAborting...\n");
      return (0);
    }
  if ((ray = bunny_malloc(sizeof(t_ray))) == NULL)
    return (1);
  if ((init_my_struct(ray)) == 1)
    {
      my_putstr_err("Fatal error ! Malloc failed\n");
      return (1);
    }
  ini_loader(ac, av, ray);
  if ((ray->pix = bunny_new_pixelarray(ray->width, ray->height)) == NULL)
    return (1);
  ray->win = bunny_start(ray->width, ray->height, false,
			 "Raytracer 1 | uberti_l");
  bunny_set_loop_main_function(main_loop);
  bunny_loop(ray->win, 60, ray);
  bunny_delete_clipable(&ray->pix->clipable);
  bunny_stop(ray->win);
  bunny_free(ray);
  return (0);
}
