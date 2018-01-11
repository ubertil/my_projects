//
// Created by Nicolas on 23/03/17.
//

#pragma once
# include <vector>
# include <ctime>
# include "IMap.hh"
# include "ICharacter.hh"

namespace arcade
{
  class IGame
  {
  public:
    virtual ~IGame() = default;
    virtual IMap&			getMap() const = 0;
    virtual ICharacter&			getCharacter() const = 0;
    virtual int				getScore() const = 0;
    virtual bool			update(const int sec, arcade::Event lastevent) = 0;
    virtual std::vector<std::string>	loadSprites() const = 0;
    virtual const std::string&		getSprite(arcade::BlockType type) const = 0;
  };
};
