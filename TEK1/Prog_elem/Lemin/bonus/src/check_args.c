/*
** check_args.c for check_args in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr  7 14:12:47 2016 louis-emile uberti-ares
** Last update Sun Apr 24 12:34:48 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include "visu.h"

t_pos		*reverse_rooms(t_pos *root)
{
  t_pos		*new_root;
  t_pos		*next;

  new_root = NULL;
  while (root)
    {
      next = root->next;
      root->next = new_root;
      new_root = root;
      root = next;
    }
  return (new_root);
}

static int	room_or_connect(char *str)
{
  int		link;
  int		i;

  link = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	link += 1;
      ++i;
    }
  if (link != 0)
    return (0);
  else
    return (1);
}

static int	check_line(t_visu *visu, char *str)
{
  if (((my_strcmp(str, "##start") == 0) && (visu->started == 1))
      || ((my_strcmp(str, "##end") == 0) && (visu->ended == 1)))
    return (-1);
  if (my_strcmp(str, "##start") == 0)
    return (put_room_in_list(visu, str, 1));
  else if (my_strcmp(str, "##end") == 0)
    return (put_room_in_list(visu, str, 2));
  else if (str[0] == '#')
    return (0);
  (visu->who != 2) ? (visu->who = room_or_connect(str)) : (0);
  if (visu->who == 84)
    return (84);
  if (visu->who == 1)
    return (put_room_in_list(visu, str, 0));
  else
    return (add_link(visu, str));
}

int		check_args(t_visu *visu)
{
  char		*line;

  visu->link = NULL;
  visu->rooms = NULL;
  visu->started = 0;
  visu->ended = 0;
  if (get_nbr_ants(visu) == 1)
    return (-1);
  while ((line = get_next_line(0)) != NULL)
    {
      if (line[0] == 'P')
	{
	  visu->mem = my_strdup(line);
	  free(line);
	  return (0);
	}
      else if (check_line(visu, line))
	{
	  free(line);
	  return (-1);
	}
      free(line);
    }
  return (0);
}
