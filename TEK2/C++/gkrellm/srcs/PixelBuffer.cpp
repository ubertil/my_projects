//
// PixelBuffer.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Fri Jan 20 23:29:32 2017 alexis papadimitriou
// Last update Sun Jan 22 05:59:28 2017 Lous-Emile Uberti-Ares
//

#include <new>
#include "PixelBuffer.hpp"

PixelBuffer::PixelBuffer(void) :
  _buffer(NULL)
{
}

PixelBuffer::PixelBuffer(uint32_t width, uint32_t height)
{
  if ((this->_buffer = SDL_CreateRGBSurface(0, width, height, 32,
					    0x000000FF,
					    0x0000FF00,
					    0x00FF0000,
					    0xFF000000)) == NULL)
    throw(std::bad_alloc());
}

PixelBuffer::~PixelBuffer(void)
{
  SDL_FreeSurface(this->_buffer);
}

void		PixelBuffer::putPixel(int16_t x, int16_t y, Color color)
{
  if (x > -1 && y > -1 && x < this->_buffer->w && y < this->_buffer->h)
    ((uint32_t *)this->_buffer->pixels)[x + y * this->_buffer->w] = color.full;
}

void		PixelBuffer::putPixel(int16_t x, int16_t y, uint32_t color)
{
  if (x > -1 && y > -1 && x < this->_buffer->w && y < this->_buffer->h)
    ((uint32_t *)this->_buffer->pixels)[x + y * this->_buffer->w] = color;
}

void		PixelBuffer::putPixelAlpha(int16_t x, int16_t y, Color color)
{
  Color		get;
  Color		col;
  float		factor;

  if (x > -1 && x < this->_buffer->w && y > -1 && y < this->_buffer->h)
    {
      get = this->getPixel(x, y);
      factor = color.argb[A] / 255.;
      col.argb[R] = color.argb[R] * factor + get.argb[R] * (1 - factor);
      col.argb[G] = color.argb[G] * factor + get.argb[G] * (1 - factor);
      col.argb[B] = color.argb[B] * factor + get.argb[B] * (1 - factor);
      ((uint32_t *)this->_buffer->pixels)[x +y * this->_buffer->w] =
	col.full;
    }
}

Color	PixelBuffer::getPixel(int16_t x, int16_t y)
{
  Color	ret;

  ret.full = BLACK;
  if (x > -1 && y > -1 && x < this->_buffer->w && y < this->_buffer->h)
    ret.full = ((uint32_t *)this->_buffer->pixels)[x + y * this->_buffer->w];
  return (ret);
}

void		PixelBuffer::putLine(Pos p1, Pos p2, Color *colors)
{
  float		dir;
  Color		col;
  Pos		p;
  int		add;

  dir = (float)(p2.y - p1.y) / (p2.x - p1.x);
  if (dir <= 1 && dir >= -1)
    {
      p.x = p1.x;
      add = (p1.x > p2.x) ? (-1) : (1);
      while (p.x != p2.x)
	{
	  p.y = p1.y + dir * (p.x - p1.x);
	  col = Utils::getColor(p1.x, p2.x, p.x, colors);
	  this->putPixel(p.x, p.y, col);
	  p.x += add;
	}
    }
  else
    {
      dir = 1 / dir;
      p.y = p1.y;
      add = (p1.y > p2.y) ? (-1) : (1);
      while (p.y != p2.y)
	{
	  p.x = p1.x + dir * (p.y - p1.y);
	  col = Utils::getColor(p1.y, p2.y, p.y, colors);
	  this->putPixel(p.x, p.y, col);
	  p.y += add;
	}
    }
}

void		PixelBuffer::fill(Color color)
{
  uint32_t	*buff = (uint32_t *)this->_buffer->pixels;
  uint32_t	size = this->_buffer->w * this->_buffer->h;
  uint32_t	idx = -1;

  while (++idx < size)
    buff[idx] = color.full;
}

void		PixelBuffer::fill(uint32_t color)
{
  uint32_t	*buff = (uint32_t *)this->_buffer->pixels;
  uint32_t	size = this->_buffer->w * this->_buffer->h;
  uint32_t	idx = -1;

  while (++idx < size)
    buff[idx] = color;
}

void		PixelBuffer::blit(PixelBuffer &buffer, Pos &pos)
{
  Pos		p;

  p.y = pos.y;
  while (p.y < pos.y + buffer.getBuffer()->h)
    {
      p.x = pos.x;
      while (p.x < pos.x + buffer.getBuffer()->w)
	{
	  this->putPixel(p.x, p.y, buffer.getPixel(p.x - pos.x,
						   p.y - pos.y));
	  ++p.x;
	}
      ++p.y;
    }
}

void		PixelBuffer::drawRect(Pos pos, uint32_t width,
				      uint32_t height, Color color)
{
  Pos		p;

  p.y = pos.y;
  while (p.y < pos.y + height)
    {
      p.x = pos.x;
      while (p.x < pos.x + width)
	this->putPixel(p.x++, p.y, color);
      ++p.y;
    }
}

void		PixelBuffer::scanLines(void)
{
  Color		c;
  int		x;
  int		y = -1;

  c.full = 0x66000000;
  while (++y < this->_buffer->h)
    {
      x = -1;
      while (++x < this->_buffer->w)
	if (y % 2)
	  this->putPixelAlpha(x, y, c);
    }
}
