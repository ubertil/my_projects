//
// Font.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 01:48:48 2017 alexis papadimitriou
// Last update Sun Jan 22 05:59:07 2017 Lous-Emile Uberti-Ares
//

#include <fstream>
#include "Font.hpp"

Font::Font(std::string const &filename)
{
  std::ifstream	font_file(filename.c_str());
  std::string	line;
  int		f_x;
  int		f_y = 0;

  if (!font_file.is_open())
    throw (std::ifstream::failure("Failed to open font file"));
  while (getline(font_file, line))
    {
      if (line.length() != 5)
	throw (std::ifstream::failure("Bad line in font file line: " + f_y));
      f_x = 0;
      for (char c : line)
	{
	  if (c == '#')
	    this->_data[f_y][f_x] = 1;
	  else
	    this->_data[f_y][f_x] = 0;
	  ++f_x;
	}
      f_y += 1;
    }
  if (f_y != 470)
    {
      throw (std::ifstream::failure("Missing line in font file. need 465. current: " + f_y));
    }
}

int		Font::render(PixelBuffer &buffer,
			     std::string const &string,
			     int x, int y, float scale_x, float scale_y)
{
  uint16_t	start_y[2];
  uint8_t	start_x;
  int		tmp_x = x;

  for (char c : string)
    {
      if (c < 33 && c != '\n' && c != ' ')
	continue ;
      start_y[0] = (c - 33) * 5;
      start_y[1] = -1;
      if (c == '\n')
	{
	  y += 6 * scale_y;
	  x = tmp_x;
	}
      else
	{
	  if (c != ' ')
	    while (++start_y[1] < 5 * scale_y)
	      {
		start_x = -1;
		while (++start_x < 5 * scale_x)
		  if (this->_data[start_y[0] + (uint32_t)(start_y[1] / scale_y)][(uint32_t)(start_x / scale_x)])
		    buffer.putPixel(x + start_x, y + start_y[1], WHITE);
	      }
	  x += 6 * scale_x;
	}
    }
  return ((y += 12 * scale_y));
}
