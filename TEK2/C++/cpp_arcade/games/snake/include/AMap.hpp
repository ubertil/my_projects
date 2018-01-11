/*
** Map.hpp for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Map.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  ven. mars 24 13:57:33 2017 Louis-Emile Uberti-Arès
// Last update Mon Apr  3 20:39:07 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <random>
# include <ctime>
# include <unordered_map>
# include "IMap.hh"
# include "Vec.hpp"
# include "Error.hpp"
# include "Protocol.hpp"

class AMap : public IMap
{
public:
  AMap(const Vec2i &size)
  {
    std::srand(std::time(0));
    this->_size.x = size.x;
    this->_size.y = size.y;
  }

  AMap(const AMap &cpy) :
    _size(cpy._size)
  {
  }

  ~AMap() = default;

  uint16_t		getWidth() const noexcept final
  {
    return (static_cast<uint16_t>(this->_size.x));
  }

  uint16_t		getHeight() const noexcept final
  {
    return (static_cast<uint16_t>(this->_size.y));
  }

  arcade::BlockType	getBlockType(const Vec2i &pos) const noexcept final
  {
    if (pos.x >= 0 && pos.x < this->_size.x && pos.y >= 0 && pos.y < this->_size.y)
      return (this->_map.at(pos));
    else
      return (arcade::BlockType::WALL);
  }

  void			setBlockType(const Vec2i &pos, arcade::BlockType type) final
  {
    if (pos.x > this->_size.x || pos.y > this->_size.y || pos.x < 0 || pos.y < 0)
      throw arcade::GameError("Block position exceeds map size");
    else
      this->_map.at(pos) = type;
  }

  void			placePowerUp() noexcept final
  {
    Vec2i		pos;

    pos.x = 0;
    pos.y = 0;
    while (this->getBlockType(pos) != arcade::BlockType::EMPTY && this->getBlockType(pos) != arcade::BlockType::COIN)
      {
	pos.x = std::rand() % this->_size.x;
	pos.y = std::rand() % this->_size.y;
      }
    this->setBlockType(pos, arcade::BlockType::POWERUP_1);
  }

    void		generateMap() noexcept = 0;
protected:
    Vec2i							_size;
    std::unordered_map<Vec2i, arcade::BlockType, HashInt>	_map;
};
