/*
** mtl_parse.c for mtl_parse in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May  7 09:25:51 2016 louis-emile uberti-ares
** Last update Sun May 22 16:57:26 2016 louis-emile uberti-ares
*/

#include <fcntl.h>
#include <unistd.h>
#include "raytracer2.h"

static char	*copy_from_slash(t_rtc *rtc, char *str, char *file, int end)
{
  int		i;
  char		**args;

  i = -1;
  if (((args = my_str_to_wordtab(file, " ")) == NULL) ||
      (args[1] == NULL))
    return (NULL);
  while (++i < end)
    str[i] = rtc->scene_file[i];
  str[i] = '/';
  str[i + 1] = '\0';
  str = my_strcpy(str, args[1]);
  free_tab(args);
  return (str);
}


static char	*get_absolute_file_name(t_rtc *rtc, char *file)
{
  char		*str;
  int		i;
  int		slash;

  i = -1;
  slash = 0;
  while (rtc->scene_file[++i] != '\0')
    if (rtc->scene_file[i] == '/')
      slash = i;
  if ((slash != 0) &&
      ((str = bunny_malloc(my_strlen(file) + slash + 2)) == NULL))
    return (NULL);
  else if (slash == 0)
    return (file);
  else
    return (copy_from_slash(rtc, str, file, slash));
}

int		add_illum(t_materials *mat, char *str)
{
  char		**args;

  if (((args = my_str_to_wordtab(str, " ")) == NULL) ||
      (args[1] == NULL) || (args[2] != NULL))
    return (-1);
  if ((mat->illum = (int)my_getdouble(args[1])) < 0)
    {
      free_tab(args);
      return (my_puterr(".mtl: Error: Illum must be between 0 and 10. ") &&
	      my_puterr("Aborting.\n"));
    }
  free_tab(args);
  return (0);
}

int		parse_mtl_file(t_rtc *rtc, char *file)
{
  int		fd;
  char		*str;

  if (((str = get_absolute_file_name(rtc, file)) == NULL) ||
      ((fd = open(str, O_RDONLY)) == -1))
    return (my_puterr(OPEN_ERR));
  my_putstr("--> Found .mtl file.\n");
  while ((str = get_shell_line(fd)) != NULL)
    {
      if (my_strncmp(str, "newmtl", 5) == 0)
	if ((rtc->mat = add_new_material(&rtc->mat, str, fd)) == NULL)
	  return (-1);
      bunny_free(str);
    }
  my_putstr(".mtl file acquiered !\n");
  close(fd);
  return (0);
}
