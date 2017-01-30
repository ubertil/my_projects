//
// Window.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Fri Jan 20 23:43:14 2017 alexis papadimitriou
// Last update Sun Jan 22 06:00:21 2017 Lous-Emile Uberti-Ares
//

#include "Window.hpp"

Window::Window(uint16_t width, uint16_t height, uint32_t flags,
	       std::string const &title)
{
  if ((this->_buffer = SDL_SetVideoMode(width, height, 0, flags)) == NULL)
    throw(std::bad_alloc());
  SDL_WM_SetCaption(title.c_str(), "rush");
  this->_title = title;
}

void		Window::refresh(void)
{
  this->scanLines();
  SDL_Flip(this->_buffer);
  this->fill(0xFF0F0F0F);
}
