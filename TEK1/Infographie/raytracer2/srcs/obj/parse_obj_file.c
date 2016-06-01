/*
** parse_obj_file.c for obj_parse_file in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May  4 11:52:23 2016 louis-emile uberti-ares
** Last update Sun May 22 16:38:46 2016 louis-emile uberti-ares
*/

#include <fcntl.h>
#include <unistd.h>
#include "raytracer2.h"

static int	get_light_pos(t_rtc *rtc, const int fd)
{
  char		*str;
  char		**args;

  if (((str = get_shell_line(fd)) == NULL) ||
      ((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] == NULL) || (args[3] == NULL) ||
      (args[4] != NULL))
    return (-1);
  bunny_free(str);
  if (my_strcmp(args[0], "light_pos") != 0)
    return (-1);
  rtc->light_pos[0] = my_getdouble(args[1]);
  rtc->light_pos[1] = my_getdouble(args[2]);
  rtc->light_pos[2] = my_getdouble(args[3]);
  free_tab(args);
  return (0);
}

static int	get_first_info(t_rtc *rtc, const int fd)
{
  char		*str;
  char		**args;

  if (((str = get_shell_line(fd)) == NULL) ||
      ((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] == NULL) || (args[3] == NULL) ||
      (args[4] != NULL))
    return (-1);
  bunny_free(str);
  if (my_strcmp(args[0], "cam_pos") != 0)
    return (-1);
  rtc->cam_pos[0] = my_getdouble(args[1]);
  rtc->cam_pos[1] = my_getdouble(args[2]);
  rtc->cam_pos[2] = my_getdouble(args[3]);
  free_tab(args);
  return (get_light_pos(rtc, fd));
}

static int	init_obj_parse(t_options *tab)
{
  tab[0].str = "v ";
  tab[1].str = "vn ";
  tab[2].str = "f ";
  tab[3].str = "s ";
  tab[4].str = "mtllib ";
  tab[5].str = "vt ";
  tab[6].str = "usemtl ";
  tab[7].str = "g ";
  tab[8].str = NULL;
  tab[0].f = &add_peak;
  tab[1].f = &add_normvec;
  tab[2].f = &add_face;
  tab[3].f = &smoothing_group;
  tab[4].f = &parse_mtl_file;
  tab[5].f = &add_tex_coor;
  tab[6].f = &use_texture;
  tab[7].f = &unused;
  tab[8].f = NULL;
  return (0);
}

int		parse_obj_file(t_rtc *rtc)
{
  int		fd;
  int		idx;
  char		*str;
  t_options	obj[9];

  if ((fd = open(rtc->scene_file, O_RDONLY)) == -1)
    return (my_puterr(OPEN_ERR));
  init_obj_parse(obj);
  my_putstr("--> Getting .obj file...\n");
  if (get_first_info(rtc, fd) == -1)
    return (my_puterr(OBJ_NO_CAM));
  while ((str = get_shell_line(fd)) != NULL)
    {
      idx = 0;
      while (my_strncmp(str, obj[idx].str, my_strlen(obj[idx].str) - 1) != 0
	      && idx < 7)
	++idx;
      if (str[0] != '\0' && str[0] != '#' && obj[idx].f(rtc, str) == -1)
	return (-1);
      bunny_free(str);
    }
  my_putstr(".obj file acquiered !\nGenerating scene...\n");
  close(fd);
  rtc->faces = reverse_faces_info(rtc->faces);
  return (create_obj_tab(rtc));
}
