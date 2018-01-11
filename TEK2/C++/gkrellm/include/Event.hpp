//
// Event.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 00:19:07 2017 alexis papadimitriou
// Last update Sat Jan 21 00:23:16 2017 alexis papadimitriou
//

#ifndef EVENT_HPP_
# define EVENT_HPP_
# include <SDL/SDL.h>

class		Event
{
private:
  SDL_Event	_event;

public:
  void		listen(bool &running);
};

#endif /* EVENT_HPP_ */
