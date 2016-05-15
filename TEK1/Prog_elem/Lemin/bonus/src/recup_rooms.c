/*
** rooms_name.c for rooms_name in /home/grella_c/rendu/CPE_2015_Lemin
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Thu Apr  7 17:04:33 2016 come grellard
** Last update Thu Apr 21 16:20:42 2016 come grellard
*/

#include <stdlib.h>
#include "visu.h"

void		insert_values(int mode, char **tab, t_pos *rooms)
{
  rooms->posxy.x = my_hard_getnbr(tab[1]);
  rooms->posxy.y = my_hard_getnbr(tab[2]);
  rooms->nb = mode;
  free_args(tab);
}

t_pos		*add_room(char *str, int mode, t_pos **old)
{
  t_pos		*rooms;
  char		**tab;

  if ((tab = my_str_to_wordtab(str)) == NULL)
    return (NULL);
  if (((rooms = malloc(sizeof(t_pos))) == NULL) ||
      ((rooms->room_name = my_strdup(tab[0])) == NULL))
    return (NULL);
  insert_values(mode, tab, rooms);
  rooms->next = *old;
  return (rooms);
}

char	*recup_next_start_end(char *str, t_visu *visu, int mode)
{
  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  else if (str[0] == '#')
    return (NULL);
  (mode == 1) ? (visu->started = 1) : (visu->ended = 1);
  return (str);
}

int	put_room_in_list(t_visu *visu, char *str, int mode)
{
  int	ret;

  if (mode == 1 || mode == 2)
    if ((str = recup_next_start_end(str, visu, mode)) == NULL)
      if (visu->err_after_start_end == 1)
	return (1);
  if ((ret = check_room(str, visu->rooms)) != 0)
    return (ret);
  if ((visu->rooms = add_room(str, mode, &visu->rooms))
      == NULL)
    return (84);
  return (0);
}
