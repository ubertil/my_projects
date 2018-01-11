/*
** Boa.hpp for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Boa.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. mars 25 15:07:54 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:15:54 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include "ACharacter.hpp"

class Boa : public ACharacter
{
public:
  Boa(const Vec2i &pos, uint16_t lives, AMap *map) :
    ACharacter(pos, lives, map)
  {
    this->_pos.push_back({pos.x - 1, pos.y});
    this->_pos.push_back({pos.x - 2, pos.y});
    this->_pos.push_back({pos.x - 3, pos.y});
  };

  ~Boa() = default;

  int		move() override final
  {
    Vec2i	lastPos;
    Vec2i	firstPos;
    Vec2i	newPos;

    lastPos = this->_pos.back();
    firstPos = this->_pos.front();
    switch (this->_dir)
      {
      case (arcade::Event::UP) :
	if (this->_map->getBlockType({lastPos.x, lastPos.y - 1}) == arcade::BlockType::WALL ||
	    this->_map->getBlockType({lastPos.x, lastPos.y - 1}) == arcade::BlockType::SNAKE)
	  return (false);
	else
	  newPos.set(lastPos.x, lastPos.y - 1);
	break;
      case (arcade::Event::DOWN) :
	if (this->_map->getBlockType({lastPos.x, lastPos.y + 1}) == arcade::BlockType::WALL ||
	    this->_map->getBlockType({lastPos.x, lastPos.y + 1}) == arcade::BlockType::SNAKE)
	  return (false);
	else
	  newPos.set(lastPos.x, lastPos.y + 1);
	break;
      case (arcade::Event::RIGHT) :
	if (this->_map->getBlockType({lastPos.x + 1, lastPos.y}) == arcade::BlockType::WALL ||
	    this->_map->getBlockType({lastPos.x + 1, lastPos.y}) == arcade::BlockType::SNAKE)
	  return (false);
	else
	  newPos.set(lastPos.x + 1, lastPos.y);
	break;
      case (arcade::Event::LEFT) :
	if (this->_map->getBlockType({lastPos.x - 1, lastPos.y}) == arcade::BlockType::WALL ||
	    this->_map->getBlockType({lastPos.x - 1, lastPos.y}) == arcade::BlockType::SNAKE)
	  return (false);
	else
	  newPos.set(lastPos.x - 1, lastPos.y);
	break;
      default:
	return (true);
      }
    this->_pos.push_back({newPos.x, newPos.y});
    if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::POWERUP_1)
      {
	this->_map->placePowerUp();
	this->score += 1;
      }
    if (this->_map->getBlockType({newPos.x, newPos.y}) != arcade::BlockType::POWERUP_1)
      {
	this->_pos.pop_front();
	this->_map->setBlockType(firstPos, arcade::BlockType::EMPTY);
      }
    this->_map->setBlockType({newPos.x, newPos.y}, arcade::BlockType::SNAKE);
    return (true);
  }

  void		setDirection(arcade::Event dir) override final
  {
    switch (dir)
      {
      case (arcade::Event::UP) :
	if (this->_dir != arcade::Event::DOWN)
	  this->_dir = dir;
	break;
      case (arcade::Event::DOWN) :
	if (this->_dir != arcade::Event::UP)
	  this->_dir = dir;
	break;
      case (arcade::Event::LEFT) :
	if (this->_dir != arcade::Event::RIGHT)
	  this->_dir = dir;
	break;
      case (arcade::Event::RIGHT) :
	if (this->_dir != arcade::Event::LEFT)
	  this->_dir = dir;
	break;
      default:
	break;
      }
  }
};
