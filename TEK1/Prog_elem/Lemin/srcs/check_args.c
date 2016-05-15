/*
** check_args.c for check_args in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr  7 14:12:47 2016 louis-emile uberti-ares
** Last update Mon Apr 25 18:16:37 2016 come grellard
*/

#include <stdlib.h>
#include "lemin.h"

static int	start_end_needed(t_lemin *lemin)
{
  if ((lemin->started == 0) || (lemin->ended == 0))
    return (1);
  else
    return (0);
}

static int	room_or_connect(t_lemin *lemin, char *str)
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
    return (create_matrix(lemin));
  else
    return (1);
}

static int	check_line(t_lemin *lemin, char *str)
{
  if (((my_strcmp(str, "##start") == 0) && (lemin->started == 1))
      || ((my_strcmp(str, "##end") == 0) && (lemin->ended == 1)))
    return (1);
  if (my_strcmp(str, "##start") == 0)
    return (put_room_in_list(lemin, str, 1));
  else if (my_strcmp(str, "##end") == 0)
    return (put_room_in_list(lemin, str, 2));
  else if (str[0] == '#')
    return (0);
  if (lemin->who != 2)
    lemin->who = room_or_connect(lemin, str);
  if (lemin->who == 84)
    return (84);
  if (lemin->who == 1)
    return (put_room_in_list(lemin, str, 0));
  else
    return (add_to_matrix(lemin, str));
}

int		check_args(t_lemin *lemin)
{
  char		*line;

  lemin->started = 0;
  lemin->ended = 0;
  if (get_nbr_ants(lemin) == 1)
    return (2);
  while ((line = get_next_line(0)) != NULL)
    {
      if (check_line(lemin, line))
	{
	  free(line);
	  return (start_end_needed(lemin));
	}
      free(line);
    }
  return (0);
}
