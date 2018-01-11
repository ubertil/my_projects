/*
** main.c.c for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/main.c.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. mars 29 19:26:07 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  2 15:58:20 2017 Nicolas Wadel
*/

#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "graphics.hpp"

static void		*get_info(const key_t key)
{
  int			shm_id;

  shm_id = shmget(key, sizeof(t_shared), SHM_R);
  if (shm_id == -1)
    return (nullptr);
  return (shmat(shm_id, NULL, SHM_R));
}

static const std::string	get_winner(const t_shared *shared, const int last)
{
  int				found;

  found = -1;
  for (int y = 0; y < MAP_Y; y++)
    {
      for (int x = 0; x < MAP_X; x++)
	{
	  if (shared->map[y][x] != -1)
	    {
	      if (found == -1)
		found = shared->map[y][x];
	      else if (found != -1 && shared->map[y][x] != found)
		return (std::string("Hugh, I had trouble seeking the winner"));
	    }
	}
    }
  return (std::string("Team ").append(std::to_string(last)).append(" wins ! Congratulations!"));;
}

static int		observe(key_t key)
{
  lemin::Manager	core;
  std::string		winner;
  t_shared		*shared;

  shared = nullptr;
  while ((shared = (t_shared *)get_info(key)) == nullptr)
    {
      if (core.getQuit() == true)
	return (0);
      core.clearScreen();
      core.renderCenterText("Waiting for players to connect", 20);
      core.updateScreen();
    }
  core.startMusic();
  while (core.window->isOpen())
    {
      core.fillColors(shared);
      core.clearScreen();
      if (core.getQuit() == true)
	return (0);
      if (shared->nb_connected > 0)
	core.renderMap(shared);
      else
	{
	  core.stopMusic();
	  core.clearScreen();
	  core.renderCenterText(get_winner(shared, core.getLast()), 20);
	  core.updateScreen();
	  shmctl(key, IPC_RMID, 0);
	  while (core.window->isOpen())
	    if (core.getQuit() == true)
	      return (0);
	}
      core.updateScreen();
    }
  return (0);
}

int			main(int ac, const char * const *av)
{
  key_t			key;

  if (ac < 2)
    {
      std::cout << GFX_USAGE << std::endl;
      return (1);
    }
  key = ftok(av[1], 0);
  if (key == (key_t)-1)
    {
      std::cerr << "Error : Invalid key" << std::endl;
      return (1);
    }
  std::cout << "Using shm key : " << static_cast<int>(key) << std::endl;
  return (observe(key));
}
