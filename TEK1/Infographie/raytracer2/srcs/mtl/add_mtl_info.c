/*
** add_mtl_info.c for add_mtl_info in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May  7 09:51:50 2016 louis-emile uberti-ares
** Last update Sun May 22 16:47:01 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

int		add_diffuse_reflec(t_materials *mat, char *str)
{
  char		**args;

  if (((args = my_str_to_wordtab(str, " ")) == NULL) || (args[1] == NULL) ||
      (args[2] == NULL) || (args[3] == NULL) || (args[4] != NULL))
    return (my_puterr(MTL_FORMAT_ERR));
  if ((my_getdouble(args[0]) < 0) ||
      (my_getdouble(args[1]) < 0) ||
      (my_getdouble(args[2]) < 0))
    {
      free_tab(args);
      return (my_puterr(MTL_COL_ERR));
    }
  mat->kd[0] = my_getdouble(args[1]);
  mat->kd[1] = my_getdouble(args[2]);
  mat->kd[2] = my_getdouble(args[3]);
  free_tab(args);
  return (0);
}

int		add_ambiant_reflec(t_materials *mat, char *str)
{
  char		**args;

  if (((args = my_str_to_wordtab(str, " ")) == NULL) || (args[1] == NULL) ||
      (args[2] == NULL) || (args[3] == NULL) || (args[4] != NULL))
    return (my_puterr(MTL_FORMAT_ERR));
  if ((my_getdouble(args[0]) < 0) ||
      (my_getdouble(args[1]) < 0) ||
      (my_getdouble(args[2]) < 0))
    {
      free_tab(args);
      return (my_puterr(MTL_COL_ERR));
    }
  mat->ka[0] = my_getdouble(args[1]);
  mat->ka[1] = my_getdouble(args[2]);
  mat->ka[2] = my_getdouble(args[3]);
  free_tab(args);
  return (0);
}

int		add_specular_reflec(t_materials *mat, char *str)
{
  char		**args;

  if (((args = my_str_to_wordtab(str, " ")) == NULL) || (args[1] == NULL) ||
      (args[2] == NULL) || (args[3] == NULL) || (args[4] != NULL))
    return (my_puterr(MTL_FORMAT_ERR));
  if ((my_getdouble(args[0]) < 0) ||
      (my_getdouble(args[1]) < 0) ||
      (my_getdouble(args[2]) < 0))
    {
      free_tab(args);
      return (my_puterr(MTL_COL_ERR));
    }
  mat->ks[0] = my_getdouble(args[3]);
  mat->ks[1] = my_getdouble(args[2]);
  mat->ks[2] = my_getdouble(args[1]);
  free_tab(args);
  return (0);
}

int		add_oppacity(t_materials *mat, char *str)
{
  char		**args;

  if (((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] != NULL))
    return (my_puterr(MTL_FORMAT_ERR));
  if ((mat->oppacity = my_getdouble(args[1])) < 0)
    {
      free_tab(args);
      return (my_puterr(MTL_COL_ERR));
    }
  free_tab(args);
  return (0);
}

int		add_specular_focus(t_materials *mat, char *str)
{
  char		**args;

  if (((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] != NULL))
    return (my_puterr(MTL_FORMAT_ERR));
  if ((mat->ns = my_getdouble(args[1])) < 0)
    {
      free_tab(args);
      return (my_puterr(MTL_COL_ERR));
    }
  free_tab(args);
  return (0);
}
