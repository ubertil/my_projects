/*
** core.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 11:24:59 2017 alexis papadimitriou
** Last update Sat Jul  1 18:59:50 2017 alexis papadimitriou
*/

#include "graphic/core.h"
#include "graphic/font.h"

t_core		*init_core()
{
  t_core	*new;

  if ((new = malloc(sizeof(t_core))) == NULL ||
      (new->screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, W_FLAGS)) ==
      NULL ||
      (new->event = malloc(sizeof(SDL_Event))) == NULL ||
      (new->client = malloc(sizeof(t_client))) == NULL ||
      (new->client->ip_address = strdup("127.0.0.1")) == NULL ||
      (new->player_list = init_plist()) == NULL ||
      (new->font = init_font()) == NULL ||
      (new->info = init_info()) == NULL ||
      (new->collision_buf = malloc(sizeof(int32_t) * WIDTH * HEIGHT)) == NULL)
    return (NULL);
  new->running = true;
  SDL_WM_SetCaption(W_TITLE, NULL);
  memset(new->collision_buf, -1, sizeof(int32_t) * WIDTH * HEIGHT);
  return (new);
}

void		free_core(t_core *core)
{
  SDL_FreeSurface(core->screen);
  free_info(core->info);
  free_font(core->font);
  free_client(core->client);
  free_map(core->map);
  free(core->event);
  free(core);
}

int32_t		get_object_id(int32_t *collision_buf, int32_t x, int32_t y)
{
  if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
    return (collision_buf[x + y * WIDTH]);
  return (-1);
}
