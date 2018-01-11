/*
** font.c for font.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:14:18 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:14:21 2017 Nicolas TROGNOT
*/

#include "graphic/font.h"

static t_font	*fill_data(t_font *font, FILE *file)
{
  int		f_x;
  int		f_y;
  char		*buf;
  size_t	n;

  n = 64;
  buf = NULL;
  f_y = 0;
  while ((getline(&buf, &n, file)) > 0)
    {
      buf[strlen(buf) - 1] = '\0';
      if (strlen(buf) != 5)
	return (NULL);
      f_x = -1;
      while (++f_x < (int)strlen(buf))
	font->data[f_y][f_x] = (buf[f_x] == '#') ? (1) : (0);
      free(buf);
      buf = NULL;
      ++f_y;
    }
  return (font);
}

t_font		*init_font()
{
  t_font	*f;
  FILE		*file;

  if ((f = malloc(sizeof(t_font))) == NULL ||
      (file = fopen(PATH_TO_FONT, "r")) == NULL)
    return (NULL);
  f->scale_x = 3;
  f->scale_y = 3;
  f->color.full = RED;
  if (fill_data(f, file) != NULL)
    fclose(file);
  return (f);
}

void		free_font(t_font *font)
{
  free(font);
}
