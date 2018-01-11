/*
** Fuckman.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Fuckman.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. mars 25 15:07:54 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:25:01 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include "ACharacter.hpp"

class Fuckman : public ACharacter
{
private:
  arcade::Event			_smooth;
  arcade::BlockType		_type;
  arcade::BlockType		_old;
  void				generateGhostRandomDirection();
public:
  Fuckman(const Vec2i &pos, uint16_t lives, AMap *map, arcade::BlockType type);
  ~Fuckman() = default;
  void				setPosition(int x, int y);
  int				move() override final;
  void				setDirection(arcade::Event dir) override final;
};
