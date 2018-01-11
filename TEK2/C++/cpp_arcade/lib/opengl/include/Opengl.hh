//
// Created by Nicolas on 23/03/17.
//

#pragma once
# include <memory>
# include <unordered_map>
# include <SFML/Graphics.hpp>
# include <SFML/OpenGL.hpp>
# include "Vec.hpp"
# include "Event.hh"
# include "IGraphics.hh"

namespace arcade
{
  class Opengl : public IGraphics
  {
  public:
    Opengl(int width, int height,
	   const std::string &name);
    ~Opengl();
    void		renderText(const std::string &text, const Vec2i &pos,
				   const int size,
				   const struct Color &color) final;
    void		deleteSpritesAndTextures();
    void		loadTexture(const std::vector<std::string> &);
    void		renderTexture(const std::string &filepath,
				      const Vec2i &pos,
				      const Vec2i &dim,
				      const arcade::Event &rotation) final;
    void		updateScreen() const final;
    void		clearScreen() const final;
    arcade::Event	getLastEvent() const final;
  private:
    std::unique_ptr<sf::RenderWindow>		_window;
    sf::Font					_font;
    sf::Text					_text;
    std::unordered_map<std::string, sf::Texture>	_texture;
    std::unordered_map<std::string, sf::Sprite>		_sprite;
  };
};

extern "C" arcade::IGraphics	*createGraphics(const Vec2i &dim,
						const std::string &name);
