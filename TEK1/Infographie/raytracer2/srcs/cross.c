/*
** cross.c for cross in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 17 13:43:31 2016 louis-emile uberti-ares
** Last update Thu May 19 02:13:05 2016 louis-emile uberti-ares
*/

void		cross(double src[3], double *u, double *v)
{
  src[0] = (u[1] * v[2]) - (v[1] * u[2]);
  src[1] = (u[2] * v[0]) - (v[2] * u[0]);
  src[2] = (u[0] * v[1]) - (v[0] * u[1]);
}
