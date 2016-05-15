/*
** get_ant_positions.c for get_ant_positions in /home/grella_c/rendu/CPE_2015_Lemin/bonus
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Sat Apr 23 16:48:36 2016 come grellard
** Last update Sat Apr 23 19:43:15 2016 come grellard
*/

#include <stdlib.h>
#include "visu.h"

char	*get_ant_dest(char *move)
{
  int	i;
  int	j;
  char	*dest;

  i = 0;
  j = 0;
  while (move[i] != '-')
    i += 1;
  i += 1;
  while (move[i++] != '\0')
    j += 1;
  if ((dest = malloc(j + 1)) == NULL)
    return (NULL);
  i -= j + 1;
  j = 0;
  while (move[i] != '\0')
    dest[j++] = move[i++];
  dest[j] = '\0';
  return (dest);
}

int			get_ant_positions(t_visu *visu, char *move)
{
  t_bunny_position	pos[2];
  int			num_ant;
  char			*name;

  if ((name = get_ant_dest(move)) == NULL)
    return (-1);
  num_ant = my_getnbr(move);
  visu->ants[num_ant - 1].dest = get_first_position(visu, name);
  pos[0] = visu->ants[num_ant - 1].current;
  pos[1] = visu->ants[num_ant - 1].dest;
  if (tekant(visu, pos, num_ant - 1) == -1)
    return (-1);
  visu->ants[num_ant - 1].current = visu->ants[num_ant - 1].dest;
  return (0);
}
