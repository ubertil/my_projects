/*
** create_matrix.c for create_matrix in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 14 14:10:08 2016 louis-emile uberti-ares
** Last update Wed Apr 20 13:57:54 2016 come grellard
*/

#include <stdlib.h>
#include "lemin.h"

static void	init_matrix(t_lemin *lemin)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y != lemin->nb_rooms)
    {
      x = 0;
      while (x != lemin->nb_rooms)
	{
	  lemin->matrix[y][x] = 0;
	  ++x;
	}
      y++;
    }
  lemin->got_matrix = 2;
}

static int	init_values(t_lemin *lemin)
{
  int		i;
  t_rooms	*tmp;

  i = 0;
  tmp = lemin->rooms;
  if ((lemin->matrix = malloc(sizeof(int *) * (lemin->nb_rooms))) == NULL)
    return (84);
  if ((lemin->names = malloc(sizeof(char *) * (lemin->nb_rooms + 1))) == NULL)
    return (84);
  while (tmp != NULL)
    {
      if ((lemin->matrix[i] = malloc(sizeof(int) * lemin->nb_rooms)) == NULL)
	return (84);
      if ((lemin->names[i] = my_strdup(tmp->room_name)) == NULL)
	return (84);
      ++i;
      tmp = tmp->next;
    }
  init_matrix(lemin);
  lemin->names[i] = NULL;
  return (0);
}

int	create_matrix(t_lemin *lemin)
{
  int	ret;

  lemin->rooms = reverse_rooms(lemin->rooms);
  ret = init_values(lemin);
  if (ret == 84)
    {
      my_puterr("Error while using malloc!\n");
      return (84);
    }
  return (2);
}

int	add_to_matrix(t_lemin *lemin, char *str)
{
  char	*s1;
  char	*s2;
  int	n1;
  int	n2;

  if (check_link(str) == 1)
    return (1);
  if (((s1 = get_first_room(str)) == NULL) ||
      ((s2 = get_second_room(str)) == NULL))
    return (84);
  n1 = find_room(lemin->rooms, s1);
  n2 = find_room(lemin->rooms, s2);
  if ((n1 == -1) || (n2 == -1))
    return (1);
  my_putstr(str);
  my_putstr("\n");
  lemin->matrix[n1][n2] = 1;
  lemin->matrix[n2][n1] = 1;
  return (free_two_rooms(s1, s2));
}
