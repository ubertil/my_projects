//
// IGame.hh for IGame in /home/uberti_l/rendu/Prog_Elem/cpp_arcade
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Thu Mar 16 15:44:59 2017 Lous-Emile Uberti-Ares
// Last update Sun Apr  9 17:55:53 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <vector>
# include <string>
# include "Vec.hpp"
# include "Event.hh"


# define CENTER_X(width, length, size) (width / 2 - size * (length / 2))
# define CENTER_Y(height, size) ((height / 2) - size)

# define WHITE {255, 255, 255, 255}
# define BLACK {255, 0, 0, 0}
# define RED {255, 255, 0, 0}
# define GREEN {255, 0, 255, 0}
# define BLUE {255, 0, 0, 255}
# define YELLOW {255, 255, 255, 0}

namespace arcade
{
  struct Color
  {
    unsigned char	a;
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
  };
  class IGraphics
  {
  public:
    virtual ~IGraphics() = default;
    virtual void		renderText(const std::string &text,
					   const Vec2i &pos,
					   const int size,
					   const struct Color &color) = 0;
    virtual void		loadTexture(const std::vector<std::string> &) = 0;
    virtual void		deleteSpritesAndTextures() = 0;
    virtual void		renderTexture(const std::string &filepath,
					      const Vec2i &pos,
					      const Vec2i &dim,
					      const arcade::Event &rotation) = 0;
    virtual void		clearScreen() const = 0;
    virtual void		updateScreen() const = 0;
    virtual arcade::Event	getLastEvent() const = 0;
  };
};
