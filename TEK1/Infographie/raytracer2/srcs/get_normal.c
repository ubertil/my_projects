/*
** get_normal.c for get_normal in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May 21 12:34:45 2016 louis-emile uberti-ares
** Last update Sat May 21 23:10:12 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

void		get_normal(double norm[3][3], double **pos)
{
  vector(norm[0], pos[0], pos[1]);
  vector(norm[1], pos[0], pos[2]);
  cross(norm[2], norm[1], norm[0]);
}
