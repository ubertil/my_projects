//
// ContainerGUI.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 04:00:38 2017 alexis papadimitriou
// Last update Sun Jan 22 03:31:02 2017 alexis papadimitriou
//

#ifndef CONTAINERGUI_HPP_
# define CONTAINERGUI_HPP_
# include "PixelBuffer.hpp"
# include "Font.hpp"
# include <string>

class			ContainerGUI
{
protected:
  Pos			_pos;
  uint16_t		_width;
  uint16_t		_height;
  std::string		_title;
  PixelBuffer		_buffer;
  Font			&_font;
  Color			_border;
  Color			_background;
  std::string		_info;
  Pos			_info_pos;

public:
  ContainerGUI(Pos pos, uint32_t width, uint32_t height,
	       std::string const &title, Font &font);

  virtual Pos		&getPos(void) {return (this->_pos);}

  virtual void		render(void);
  virtual void		setInfo(std::string const &info, Pos pos);
  virtual PixelBuffer	&getBuffer(void);
};

#endif /* !CONTAINERGUI_HPP_ */
