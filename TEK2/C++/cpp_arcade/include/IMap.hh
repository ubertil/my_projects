/*
** IMap.h for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/IMap.h
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  lun. avr. 03 13:09:27 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 16:11:33 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include "Protocol.hpp"
# include "Blocks.hh"
# include "Vec.hpp"

class IMap
{
public:
  virtual ~IMap() = default;
  virtual uint16_t		getWidth() const noexcept = 0;
  virtual uint16_t		getHeight() const noexcept = 0;
  virtual arcade::BlockType	getBlockType(const Vec2i &pos) const noexcept = 0;
  virtual void			placePowerUp() noexcept = 0;
  virtual void			setBlockType(const Vec2i &pos, arcade::BlockType type) = 0;
  virtual void			generateMap() noexcept = 0;
};
