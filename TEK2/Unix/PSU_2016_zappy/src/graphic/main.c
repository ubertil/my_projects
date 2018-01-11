/*
** main.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 11:42:31 2017 alexis papadimitriou
** Last update Sun Jul  2 19:11:33 2017 Nicolas TROGNOT
*/

#include <time.h>
#include <unistd.h>
#include <SDL/SDL_image.h>
#include "graphic/core.h"
#include "graphic/event.h"
#include "graphic/drawing.h"
#include "graphic/client.h"
#include "graphic/font.h"
#include "graphic/gui.h"
#include "graphic/transaction.h"
#include "common/utils/errors.h"
#include "common/protocol.h"

static int	disp_usage(const char *prog_name)
{
  dprintf(1, "USAGE: %s port [ip_address]\n", prog_name);
  dprintf(1, "\tport\tis the port number\n");
  dprintf(1, "\tip_address is the ip of the machine, localhost by default\n");
  return (0);
}

static bool		graphic_loop(t_core *core)
{
  struct timeval	timeout;

  timeout.tv_sec = 0;
  timeout.tv_usec = 10000;
  if (init_transaction(core) == false)
    return (false);
  while (core->running)
    {
      if (manage_transaction(core, &timeout) == false)
	return (false);
      render_map(core->screen, core->map, 10, 10);
      set_floor_id(core->collision_buf, core->map, 10, 10);
      render_player(core->screen, core->player_list,
		    core->map->textures[GRASS_IDX]->w,
		    core->map->textures[GRASS_IDX]->h);
      set_player_id(core->collision_buf, core->player_list,
		    core->map->textures[GRASS_IDX]->w,
		    core->map->textures[GRASS_IDX]->h);
      manage_event(core);
      render_gui(core);
      SDL_Flip(core->screen);
      fill(core->screen, BLACK);
    }
  return (true);
}

int		main(const int ac, const char **av)
{
  t_core	*core;
  bool		ret;

  if (ac == 1 || ac > 3)
    return (disp_usage(av[0]));
  srand(time(0) * getpid());
  SDL_Init(INIT_FLAGS);
  IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
  TTF_Init();
  if ((core = init_core()) == NULL ||
      (init_client(core->client, atoi(av[1]), av[2])) == NULL)
    return (ERROR_CODE);
  ret = graphic_loop(core);
  if (ret)
    free_core(core);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
  return (0);
}
