/*
** player.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 28 15:34:32 2017 alexis papadimitriou
** Last update Thu Jun 29 15:06:31 2017 alexis papadimitriou
*/

#include "graphic/player.h"

t_player		*init_player(int32_t x, int32_t y)
{
  t_player		*new;
  int			i;

  if ((new = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  new->pos.x = x;
  new->pos.y = y;
  new->next = NULL;
  i = -1;
  while (++i < NB_ITEM)
    new->inventory[i] = 0;
  return (new);
}

void			free_player(t_player *player)
{
  free(player->team);
  free(player);
}
