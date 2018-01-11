/*
** Character.hh.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Character.hh.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  ven. mars 24 11:51:40 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 16:09:09 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <list>
# include "ICharacter.hh"
# include "AMap.hpp"
# include "Protocol.hpp"
# include "Vec.hpp"

class ACharacter : public ICharacter
{
public:
  ACharacter(const Vec2i &pos, uint16_t lives, AMap *map)
  {
    this->_lives = lives;
    this->_map = map;
    this->_pos.push_back(pos);
    this->_dir = arcade::Event::NOTHING;
    this->score = 0;
  }

  virtual ~ACharacter() = default;

  uint16_t			isDead() const final
  {
    return (this->_lives);
  }

  virtual int			move() = 0;
  virtual void			setDirection(arcade::Event dir) = 0;

  int				getScore() const final
  {
    return (this->score);
  }

  std::list<Vec2i>		getPos() const
  {
    return (this->_pos);
  }

  arcade::Event			getLastDir() const
  {
    return (this->_dir);
  }
protected:
  int				score;
  AMap				*_map;
  uint16_t			_lives;
  std::list<Vec2i>		_pos;
  arcade::Event			_dir;
};
