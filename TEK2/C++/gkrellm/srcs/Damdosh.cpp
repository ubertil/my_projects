//
// Damdosh.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Fri Jan 20 23:59:55 2017 alexis papadimitriou
// Last update Sun Jan 22 05:24:29 2017 alexis papadimitriou
//

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Damdosh.hpp"
#include "ContainerGUI.hpp"
#include "GraphContainerGUI.hpp"

Damdosh::Damdosh(void) :
  _display(1920, 1080, SDL_DOUBLEBUF, "Damdosh"), _font(".font.txt"),
  _starfield(5000, 1920, 1080)
{
  this->_ups = 60;
  this->_running = false;
}

void			Damdosh::start(std::vector<AModule *> &modules)
{
  uint32_t		next;
  uint32_t		now;
  uint8_t		ups_count = 0;


  this->_running = true;
  next = SDL_GetTicks() + this->_ups;
  while (this->_running)
    {
      this->_event.listen(this->_running);
      this->_starfield.renderAndUpdateStars(this->_display);
      for (AModule *m : modules)
	{
	  m->getContainer()->render();
	  this->_display.blit(m->getContainer()->getBuffer(),
			      m->getContainer()->getPos());
	  if (ups_count % 6 == 0)
	    {
	      m->refresh();
	      ups_count = 0;
	    }
	}
      this->_display.refresh();
      now = SDL_GetTicks();
      SDL_Delay((next <= now) ? (0) : (next - now));
      next += this->_ups;
      ++ups_count;
    }
}
