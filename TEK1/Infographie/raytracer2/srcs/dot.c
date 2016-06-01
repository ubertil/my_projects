/*
** dot.c for dot in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 17 13:28:26 2016 louis-emile uberti-ares
** Last update Tue May 17 15:35:04 2016 louis-emile uberti-ares
*/

double		dot(double *v, double *u)
{
  return ((v[0] * u[0]) + (v[1] * u[1]) + (v[2] * u[2]));
}
