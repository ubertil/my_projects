/*
** add_obj_info.c for add_obj_info in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May  4 14:28:49 2016 louis-emile uberti-ares
** Last update Fri May 20 15:09:40 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

int		add_peak(t_rtc *rtc, char *str)
{
  t_objinfo	*new;
  char		**args;

  ++rtc->nb_lines;
  if (((new = bunny_malloc(sizeof(t_objinfo))) == NULL) ||
      ((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] == NULL) || (args[3] == NULL) ||
      (args[4] != NULL))
    return (my_puterr(OBJ_FORMAT_ERR));
  new->pos[0] = my_getdouble(args[1]);
  new->pos[1] = my_getdouble(args[2]);
  new->pos[2] = my_getdouble(args[3]);
  new->next = rtc->peak;
  rtc->peak = new;
  free_tab(args);
  return (0);
}

int		add_normvec(t_rtc *rtc, char *str)
{
  t_objinfo	*new;
  char		**args;

  ++rtc->nb_lines;
  if (((new = bunny_malloc(sizeof(t_objinfo))) == NULL) ||
      ((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] == NULL) || (args[3] == NULL) ||
      (args[4] != NULL))
    return (my_puterr(OBJ_FORMAT_ERR));
  new->pos[0] = my_getdouble(args[1]);
  new->pos[1] = my_getdouble(args[2]);
  new->pos[2] = my_getdouble(args[3]);
  new->next = rtc->norm;
  rtc->norm = new;
  free_tab(args);
  return (0);
}

int		use_texture(t_rtc *rtc, char *str)
{
  char		**args;
  t_materials	*tmp;

  tmp = rtc->mat;
  args = NULL;
  if (((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] != NULL))
    return (my_puterr(OBJ_FORMAT_ERR));
  if ((my_strcmp(args[1], "(null)")) == 0)
    {
      free_tab(args);
      return (0);
    }
  while (tmp)
    {
      if ((my_strcmp(args[1], tmp->name) == 0) &&
	  ((rtc->curr_mat = my_strdup(tmp->name)) != NULL))
	{
	  free_tab(args);
	  return (0);
	}
      tmp = tmp->next;
    }
  free_tab(args);
  return (my_puterr("Error : Unknown material name used. Aborting.\n"));
}

int		add_tex_coor(t_rtc *rtc, char *str)
{
  t_objinfo	*new;
  char		**args;

  if (((new = bunny_malloc(sizeof(t_objinfo))) == NULL) ||
      ((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] == NULL) || (args[3] == NULL) ||
      (args[4] != NULL))
    return (my_puterr(OBJ_FORMAT_ERR));
  new->pos[0] = my_getdouble(args[1]);
  new->pos[1] = my_getdouble(args[2]);
  new->pos[2] = my_getdouble(args[3]);
  new->next = rtc->tex;
  rtc->tex = new;
  free_tab(args);
  return (0);
}

int		add_face(t_rtc *rtc, char *str)
{
  t_faces	*new;
  char		**args;

  if (((new = bunny_malloc(sizeof(t_faces))) == NULL) ||
      ((args = my_str_to_wordtab(str, " ")) == NULL))
    return (-1);
  if ((new = get_coordinates_face(new, args)) == NULL)
    {
      free_tab(args);
      return (my_puterr("Error : Invalid face format. Aborting\n"));
    }
  free_tab(args);
  if (rtc->curr_mat == NULL)
    new->mat = NULL;
  else if (rtc->curr_mat != NULL &&
	   ((new->mat = my_strdup(rtc->curr_mat)) == NULL))
    return (my_puterr(MALLOC_ERR));
  new->next = rtc->faces;
  rtc->faces = new;
  return (0);
}
