/*
** graphics.h for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/graphics.h
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. mars 29 19:58:21 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  2 16:08:51 2017 Nicolas Wadel
*/

#pragma once
# include <memory>
# include <map>
# include <cstdlib>
# include <iostream>
# include <ctime>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include "shared.h"

# define WIN_NAME "== Lemin Visualizer =="
# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define REC_WIDTH (WIN_WIDTH / MAP_X)
# define REC_HEIGHT (WIN_HEIGHT / MAP_Y)

namespace lemin
{
  class Manager
  {
  public:
    Manager()
    {
      window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIN_WIDTH,
								WIN_HEIGHT), WIN_NAME);
      _font.loadFromFile("graphics/ressources/lemipc.ttf");
      _text.setFont(_font);
      _text.setCharacterSize(24);
      _text.setFillColor(sf::Color::White);
      _music.openFromFile("graphics/ressources/lemipc.ogg");
    };

    ~Manager() = default;

    void		startMusic()
    {
      _music.play();
      _music.setLoop(true);
    }

    void		stopMusic()
    {
      _music.stop();
    }

    int			getLast() const
    {
      return (lastPrinted);
    }

    bool		getQuit()
    {
      sf::Event		event;

      while (window->pollEvent(event))
	{
	  if ((event.type == sf::Event::Closed) ||
	      (event.type == sf::Event::KeyPressed &&
	       event.key.code == sf::Keyboard::Escape))
	    {
	      window->close();
	      return (true);
	    }
	}
      return (false);
    }

    void		renderText(const std::string &text, const int x, const int y,
				   const int size)
    {
      _text.setString(text);
      _text.setCharacterSize(size);
      _text.setPosition(x, y);
      window->draw(_text);
    }

    void		renderCenterText(const std::string &text, const int size)
    {
      _text.setString(text);
      _text.setCharacterSize(size);
      sf::FloatRect textRect = _text.getLocalBounds();
      _text.setOrigin(textRect.left + textRect.width / 2.0f,
		      textRect.top + textRect.height / 2.0f);
      _text.setPosition(sf::Vector2f(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f));
      window->draw(_text);
    }

    void			renderRect(const int x, const int y, const sf::Color color)
    {
      sf::RectangleShape	rectangle(sf::Vector2f(REC_WIDTH, REC_HEIGHT));

      rectangle.setFillColor(color);
      rectangle.setPosition(x, y);
      window->draw(rectangle);
    }

    void			clearScreen()
    {
      window->clear(sf::Color::Black);
    }

    void			updateScreen()
    {
      window->display();
    }

    void			fillColors(t_shared *shared)
    {
      _colors[-1] = sf::Color::White;
      std::srand(std::time(0));
      for (int y = 0; y < MAP_Y; y++)
	{
	  for (int x = 0; x < MAP_X; x++)
	    if (shared->map[y][x] != -1 &&
		_colors.find(shared->map[y][x]) == _colors.end())
	      _colors[shared->map[y][x]] = sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255);
	}
    }

    void			renderMap(t_shared *shared)
    {
      for (int y = 0; y < MAP_Y; y++)
	{
	  for (int x = 0; x < MAP_X; x++)
	    if (shared->map[y][x] != -1 &&
		_colors.find(shared->map[y][x]) != _colors.end())
	      {
		renderRect(x * REC_WIDTH, y * REC_HEIGHT,
			   _colors.at(shared->map[y][x]));
		lastPrinted = shared->map[y][x];
	      }
	}
    }

    std::unique_ptr<sf::RenderWindow>		window;
    sf::Music					_music;
  private:
    int						lastPrinted;
    std::map<int, sf::Color>			_colors;
    sf::Font					_font;
    sf::Text					_text;
  };
};
