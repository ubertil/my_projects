/*
** event.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 12:03:38 2017 alexis papadimitriou
** Last update Tue Jun 27 12:03:38 2017 alexis papadimitriou
*/

#include "graphic/event.h"

void	manage_event(t_core *core)
{
  while (SDL_PollEvent(core->event))
    {
      if ((core->event->type == SDL_KEYDOWN &&
	   core->event->key.keysym.sym == SDLK_ESCAPE) ||
	  (core->event->type == SDL_QUIT))
	core->running = false;
      if (core->event->type == SDL_MOUSEBUTTONUP)
	handle_click(core, &core->event->motion);
    }
}
