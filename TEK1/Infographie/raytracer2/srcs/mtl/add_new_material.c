/*
** add_new_material.c for add_new_material in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May  7 15:52:04 2016 louis-emile uberti-ares
** Last update Sun May 22 17:00:58 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static void	init_mtl_options(t_mtloptions *tab)
{
  tab[0].str = "Kd";
  tab[1].str = "Ka";
  tab[2].str = "Ks";
  tab[3].str = "d";
  tab[4].str = "Ns";
  tab[5].str = "illum";
  tab[6].str = NULL;
  tab[0].f = &add_diffuse_reflec;
  tab[1].f = &add_ambiant_reflec;
  tab[2].f = &add_specular_reflec;
  tab[3].f = &add_oppacity;
  tab[4].f = &add_specular_focus;
  tab[5].f = &add_illum;
  tab[6].f = NULL;
}

t_materials		*add_new_material(t_materials **old, char *name, int fd)
{
  t_materials		*mat;
  t_mtloptions		tab[7];
  char			*str;
  char			**args;
  int			idx;

  if (((mat = bunny_malloc(sizeof(t_materials))) == NULL) ||
      ((args = my_str_to_wordtab(name, " ")) == NULL) || (args[1] == NULL) ||
      (args[2] != NULL) || ((mat->name = my_strdup(args[1])) == NULL))
    return (NULL);
  free_tab(args);
  init_mtl_options(tab);
  while (((str = get_shell_line(fd)) != NULL) && (str[0] != '\0') &&
	 (str[0] != '#') && my_strncmp(str, "newmtl ", 5) != 0)
    {
      idx = 0;
      while ((my_strncmp(tab[idx].str, str, my_strlen(tab[idx].str) - 1) != 0)
	     &&	idx < 5)
	++idx;
      if (tab[idx].f(mat, str) == -1)
	return (NULL);
      bunny_free(str);
    }
  mat->next = *old;
  return (mat);
}
