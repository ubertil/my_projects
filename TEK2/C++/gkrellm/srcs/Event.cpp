//
// Event.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 00:22:25 2017 alexis papadimitriou
// Last update Sun Jan 22 05:59:17 2017 Lous-Emile Uberti-Ares
//

#include "Event.hpp"

void		Event::listen(bool &running)
{
  if (SDL_PollEvent(&this->_event))
    {
      switch (this->_event.type)
	{
	case (SDL_QUIT):
	  running = false;
	  break;
	case (SDL_KEYDOWN):
	  if (this->_event.key.keysym.sym == SDLK_ESCAPE)
	      running = false;
	  break;
	}
    }
}
