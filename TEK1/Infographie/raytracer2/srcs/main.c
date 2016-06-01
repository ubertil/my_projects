/*
** main.c for main in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Mar 14 12:29:31 2016 louis-emile uberti-ares
** Last update Sun May 22 17:07:36 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static t_bunny_response	mainloop(void *_rtc)
{
  t_rtc			*rtc;

  rtc = _rtc;
  set_background(rtc->cam, BLACK);
  if (init_threads(rtc) == -1)
    return (EXIT_ON_ERROR);
  bunny_blit(&rtc->win->buffer, &rtc->cam->clipable, NULL);
  bunny_display(rtc->win);
  return (GO_ON);
}

static t_bunny_response	events(t_bunny_event_state state,
			       t_bunny_keysym key,
			       void *_rtc)
{
  t_rtc			*rtc;

  rtc = _rtc;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  move1(state, key, rtc);
  move2(state, key, rtc);
  return (GO_ON);
}

static int	init_values(t_rtc *rtc)
{
  rtc->height = 1080;
  rtc->width = 1920;
  rtc->fullscreen = 0;
  rtc->nb_lines = 0;
  rtc->tex = NULL;
  rtc->obj = NULL;
  rtc->curr_mat = NULL;
  rtc->scene_file = NULL;
  rtc->norm = NULL;
  rtc->peak = NULL;
  rtc->faces = NULL;
  rtc->mat = NULL;
  rtc->triangles = NULL;
  return (0);
}

int		main(int ac, char **av)
{
  t_rtc		*rtc;

  bunny_set_maximum_ram(2147483647);
  if (ac < 2)
    return (my_puterr("Usage : ./raytracer2 [SCENE] [OPTIONS]\nType ") &&
	    my_puterr("--help for more info about this program\n"));
  if ((rtc = bunny_malloc(sizeof(t_rtc))) == NULL)
    return (my_puterr("Error : Bunny malloc failed !\n"));
  if ((init_values(rtc) != 0) || (parse_args(rtc, ac, av) != 0) ||
      (!(rtc->win = bunny_start(rtc->width, rtc->height, rtc->fullscreen,
				"Raytracer 2 by UBGRRA"))) ||
      (!(rtc->cam = bunny_new_pixelarray(rtc->width, rtc->height))) ||
      (norm_tab(rtc) == -1))
    return (-1);
  free_norm(rtc);
  set_background(rtc->cam, BLACK);
  bunny_set_key_response(events);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(rtc->win, 60, rtc);
  bunny_delete_clipable(&rtc->cam->clipable);
  free_all(rtc);
  return (0);
}
