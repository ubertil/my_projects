/*
** get_ini_color.c for get_ini_color in /home/uberti_l/rendu/Infographie/gfx_raytracer1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 15 15:58:00 2016 louis-emile uberti-ares
** Last update Thu Feb 18 17:03:28 2016 louis-emile uberti-ares
*/

#include <lapin.h>
#include "include/raytracer.h"

t_color		get_ini_color(char *col)
{
  t_color	color;

  my_putstr(" of color ");
  my_putstr(col);
  my_putchar('\n');
  if (my_strcmp(col, "RED") == 0)
    color.full = RED;
  if (my_strcmp(col, "BLUE") == 0)
    color.full = BLUE;
  if (my_strcmp(col, "GREEN") == 0)
    color.full = GREEN;
  if (my_strcmp(col, "BLACK") == 0)
    color.full = BLACK;
  else if (my_strcmp(col, "WHITE") == 0)
    color.full = WHITE;
  return (color);
}
