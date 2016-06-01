/*
** parse_args.c for parse_args in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May  3 22:48:15 2016 louis-emile uberti-ares
** Last update Sun May 22 16:32:10 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static int	remind_options_to_user(t_rtc *rtc)
{
  if (rtc->height == 1080)
    my_putstr("Default height selected : 1080\n");
  else
    {
      my_putstr("Your selected height : ");
      my_put_nbr(rtc->height);
      my_putstr("\n");
    }
  if (rtc->width == 1920)
    my_putstr("Default width selected : 1920\n");
  else
    {
      my_putstr("Your selected width : ");
      my_put_nbr(rtc->width);
      my_putstr("\n");
    }
  (rtc->fullscreen == 1) ? (my_putstr("Fullscreen : YES\n")) :
    (my_putstr("Fullscreen : NO\n"));
  if (rtc->scene_file == NULL)
    return (my_puterr("Error : No scene file given. Aborting.\n"));
  else
    return (parse_obj_file(rtc));
}


int		get_obj_file(t_rtc *rtc, char *str)
{
  if ((quick_match(str, ".obj") == 0) && (rtc->scene_file != NULL))
    return (my_puterr("Error : Please enter only one .obj file at a time.")
	    && my_puterr(" Aborting.\n"));
  if (quick_match(str, ".obj") == 0)
    {
      if ((rtc->scene_file = my_strdup(str)) == NULL)
	return (my_puterr(MALLOC_ERR));
      return (0);
    }
  else
    return (my_puterr("Error : Unknown option or .obj file named '") &&
	    my_puterr(str) && my_puterr("'\nPlease use --help to view")
	    && my_puterr(" all available options.\n"));
}

static int	init_options(t_options *tab)
{
  tab[0].str = "--width=";
  tab[1].str = "--height=";
  tab[2].str = "--fullscreen=";
  tab[3].f = NULL;
  tab[0].f = &get_user_width;
  tab[1].f = &get_user_height;
  tab[2].f = &get_user_fullscreen;
  tab[3].f = &get_obj_file;
  return (0);
}

int		parse_args(t_rtc *rtc, int ac, char **av)
{
  t_options	tab[4];
  int		i;
  int		idx;

  i = 1;
  if (init_options(tab) == -1)
    return (-1);
  while (i < ac)
    {
      idx = 0;
      if (my_strcmp(av[i], "--help") == 0)
	return (print_help());
      else
	{
	  while (idx < 3 && my_strncmp(tab[idx].str, av[i],
				       my_strlen(tab[idx].str) - 1) != 0)
	    ++idx;
	  if ((tab[idx].f(rtc, av[i])) != 0)
	    return (-1);
	  ++i;
	}
    }
  return (remind_options_to_user(rtc));
}
