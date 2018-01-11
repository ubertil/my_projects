/*
** Snake.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Snake.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. mars 23 23:26:23 2017 Louis-Emile Uberti-Arès
// Last update Fri Apr  7 17:59:44 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <memory>
# include "Boa.hpp"
# include "MapSnake.hpp"
# include "IGame.hh"

namespace arcade
{
  class Snake : public IGame
  {
  public:
    Snake();
    ~Snake() = default;
    IMap&			getMap() const final;
    ICharacter&			getCharacter() const final;
    int				getScore() const final;
    bool			update(const int sec, arcade::Event event) final;
    std::vector<std::string>	loadSprites() const final;
    const std::string&		getSprite(arcade::BlockType type) const final;
  private:
    std::unique_ptr<MapSnake>				_map;
    std::unique_ptr<Boa>				_character;
    std::unordered_map<arcade::BlockType, std::string>	_sprites;
  };
};

extern "C" void			Play();
extern "C" arcade::IGame	*createGame();
