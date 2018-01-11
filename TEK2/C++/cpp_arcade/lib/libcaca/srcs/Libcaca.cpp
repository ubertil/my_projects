//
// sfml.cpp for sfml.cpp in /home/nicolas.trognot/rendu/C++/cpp_arcade/libs/sfml
//
// Made by Nicolas TROGNOT
// Login   <nicolas.trognot@epitech.net>
//
// Started on  Sat Mar 25 12:07:26 2017 Nicolas TROGNOT
// Last update Fri Apr  7 16:22:53 2017 Lous-Emile Uberti-Ares
//

#include "Error.hpp"
#include "Libcaca.hh"

arcade::Libcaca::Libcaca(int width, int height, const std::string &name)
{
  this->_cv = caca_create_canvas(width / 10, height / 20);
  this->_dp = caca_create_display(this->_cv);
  if (!this->_dp)
    throw arcade::LibError("Error while loading Libcaca");
  this->_cv = caca_get_canvas(this->_dp);
  caca_set_display_title(this->_dp, name.c_str());
}

arcade::Libcaca::~Libcaca()
{
  caca_free_display(this->_dp);
}

void			arcade::Libcaca::renderText(const std::string &text,
						    const Vec2i &pos,
						    const int size,
						    const struct Color &color)
{
    caca_set_color_ansi(this->_cv, CACA_BLACK, CACA_WHITE);
    caca_put_str(this->_cv, pos.x / 10, pos.y / 20, text.c_str());
    (void)text;
    (void)pos;
    (void)size;
    (void)color;
}

void			arcade::Libcaca::deleteSpritesAndTextures()
{
  this->textures.clear();
}

void			arcade::Libcaca::loadTexture(const std::vector<std::string> &filepath)
{
  this->textures = filepath;
}

void			arcade::Libcaca::renderTexture(const std::string &filepath,
						       const Vec2i &pos,
						       const Vec2i &dim,
						       const arcade::Event &event)
{
  (void)dim;
  (void)event;
  (void)filepath;
  (void)pos;
}

void			arcade::Libcaca::clearScreen() const
{
  caca_clear_canvas(this->_cv);
}

void			arcade::Libcaca::updateScreen() const
{
  caca_refresh_display(this->_dp);
}

arcade::Event		arcade::Libcaca::getLastEvent() const
{
  caca_event_t		ev;
  int			ret;
  int			character;

  ret = caca_get_event(this->_dp, CACA_EVENT_ANY, &ev, 0);
  if (ret == 1)
    {
      if (caca_get_event_type(&ev) == CACA_EVENT_QUIT)
	return (arcade::Event::QUIT);
      if (caca_get_event_type(&ev) == CACA_EVENT_KEY_RELEASE)
	{
	  character = caca_get_event_key_ch(&ev);
	  switch (character)
	    {
	    case 27:
	      return (arcade::Event::QUIT);
	    case 8:
	      return (arcade::Event::BACK);
	    case 10:
	      return (arcade::Event::ENTER);
	    case 275:
	      return (arcade::Event::LEFT);
	    case 276:
	      return (arcade::Event::RIGHT);
	    case 273:
	      return (arcade::Event::UP);
	    case 274:
	      return (arcade::Event::DOWN);
	    case 112:
	      return (arcade::Event::PAUSE);
	    case 50:
	      return (arcade::Event::PREV_LIB);
	    case 51:
	      return (arcade::Event::NEXT_LIB);
	    case 52:
	      return (arcade::Event::PREV_GAME);
	    case 53:
	      return (arcade::Event::NEXT_GAME);
	    case 56:
	      return (arcade::Event::RESTART);
	    case 57:
	      return (arcade::Event::MENU);
	    default:
	      break;
	    }
	}
    }
  return (arcade::Event::NOTHING);
}

extern "C" arcade::IGraphics	*createGraphics(const Vec2i &dim, const std::string &name)
{
  return (new arcade::Libcaca(dim.x, dim.y, name));
}
