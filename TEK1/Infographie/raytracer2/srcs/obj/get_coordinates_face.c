/*
** get_coordinates_face.c for get_coordinates_face in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon May  9 15:59:52 2016 louis-emile uberti-ares
** Last update Fri May 20 15:13:44 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static int	array_size(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}

static int	find_format(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '/')
	++i;
      if (str[i + 1] != '\0' && str[i + 1] == '/')
	return (1);
      while (str[i] != ' ')
	{
	  if (str[i] == '/')
	    return (3);
	  ++i;
	}
      return (1);
    }
  return (1);
}

static int	fill_matching_format(t_faces *new, char **args, int i)
{
  if (new->type == 1 || new->type == 2)
    {
      new->pos[i][2] = -1;
      if (((new->pos[i][0] = (int)my_getdouble(args[0])) <= 0) ||
	  ((new->pos[i][1] = (int)my_getdouble(args[1])) <= 0))
	return (my_puterr(OBJ_WRONG_IDX));
    }
  else
    {
      if (((new->pos[i][0] = (int)my_getdouble(args[0])) <= 0) ||
	  ((new->pos[i][1] = (int)my_getdouble(args[1])) <= 0) ||
	  ((new->pos[i][2] = (int)my_getdouble(args[2])) <= 0))
	return (my_puterr(OBJ_WRONG_IDX));
    }
  return (0);
}

t_faces	*get_coordinates_face(t_faces *new, char **args)
{
  int	i;
  char	**num;

  if ((new->pos =
       bunny_malloc(sizeof(int *) * (array_size(args)))) == NULL)
    return (NULL);
  new->type = find_format(args[1]);
  new->nb = array_size(args) - 1;
  i = 0;
  while (args[++i] != NULL)
    {
      if (((num = my_str_to_wordtab(args[i], "/")) == NULL) ||
	  ((new->pos[i - 1] = bunny_malloc(sizeof(int) * 3)) == NULL))
	return (NULL);
      if (fill_matching_format(new, num, i - 1) == -1)
	return (NULL);
      free_tab(num);
    }
  if ((new->pos[i] = bunny_malloc(sizeof(int) * 3)) == NULL)
    return (NULL);
  new->pos[i][0] = -1;
  new->pos[i][1] = -1;
  new->pos[i][2] = -1;
  return (new);
}
