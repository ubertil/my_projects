//
// ContainerGUI.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 04:40:44 2017 alexis papadimitriou
// Last update Sun Jan 22 05:58:52 2017 Lous-Emile Uberti-Ares
//

#include "ContainerGUI.hpp"

ContainerGUI::ContainerGUI(Pos pos, uint32_t width, uint32_t height,
			   std::string const &title, Font &font) :
  _pos(pos), _width(width), _height(height), _title(title),
  _buffer(width, height), _font(font)
{
  this->_border.full = 0xFF888888;
  this->_background.full = 0xFF444444;
}

void		ContainerGUI::render(void)
{
  this->_buffer.fill(this->_border);
  this->_buffer.drawRect((Pos){2, 20}, this->_width - 4,
			 this->_height - 22, this->_background);
  this->_font.render(this->_buffer, this->_title, 2, 2, 3, 3);
  this->_font.render(this->_buffer, this->_info,
		     this->_info_pos.x + 4, this->_info_pos.y + 24, 2, 2);
}

void		ContainerGUI::setInfo(std::string const &info, Pos pos)
{
  this->_info = info;
  this->_info_pos = pos;
}

PixelBuffer	&ContainerGUI::getBuffer(void)
{
  return (this->_buffer);
}
