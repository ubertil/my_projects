/*
** rooms_name.c for rooms_name in /home/grella_c/rendu/CPE_2015_Lemin
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Thu Apr  7 17:04:33 2016 come grellard
** Last update Thu May  5 15:06:21 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "lemin.h"

t_rooms		*reverse_rooms(t_rooms *root)
{
  t_rooms	*new_root;
  t_rooms	*next;

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

void		insert_values(int mode, char **tab,
			      t_lemin *lemin, t_rooms *rooms)
{
  rooms->pos[0] = my_hard_getnbr(tab[1]);
  rooms->pos[1] = my_hard_getnbr(tab[2]);
  rooms->has_been_visited = 0;
  rooms->nb = mode;
  lemin->nb_rooms += 1;
  free_args(tab);
}

t_rooms		*add_room(char *str, int mode, t_lemin *lemin, t_rooms **old)
{
  t_rooms	*rooms;
  char		**tab;

  if ((tab = my_str_to_wordtab(str)) == NULL
      || ((rooms = malloc(sizeof(t_rooms))) == NULL)
      || ((rooms->room_name = my_strdup(tab[0])) == NULL))
    return (NULL);
  insert_values(mode, tab, lemin, rooms);
  rooms->next = *old;
  return (rooms);
}

char	*recup_next_start_end(char *str, t_lemin *lemin, int mode)
{
  my_putstr(str);
  my_putstr("\n");
  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  else if (str[0] == '#')
    {
      lemin->err_after_start_end = 1;
      return (NULL);
    }
  (mode == 1) ? (lemin->started = 1) : (lemin->ended = 1);
  return (str);
}

int	put_room_in_list(t_lemin *lemin, char *str, int mode)
{
  int	ret;

  if (mode == 1 || mode == 2)
    if ((str = recup_next_start_end(str, lemin, mode)) == NULL)
      {
	if (lemin->err_after_start_end == 1)
	  return (1);
	else
	  my_puterr("Error while using malloc!\n");
      }
  if ((ret = check_room(str, lemin->rooms)) != 0)
    return (ret);
  if ((lemin->rooms = add_room(str, mode, lemin, &lemin->rooms))
      == NULL)
    {
      my_puterr("Error while using malloc!\n");
      return (84);
    }
  my_putstr(str);
  my_putstr("\n");
  return (0);
}
