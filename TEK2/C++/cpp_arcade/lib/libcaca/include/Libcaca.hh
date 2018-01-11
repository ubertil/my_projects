//
// Created by Nicolas on 23/03/17.
//

#pragma once
# include <memory>
# include <vector>
# include <caca.h>
# include "Vec.hpp"
# include "Event.hh"
# include "IGraphics.hh"

namespace arcade
{
  class Libcaca : public IGraphics
  {
  public:
    Libcaca(int width, int height,
	    const std::string &name);
    ~Libcaca();
    void		renderText(const std::string &text, const Vec2i &pos,
				   const int size,
				   const struct Color &color) final;
    void		loadTexture(const std::vector<std::string> &);
    void		deleteSpritesAndTextures();
    void		renderTexture(const std::string &filepath,
				      const Vec2i &pos, const Vec2i &dim,
				      const arcade::Event &) final;
    void		updateScreen() const final;
    void		clearScreen() const final;
    arcade::Event	getLastEvent() const final;
  public:
    std::vector<std::string>	textures;
    caca_canvas_t		*_cv;
    caca_display_t		*_dp;
    caca_event_t		*_ev;
  };
};

extern "C" arcade::IGraphics	*createGraphics(const Vec2i &dim,
						const std::string &name);
