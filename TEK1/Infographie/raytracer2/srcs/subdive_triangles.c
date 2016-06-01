/*
** subdive_triangles.c for subdive_triangless in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 10 22:09:19 2016 louis-emile uberti-ares
** Last update Sun May 22 17:51:48 2016 Félix Grellard
*/

#include "raytracer2.h"

static double	**doesnt_exist(void)
{
  double	**dump;

  if (((dump = bunny_malloc(sizeof(double *) * 3)) == NULL)
      || ((dump[0] = bunny_malloc(sizeof(double) * 3)) == NULL)
      || ((dump[1] = bunny_malloc(sizeof(double) * 3)) == NULL)
      || ((dump[2] = bunny_malloc(sizeof(double) * 3)) == NULL))
    return (NULL);
  dump[0][0] = -1;
  dump[0][1] = -1;
  dump[0][2] = -1;
  dump[1][0] = -1;
  dump[1][1] = -1;
  dump[1][2] = -1;
  dump[2][0] = -1;
  dump[2][1] = -1;
  dump[2][2] = -1;
  return (dump);
}

static int	v_vn_vt_format(t_rtc *rtc, t_triangles *new, int **pos,
			       const int *idx)
{
  new->norm[0] = rtc->norm_tab[pos[idx[0]][1] - 1];
  new->norm[1] = rtc->norm_tab[pos[idx[1]][1] - 1];
  new->norm[2] = rtc->norm_tab[pos[idx[2]][1] - 1];
  new->tex[0] = rtc->norm_tab[pos[idx[0]][2] - 1];
  new->tex[1] = rtc->norm_tab[pos[idx[1]][2] - 1];
  new->tex[2] = rtc->norm_tab[pos[idx[2]][2] - 1];
  return (0);
}

static int	v_vt_format(t_rtc *rtc, t_triangles *new, int **pos,
			    const int *idx)
{
  new->tex[0] = rtc->norm_tab[pos[idx[0]][1] - 1];
  new->tex[1] = rtc->norm_tab[pos[idx[1]][1] - 1];
  new->tex[2] = rtc->norm_tab[pos[idx[2]][1] - 1];
  if ((new->norm = doesnt_exist()) == NULL)
    return (my_puterr(MALLOC_ERR));
  return (0);
}

static int	add_new_triangle(t_rtc *rtc, const int *idx, int **pos,
				 const char *mat)
{
  t_triangles	*new;

  if (((new = bunny_malloc(sizeof(t_triangles))) == NULL)
      || ((new->pos = bunny_malloc(sizeof(double *) * 3)) == NULL)
      || ((new->norm = bunny_malloc(sizeof(double *) * 3)) == NULL)
      || ((new->tex = bunny_malloc(sizeof(double *) * 3)) == NULL))
    return (-1);
  new->mat = my_strdup(mat);
  new->pos[0] = rtc->obj[pos[idx[0]][0] - 1];
  new->pos[1] = rtc->obj[pos[idx[1]][0] - 1];
  new->pos[2] = rtc->obj[pos[idx[2]][0] - 1];
  if (idx[3] == 2 && v_vt_format(rtc, new, pos, idx) == -1)
    return (-1);
  if (idx[3] == 3 && v_vn_vt_format(rtc, new, pos, idx) == -1)
    return (-1);
  if (idx[3] == 1)
    {
      new->tex = doesnt_exist();
      new->norm[0] = rtc->norm_tab[pos[idx[0]][1] - 1];
      new->norm[1] = rtc->norm_tab[pos[idx[1]][1] - 1];
      new->norm[2] = rtc->norm_tab[pos[idx[2]][1] - 1];
    }
  new->next = rtc->triangles;
  rtc->triangles = new;
  return (0);
}

int		get_all_triangles(t_rtc *rtc)
{
  t_faces	*tmp;
  int		idx[4];
  int		triangles;

  tmp = rtc->faces;
  idx[0] = 0;
  while (tmp)
    {
      idx[1] = 1;
      idx[2] = 2;
      (tmp->nb > 3) ? (triangles = tmp->nb - 2) : (triangles = 1);
      idx[3] = tmp->type;
      while (triangles > 0)
	{
	  if (add_new_triangle(rtc, idx, tmp->pos, tmp->mat) == -1)
	    return (-1);
	  ++idx[1];
	  ++idx[2];
	  --triangles;
	}
      tmp = tmp->next;
    }
  free_faces(rtc->faces);
  return (0);
}
