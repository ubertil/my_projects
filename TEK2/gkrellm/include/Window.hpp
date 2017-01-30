//
// window.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Fri Jan 20 23:01:30 2017 alexis papadimitriou
// Last update Sat Jan 21 00:15:51 2017 alexis papadimitriou
//

#ifndef WINDOW_HPP_
# define WINDOW_HPP_
# include "PixelBuffer.hpp"
# include <string>

class		Window : public PixelBuffer
{
private:
  uint16_t	_width;
  uint16_t	_height;
  std::string	_title;

public:
  Window(uint16_t width, uint16_t height, uint32_t flags,
	 std::string const &title);

  void		refresh(void);
};

#endif /* !WINDOW_HPP_ */
