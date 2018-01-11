//
// Opengl.cpp for Opengl.cpp in /home/nicolas.trognot/rendu/C++/cpp_arcade/libs/sfml
//
// Made by Nicolas TROGNOT
// Login   <nicolas.trognot@epitech.net>
//
// Started on  Sat Mar 25 12:07:26 2017 Nicolas TROGNOT
// Last update Sun Apr  9 22:43:18 2017 Lous-Emile Uberti-Ares
//

#include "Opengl.hh"

arcade::Opengl::Opengl(int width, int height, const std::string &name)
{
  this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), name);
  this->_window->setVerticalSyncEnabled(true);
  this->_font.loadFromFile("ressources/common/ARCADE_N.TTF");
  this->_text.setFont(this->_font);
  this->_text.setCharacterSize(24);
#if SFML_VERSION_MAJOR >= 2 && SFML_VERSION_MINOR >= 4
  this->_text.setFillColor(sf::Color::White);
#else
  this->_text.setColor(sf::Color::White);
#endif
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

arcade::Opengl::~Opengl()
{
  this->_window->close();
}

void			arcade::Opengl::renderText(const std::string &text, const Vec2i &pos,
						   const int size,
						   const struct Color &color)
{
  this->_text.setString(text);
  this->_text.setCharacterSize(size);
  this->_text.setPosition(pos.x, pos.y);
#if SFML_VERSION_MAJOR >= 2 && SFML_VERSION_MINOR >= 4
  this->_text.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
#else
  this->_text.setColor(sf::Color(color.r, color.g, color.b, color.a));
#endif
  this->_window->draw(this->_text);
}

void			arcade::Opengl::loadTexture(const std::vector<std::string> &filepath)
{
  for (auto const &e : filepath)
    {
      if (this->_texture.find(e) == this->_texture.end())
	this->_texture[e].loadFromFile(e);
      if (this->_sprite.find(e) == this->_sprite.end())
	this->_sprite[e] = sf::Sprite(this->_texture.at(e));
    }
}

void			arcade::Opengl::deleteSpritesAndTextures()
{
  this->_texture.clear();
  this->_sprite.clear();
}

void			arcade::Opengl::renderTexture(const std::string &filepath,
						      const Vec2i &pos,
						      const Vec2i &dim,
						      const arcade::Event &rotation)
{
  if (this->_texture.find(filepath) == this->_texture.end())
    this->_texture[filepath].loadFromFile(filepath);
  if (this->_sprite.find(filepath) == this->_sprite.end())
    this->_sprite[filepath] = sf::Sprite(this->_texture.at(filepath));
  this->_sprite.at(filepath).setOrigin(this->_texture.at(filepath).getSize().x / 2,
				       this->_texture.at(filepath).getSize().y / 2);
  if (rotation == arcade::Event::UP)
    this->_sprite.at(filepath).setRotation(0);
  else if (rotation == arcade::Event::RIGHT)
    this->_sprite.at(filepath).setRotation(90);
  else if (rotation == arcade::Event::DOWN)
    this->_sprite.at(filepath).setRotation(180);
  else if (rotation == arcade::Event::LEFT)
    this->_sprite.at(filepath).setRotation(270);
  else
    this->_sprite.at(filepath).setRotation(0);
  this->_sprite.at(filepath).setScale(static_cast<float>(dim.x) /
				      static_cast<float>(this->_texture.at(filepath).getSize().x),
				      static_cast<float>(dim.y) /
				      static_cast<float>(this->_texture.at(filepath).getSize().y));
  this->_sprite.at(filepath).setPosition(pos.x + dim.x / 2, pos.y + dim.y / 2);
  this->_window->draw(this->_sprite.at(filepath));
}

void			arcade::Opengl::clearScreen() const
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void			arcade::Opengl::updateScreen() const
{
  this->_window->display();
}

arcade::Event		arcade::Opengl::getLastEvent() const
{
  sf::Event		event;

  while (this->_window->pollEvent(event))
    {
      switch (event.type)
	{
	case sf::Event::Closed:
	  return (arcade::Event::QUIT);
	case sf::Event::KeyPressed:
	  {
	    switch (event.key.code)
	      {
	      case sf::Keyboard::Escape:
		return (arcade::Event::QUIT);
	      case sf::Keyboard::Left:
		return (arcade::Event::LEFT);
	      case sf::Keyboard::Right:
		return (arcade::Event::RIGHT);
	      case sf::Keyboard::Up:
		return (arcade::Event::UP);
	      case sf::Keyboard::Down:
		return (arcade::Event::DOWN);
	      case sf::Keyboard::P:
		return (arcade::Event::PAUSE);
	      case sf::Keyboard::Return:
		return (arcade::Event::ENTER);
	      case sf::Keyboard::BackSpace:
		return (arcade::Event::BACK);
	      case sf::Keyboard::PageUp:
		return (arcade::Event::PLUS);
	      case sf::Keyboard::PageDown:
		return (arcade::Event::MINUS);
	      case sf::Keyboard::Num2:
		return (arcade::Event::PREV_LIB);
	      case sf::Keyboard::Num3:
		return (arcade::Event::NEXT_LIB);
	      case sf::Keyboard::Num4:
		return (arcade::Event::PREV_GAME);
	      case sf::Keyboard::Num5:
		return (arcade::Event::NEXT_GAME);
	      case sf::Keyboard::Num8:
		return (arcade::Event::RESTART);
	      case sf::Keyboard::Num9:
		return (arcade::Event::MENU);
	      default:
		break;
	      }
	  }
	default:
	  break;
	}
    }
  return (arcade::Event::NOTHING);
}

extern "C" arcade::IGraphics	*createGraphics(const Vec2i &dim, const std::string &name)
{
  return (new arcade::Opengl(dim.x, dim.y, name));
}
