//
// pixelBuffer.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Fri Jan 20 23:04:13 2017 alexis papadimitriou
// Last update Sat Jan 21 10:17:10 2017 alexis papadimitriou
//

#ifndef PIXELBUFFER_HPP_
# define PIXELBUFFER_HPP_
# include <SDL/SDL.h>
# include "Utils.hpp"

class			PixelBuffer
{
protected:
  SDL_Surface		*_buffer;

public:
  PixelBuffer(void);
  PixelBuffer(uint32_t width, uint32_t height);
  virtual ~PixelBuffer(void);

  virtual SDL_Surface	*getBuffer(void)	const {return (this->_buffer);}

  virtual void		putPixel(int16_t x, int16_t y, Color color);
  virtual void		putPixel(int16_t x, int16_t y, uint32_t color);
  virtual void		putPixelAlpha(int16_t x, int16_t y, Color color);
  virtual Color		getPixel(int16_t x, int16_t y);
  virtual void		putLine(Pos p1, Pos p2, Color *colors);
  virtual void		fill(Color color);
  virtual void		fill(uint32_t color);
  virtual void		blit(PixelBuffer &buffer, Pos &pos);
  virtual void		drawRect(Pos pos, uint32_t width, uint32_t height,
				 Color color);
  virtual void		scanLines(void);
};

#endif /* !PIXELBUFFER_HPP_ */
