/*
** print_help.c for print_help in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May  3 23:08:57 2016 louis-emile uberti-ares
** Last update Thu May 19 23:19:10 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

int		print_help(void)
{
  my_putstr("\033[01;37m");
  my_putstr("Welcome on the help page of the Raytracer 2 project made by ");
  my_putstr("Louis-Emile UBERTI, RAHIL Felix and GRELLARD Felix.\n\n");
  my_putstr("\t\033[01;32mUsage : ./raytracer2 .objfile [OPTIONS]\n\033[0m");
  my_putstr("\nOptions are :\n");
  my_putstr("\t--help\t\t: Display this page.\n");
  my_putstr("\t--width=K\t: Set the screen's width\n");
  my_putstr("\t--height=K\t: Set the screen's height\n");
  my_putstr("\t--fullscreen=K\t: Enable fullscreen mode(1 is YES, 0 is NO)\n");
  my_putstr("\nThis program was developed with the liblapin 1.7 by ");
  my_putstr("Jason BRILLANTE\n\n");
  my_putstr("EPITECH 2015-2016\n");
  return (-1);
}
