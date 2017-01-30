//
// Starfield.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/merge
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sun Jan 22 04:29:55 2017 alexis papadimitriou
// Last update Sun Jan 22 06:30:54 2017 Lous-Emile Uberti-Ares
//

#include <cstdlib>
#include <ctime>
#include "Starfield.hpp"

Starfield::Starfield(int nb, int width, int height) :
  _stars(new Star[nb]), _width(width), _height(height), _nb(nb),
  _fov(-(width / -1.7119868018170374)), _angle(0)
{
  Color		colors[2];

  colors[0].full = WHITE;
  colors[1].full = BLACK;

  std::srand(std::time(0));
  for (int i = 0; i < nb; i++)
    {
      this->_stars[i].x = std::rand() % width * 2 - width / 2;
      this->_stars[i].y = std::rand() % height * 2 - height / 2;
      this->_stars[i].z = std::rand() % (500 + (int)this->_fov) - this->_fov;
      this->_stars[i].speed = std::rand() % 5 + 5;
      this->_stars[i].color = Utils::getColor(-this->_fov, 500,
					      this->_stars[i].z, colors);
    }
}

Starfield::~Starfield()
{
  delete this->_stars;
}

void		Starfield::renderAndUpdateStars(PixelBuffer &buffer)
{
  int		idx;
  Pos		pos;
  Color		c[2];

  c[0].full = WHITE;
  c[1].full = BLACK;
  idx = -1;
  while (++idx < this->_nb)
    {
      pos.x = (this->_fov * (this->_stars[idx].x - this->_width / 2)) / (this->_fov + this->_stars[idx].z) + this->_width / 2;
      pos.y = (this->_fov * (this->_stars[idx].y - this->_height / 2)) / (this->_fov + this->_stars[idx].z) + this->_height / 2;
      buffer.putPixel(pos.x, pos.y, this->_stars[idx].color);
      this->_stars[idx].z -= this->_stars[idx].speed;
      if (this->_stars[idx].z < -this->_fov)
	{
	  this->_stars[idx].z = 500;
	  this->_stars[idx].x = rand() % this->_width * 2 - this->_width / 2;
	  this->_stars[idx].y = rand() % this->_height * 2 - this->_height / 2;
	  this->_stars[idx].speed = rand() % 5 + 5;
	  this->_stars[idx].color.full = BLACK;
	}
      else
	this->_stars[idx].color = Utils::getColor(-this->_fov, 500, this->_stars[idx].z, c);
    }
  this->_angle += .015;
}
