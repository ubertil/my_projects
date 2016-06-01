/*
** norm.c for norm in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 19 00:40:06 2016 louis-emile uberti-ares
** Last update Sat May 21 15:38:35 2016 louis-emile uberti-ares
*/

double	norm(double *vec)
{
  return ((vec[0] + vec[1] + vec[2]));
}

void		normalize(double *vec)
{
  double	norme;

  norme = norm(vec);
  vec[0] /= norme;
  vec[1] /= norme;
  vec[2] /= norme;
}
