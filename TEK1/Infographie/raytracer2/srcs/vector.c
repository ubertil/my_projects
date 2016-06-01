/*
** vector.c for vector in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 17 20:46:09 2016 louis-emile uberti-ares
** Last update Thu May 19 02:10:21 2016 louis-emile uberti-ares
*/

void		vector(double vector[3], double *b, double *c)
{
  vector[0] = c[0] - b[0];
  vector[1] = c[1] - b[1];
  vector[2] = c[2] - b[2];
}
