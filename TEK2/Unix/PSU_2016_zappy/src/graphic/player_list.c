/*
** player_list.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 28 15:37:43 2017 alexis papadimitriou
** Last update Fri Jun 30 12:13:06 2017 alexis papadimitriou
*/

#include <SDL/SDL_image.h>
#include "graphic/player.h"

t_plist		*init_plist()
{
  t_plist	*new;

  if ((new = malloc(sizeof(t_plist))) == NULL ||
      (new->player_texture[NORTH] = IMG_Load(PLAYER_UP_TEXT)) == NULL ||
      (new->player_texture[SOUTH] = IMG_Load(PLAYER_DOWN_TEXT)) == NULL ||
      (new->player_texture[WEST] = IMG_Load(PLAYER_LEFT_TEXT)) == NULL ||
      (new->player_texture[EAST] = IMG_Load(PLAYER_RIGHT_TEXT)) == NULL)
    return (NULL);
  new->head = NULL;
  new->team_name = NULL;
  return (new);
}

void		free_plist(t_plist *list)
{
  t_player	*next;
  t_player	*to_free;

  next = list->head;
  while (next)
    {
      to_free = next;
      next = next->next;
      free_player(to_free);
    }
  SDL_FreeSurface(list->player_texture[NORTH]);
  SDL_FreeSurface(list->player_texture[SOUTH]);
  SDL_FreeSurface(list->player_texture[WEST]);
  SDL_FreeSurface(list->player_texture[EAST]);
  free(list);
}

void		push(t_plist *list, t_player *player)
{
  if (!player)
    return ;
  player->next = list->head;
  list->head = player;
}

t_player	*get_from_id(t_plist *list, int32_t id)
{
  t_player	*current;

  current = list->head;
  while (current && current->id != id)
    current = current->next;
  return (current);
}

void		remove_player(t_plist *list, t_player *player)
{
  t_player	*current;
  t_player	*prev;

  if (!player)
    return ;
  current = list->head;
  prev = NULL;
  while (current && current != player)
    {
      prev = current;
      current = current->next;
    }
  if (!current)
    return ;
  if (prev)
    prev->next = current->next;
  else
    list->head = current->next;
  current->next = NULL;
}
