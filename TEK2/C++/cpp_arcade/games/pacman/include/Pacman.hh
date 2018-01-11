/*
** Pacman.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Pacman.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. mars 23 23:26:23 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:19:01 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <memory>
# include "Fuckman.hh"
# include "MapPacman.hpp"
# include "IGame.hh"

namespace arcade
{
  class Pacman : public IGame
  {
  public:
    Pacman();
    ~Pacman() = default;
    IMap&			getMap() const final;
    ICharacter&			getCharacter() const final;
    int				getScore() const final;
    bool			update(const int sec, arcade::Event event) final;
    std::vector<std::string>	loadSprites() const final;
    const std::string&		getSprite(arcade::BlockType type) const final;
  private:
    std::unique_ptr<MapPacman>				_map;
    std::unique_ptr<Fuckman>				_character;
    std::unique_ptr<Fuckman>				_ghost_1;
    std::unique_ptr<Fuckman>				_ghost_2;
    std::unique_ptr<Fuckman>				_ghost_3;
    std::unique_ptr<Fuckman>				_ghost_4;
    std::unordered_map<arcade::BlockType, std::string>	_sprites;
    char						_godMode;
    bool						_checkCherry;
    char						getGodMode() const;
    void						setGodMode(const char v);
    bool						checkReturn(const int ret);
    void						placePPowerUp();
  };
};

extern "C" void			Play();
extern "C" arcade::IGame	*createGame();
