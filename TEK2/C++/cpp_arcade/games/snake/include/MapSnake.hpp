/*
** MapSnake.hpp for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/MapSnake.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  lun. avr. 03 14:51:26 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:16:24 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include "AMap.hpp"

class MapSnake : public AMap
{
public:
  MapSnake(const Vec2i &dim) :
    AMap(dim)
  {
    this->generateMap();
  };

  ~MapSnake() = default;

  void		generateMap() noexcept override final
  {
    Vec2i	pos(-1, 0);

    while (++pos.x < this->_size.x)
      _map[pos] = arcade::BlockType::WALL;
    while (++pos.y < this->_size.y - 1)
      {
	pos.x = -1;
	while (++pos.x < this->_size.x)
	  _map[pos] = (pos.x == 0 || pos.x == this->_size.x - 1) ?
	    (arcade::BlockType::WALL) : (arcade::BlockType::EMPTY);
      }
    pos.x = -1;
    while (++pos.x < this->_size.x)
      _map[pos] = arcade::BlockType::WALL;
  }
};
