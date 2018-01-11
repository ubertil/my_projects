/*
** ICharacter.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/ICharacter.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. mars 25 14:51:59 2017 Louis-Emile Uberti-Arès
// Last update Sat Apr  8 15:07:34 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <list>
# include "Event.hh"
# include "Vec.hpp"

class ICharacter
{
public:
  virtual ~ICharacter() = default;
  virtual int			getScore() const = 0;
  virtual uint16_t		isDead() const = 0;
  virtual int			move() = 0;
  virtual void			setDirection(arcade::Event dir) = 0;
  virtual std::list<Vec2i>	getPos() const = 0;
  virtual arcade::Event		getLastDir() const = 0;
};
