//
// damdosh.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Fri Jan 20 23:14:42 2017 alexis papadimitriou
// Last update Sun Jan 22 05:25:07 2017 alexis papadimitriou
//

#ifndef DAMDOSH_HPP_
# define DAMDOSH_HPP_
# include "Window.hpp"
# include "Event.hpp"
# include "Font.hpp"
# include "ContainerGUI.hpp"
# include "AModule.hpp"
# include "Starfield.hpp"
# include <vector>

class				Damdosh
{
private:
  Window			_display;
  Event				_event;
  Font				_font;
  uint8_t			_ups;
  bool				_running;
  std::vector<ContainerGUI *>	_containers;
  Starfield			_starfield;

public:
  Damdosh(void);
  ~Damdosh(void) {};

  void				start(std::vector<AModule *> &modules);

  Font				&getFont(void) {return (this->_font);}
};

#endif /* DAMDOSH_HPP_ */
