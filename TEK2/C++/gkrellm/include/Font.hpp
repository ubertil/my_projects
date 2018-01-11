//
// Font.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 01:42:16 2017 alexis papadimitriou
// Last update Sun Jan 22 02:31:39 2017 alexis papadimitriou
//

#ifndef FONT_HPP_
# define FONT_HPP_
# include <string>
# include "PixelBuffer.hpp"

class		Font
{
private:
  uint8_t	_data[470][5];

public:
  Font(std::string const &filename);

  int		render(PixelBuffer &buffer, std::string const &string,
		       int x , int y, float scale_x, float scale_y);
};

#endif /* !FONT_HPP_ */
