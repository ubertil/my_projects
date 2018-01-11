//
// Menu.hpp for Move in /home/uberti_l/rendu/Prog_Elem/cpp_arcade
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Thu Apr  6 21:28:12 2017 Lous-Emile Uberti-Ares
// Last update Sun Apr  9 22:51:08 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <vector>
# include "Highscore.hpp"
# include "IGraphics.hh"

namespace arcade
{
  struct Item
  {
    struct Color	color;
    Vec2i		box;
    Vec2i		pos;
    std::string		text;
    std::string		info;
  };

  class Menu
  {
  public:
    Menu(const Vec2i &dim, int &_FPS);
    ~Menu() = default;
    void			moveUp();
    void			validateInput();
    void			moveDown();
    const std::string		&getName() const;
    void			moveLeft();
    void			moveRight();
    void			setSelected(const int selected);
    int				getSelected() const;
    void			render(arcade::IGraphics *win,
				       const arcade::Highscore *scores) const;
  private:
    void			mainMenu(IGraphics *win) const;
    void			topMenu(IGraphics *win,
					const arcade::Highscore *scores) const;
    void			optionsMenu(IGraphics *win) const;
    void			helpMenu(IGraphics *win) const;
    void			infoBox(IGraphics *win, const int i) const;
    void			selectorMenu(IGraphics *win) const;
    const std::string		menuTexture;
    const std::string		menuInfo;
    const std::string		menuBar;
    std::string			name;
    int				screen;
    int				selectedMain;
    int				selectedOption;
    int				selectedChar;
    int				&FPS;
    bool			onSelector;
    const Vec2i			dim;
    std::vector<Item>		main;
    std::vector<Item>		options;
    std::vector<Item>		selector;
  };
};
