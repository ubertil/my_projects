/*
** handle_user_options.c for handle_user_options in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May  3 23:15:15 2016 louis-emile uberti-ares
** Last update Fri May 20 14:21:55 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

int		get_user_width(t_rtc *rtc, char *str)
{
  int		i;

  i = 0;
  while (str[i] != '=' && str[i] != '\0')
    ++i;
  if (str[i] == '\0')
    return (my_puterr("Error : Width needs a value. Aborting.\n"));
  ++i;
  if ((str[i] == '\0') ||
       (((rtc->width = getnbr_from(str, i)) == -1) ||
	((rtc->width > 1920) || (rtc->width < 0))))
    return (my_puterr("Error : Width value should be between 0 OR 1920.") &&
	    my_puterr(" Aborting.\n"));
  return (0);
}

int		get_user_height(t_rtc *rtc, char *str)
{
  int		i;

  i = 0;
  while (str[i] != '=' && str[i] != '\0')
    ++i;
  if (str[i] == '\0')
    return (my_puterr("Error : Height needs a value. Aborting.\n"));
  ++i;
  if ((str[i] == '\0') ||
      (((rtc->height = getnbr_from(str, i)) == -1) ||
       ((rtc->height > 1080) || (rtc->height < 0))))
    return (my_puterr("Error : Height value should be between 0 OR 1080.") &&
	    my_puterr(" Aborting.\n"));
  return (0);
}

int		get_user_fullscreen(t_rtc *rtc, char *str)
{
  int		i;

  i = 0;
  while (str[i] != '=' && str[i] != '\0')
    ++i;
  if (str[i] == '\0')
    return (my_puterr("Error : Fullscreen needs a value. Aborting.\n"));
  ++i;
  if ((str[i] == '\0') || (str[i] != '0' && str[i] != '1'))
    return (my_puterr("Error : Fullscreen value MUST BE 0 OR 1. Aborting.\n"));
  rtc->fullscreen = str[i] - 48;
  return (0);
}
