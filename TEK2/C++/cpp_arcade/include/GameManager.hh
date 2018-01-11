/*
** GameManager.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/GameManager.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. mars 18 21:27:23 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:46:47 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <chrono>
# include <memory>
# include <iostream>
# include <unordered_map>
# include "Menu.hh"
# include "Highscore.hpp"
# include "Timer.hpp"
# include "IGraphics.hh"
# include "LibLoader.hpp"
# include "IGame.hh"

namespace arcade
{
  class			GameManager
  {
  public:
    GameManager(const std::string &path);
    ~GameManager();
  private:
    void		loadGame();
    void		loadGraphics();
    void		swapGraphics(bool next);
    void		swapGame(bool next);
    void		playGame();
    void		handleEvent() const;
    void		pause();
    void		gameOver(const std::string &);
    bool		drawMap() const;
    void		displayHUD() const;
    void		mainMenu();
    int			timeDiff(int fps);

    bool		can_play;
    bool		let_play;
    bool		alive;
    bool		menu;
    int			current_game;
    int			current_graphics;
    arcade::Event	event;
    std::unique_ptr<arcade::Highscore>				highscore;
    std::unique_ptr<arcade::Timer>				time;
    std::unique_ptr<arcade::LibLoader<IGame> >			gameLoader;
    std::unique_ptr<arcade::LibLoader<IGraphics> >		gfxLoader;
    std::unique_ptr<arcade::Menu>				home;
    std::chrono::steady_clock::time_point			begin;
    std::unordered_map<arcade::Event, std::function<void()> >	actions;
    std::vector<std::string>					graphicspath;
    std::vector<std::string>					gamepath;
    IGraphics*							graphics;
    IGame*							game;
  };
}
