//
// Menu.hpp for Move in /home/uberti_l/rendu/Prog_Elem/cpp_arcade
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Thu Apr  6 21:28:12 2017 Lous-Emile Uberti-Ares
// Last update Sun Apr  9 22:50:37 2017 Lous-Emile Uberti-Ares
//

#include "Menu.hh"

arcade::Menu::Menu(const Vec2i &dim, int &_FPS) :
  menuTexture("./ressources/common/menu.jpg"),
  menuInfo("./ressources/common/menuInfo.jpg"),
  menuBar("./ressources/common/menuBar.jpg"),
  name("DEFAULT"),
  screen(-1), selectedMain(0), selectedOption(0), selectedChar(0),
  FPS(_FPS), onSelector(false), dim(dim)
{
  this->main.insert(this->main.end(),
		    {RED, {80, 125}, {150, 140}, "TOP", "See highscores for every game"});
  this->main.insert(this->main.end(),
		    {WHITE, {80, 225}, {125, 240}, "SNAKE", "Play the authentic snake !"});
  this->main.insert(this->main.end(),
		    {WHITE, {80, 320}, {110, 335}, "PACMAN", "Play the famous Pacman !"});
  this->main.insert(this->main.end(),
		    {WHITE, {80, 420}, {98, 435}, "OPTIONS", "Settings and options"});
  this->main.insert(this->main.end(),
		    {WHITE, {80, 510}, {138, 530}, "HELP", "Learn more about us !"});
  this->main.insert(this->main.end(),
		    {WHITE, {80, 605}, {138, 625}, "QUIT", "Quit Arcade TRUB"});
  this->options.insert(this->options.end(),
		       {RED, {0, 0}, {CENTER_X(this->dim.x, 25, 23), 230},
				       "Frames Per Seconds (FPS)", ""});
  this->options.insert(this->options.end(),
		       {WHITE, {0, 0}, {120, 430}, "Name : ", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {120, 480}, "A", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {170, 480}, "B", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {220, 480}, "C", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {270, 480}, "D", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {320, 480}, "E", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {370, 480}, "F", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {420, 480}, "G", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {470, 480}, "H", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {520, 480}, "I", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {570, 480}, "J", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {620, 480}, "K", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {670, 480}, "L", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {120, 520}, "M", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {170, 520}, "N", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {220, 520}, "O", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {270, 520}, "P", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {320, 520}, "Q", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {370, 520}, "R", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {420, 520}, "S", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {470, 520}, "T", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {520, 520}, "U", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {570, 520}, "V", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {620, 520}, "W", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {660, 520}, "X", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {120, 570}, "Y", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {170, 570}, "Z", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {220, 570}, "0", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {270, 570}, "1", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {320, 570}, "2", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {370, 570}, "3", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {420, 570}, "4", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {470, 570}, "5", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {520, 570}, "6", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {570, 570}, "7", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {620, 570}, "8", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0}, {670, 570}, "9", ""});
  this->selector.insert(this->selector.end(), {WHITE, {0, 0},
	{CENTER_X(this->dim.x, 25, 6), 610}, "RETURN", ""});
}

void		arcade::Menu::moveUp()
{
  if (this->screen == -1 && this->selectedMain - 1 >= 0)
    {
      this->main.at(this->selectedMain).color = WHITE;
      this->selectedMain--;
      this->main.at(this->selectedMain).color = RED;
    }
  else if (this->screen == 3 && this->selectedOption - 1 >= 0)
    {
      if (this->onSelector && this->selectedChar - 12 >= 0)
	{
	  this->selector.at(this->selectedChar).color = WHITE;
	  this->selectedChar -= 12;
	  this->selector.at(this->selectedChar).color = BLUE;
	}
      else
	{
	  this->options.at(this->selectedOption).color = WHITE;
	  this->selectedOption--;
	  this->options.at(this->selectedOption).color = RED;
	  this->selector.at(this->selectedChar).color = WHITE;
	  this->selectedChar = 0;
	}
    }
  if (this->selectedOption == 1)
    this->onSelector = true;
  else
    {
      this->onSelector = false;
      this->selector.at(this->selectedChar).color = WHITE;
      this->selectedChar = 0;
    }
}

void		arcade::Menu::validateInput()
{
  if (this->onSelector)
    {
      if (this->selector.at(this->selectedChar).text.compare("RETURN") == 0)
	{
	  if (this->name.size() > 0)
	    this->name.pop_back();
	}
      else if (this->name.size() < 8)
	this->name += this->selector.at(this->selectedChar).text;
    }
}

void		arcade::Menu::moveDown()
{
  if (this->screen == -1 && this->selectedMain + 1 < 6)
    {
      this->main.at(selectedMain).color = WHITE;
      this->selectedMain++;
      this->main.at(selectedMain).color = RED;
    }
  else if (this->screen == 3 && this->selectedOption + 1 < 2)
    {
      this->options.at(selectedOption).color = WHITE;
      this->selectedOption++;
      this->options.at(selectedOption).color = RED;
    }
  else if (this->onSelector && this->selectedChar + 1 < 37)
    {
      this->selector.at(selectedChar).color = WHITE;
      if (this->selectedChar + 12 >= 37)
	this->selectedChar = 36;
      else
	this->selectedChar += 12;
      this->selector.at(selectedChar).color = BLUE;
    }
  if (this->selectedOption == 1)
    this->onSelector = true;
  else
    this->onSelector = false;
}

const std::string		&arcade::Menu::getName() const
{
  return (this->name);
}

void		arcade::Menu::moveLeft()
{
  if (this->screen == 3)
    {
      if (this->FPS > 5 && this->selectedOption == 0)
	this->FPS--;
      else if (this->onSelector && this->selectedChar - 1 >= 0)
	{
	  this->selector.at(this->selectedChar).color = WHITE;
	  this->selectedChar--;
	  this->selector.at(this->selectedChar).color = BLUE;
	}
    }
}

void		arcade::Menu::moveRight()
{
  if (this->screen == 3)
    {
      if (this->FPS < 30 && this->selectedOption == 0)
	this->FPS++;
      else if (this->onSelector && this->selectedChar + 1 < 37)
	{
	  this->selector.at(this->selectedChar).color = WHITE;
	  this->selectedChar++;
	  this->selector.at(this->selectedChar).color = BLUE;
	}
    }
}

void		arcade::Menu::setSelected(const int selected)
{
  if (selected == -1)
    {
      this->onSelector = false;
      this->selector.at(this->selectedChar).color = WHITE;
      this->options.at(this->selectedOption).color = WHITE;
      this->selectedOption = 0;
      this->options.at(this->selectedOption).color = RED;
      this->selectedChar = 0;
    }
  this->screen = selected;
}

int			arcade::Menu::getSelected() const
{
  return (this->selectedMain);
}

void			arcade::Menu::render(arcade::IGraphics *win,
					     const arcade::Highscore *scores) const
{
  win->clearScreen();
  win->renderTexture(this->menuTexture, {0, 0}, this->dim, arcade::Event::UP);
  switch (this->screen)
    {
    case (-1) :
      this->mainMenu(win);
      break;
    case (0) :
      this->topMenu(win, scores);
      break;
    case (1) :
    case (2) :
    case (5) :
      break;
    case (3) :
      this->optionsMenu(win);
      break;
    case (4) :
      this->helpMenu(win);
      break;
    default:
      break;
    }
  win->updateScreen();
}

void				arcade::Menu::mainMenu(IGraphics *win) const
{
  int				i;

  i = -1;
  while (++i <= 5)
    {
      win->renderTexture(this->menuInfo, this->main.at(i).box,
			 {235, 70}, arcade::Event::UP);
      win->renderText(this->main.at(i).text, this->main.at(i).pos,
		      30, this->main.at(i).color);
      if (i == this->selectedMain)
	this->infoBox(win, i);
    }
}

void				arcade::Menu::topMenu(IGraphics *win,
						      const Highscore *scores) const
{
  std::vector<std::string>	snake_score = scores->getHighscores("SNAKE", 3);
  std::vector<std::string>	pacman_score = scores->getHighscores("PACMAN", 3);
  Vec2i				pos(0, 280);

  win->renderTexture(this->menuInfo, {0, 122}, {this->dim.x, 570}, arcade::Event::UP);
  win->renderText("HIGHSCORES : TOP 3", {CENTER_X(this->dim.x, 35, 18), 130}, 35, WHITE);
  win->renderText("SNAKE", {CENTER_X(this->dim.x, 25, 5), 220}, 25, GREEN);
  for (auto const &e : snake_score)
    {
      win->renderText(e, {CENTER_X(this->dim.x, 20, static_cast<int>(e.size())), pos.y}, 20, WHITE);
      pos.y += 50;
    }
  pos.y = 500;
  win->renderText("PACMAN", {CENTER_X(this->dim.x, 25, 6), 440}, 25, YELLOW);
  for (auto const &e : pacman_score)
    {
      win->renderText(e, {CENTER_X(this->dim.x, 20, static_cast<int>(e.size())), pos.y}, 20, WHITE);
      pos.y += 50;
    }
  this->infoBox(win, 0);
}

void				arcade::Menu::optionsMenu(IGraphics *win) const
{
  std::string			frames(std::to_string(this->FPS));

  win->renderTexture(this->menuInfo, {0, 122}, {this->dim.x, 570}, arcade::Event::UP);
  win->renderText(this->options.at(0).text, this->options.at(0).pos, 25,
		  this->options.at(0).color);
  win->renderTexture(this->menuBar, {340, 280}, {this->FPS * 5, 20},
		     arcade::Event::UP);
  if (this->FPS >= 5 && this->FPS <= 20)
    win->renderText(frames, {CENTER_X(this->dim.x, 35, 2), 330}, 35, WHITE);
  else if (this->FPS > 20 && this->FPS <= 25)
    win->renderText(frames, {CENTER_X(this->dim.x, 35, 2), 330}, 35, YELLOW);
  else
    win->renderText(frames, {CENTER_X(this->dim.x, 35, 2), 330}, 35, RED);
  win->renderText(this->options.at(1).text, this->options.at(1).pos, 25,
		  this->options.at(1).color);
  win->renderText(this->name, {CENTER_X(this->dim.x, 25, 8), 430}, 25, WHITE);
  this->selectorMenu(win);
  this->infoBox(win, 3);
}

void				arcade::Menu::helpMenu(IGraphics *win) const
{
  win->renderTexture(this->menuInfo, {0, 122}, {this->dim.x, 570}, arcade::Event::UP);
  win->renderText("Arcade TRUB was built by a team of 2 developpers",
		  {CENTER_X(this->dim.x, 15, 48), 130}, 15, WHITE);
  win->renderText("Louis-Emile UBERTI-ARES", {CENTER_X(this->dim.x, 15, 23), 180},
		  15, WHITE);
  win->renderText("Nicolas TROGNOT", {CENTER_X(this->dim.x, 15, 15), 210}, 15, WHITE);
  win->renderText("This project comes bundled with :",
		  {CENTER_X(this->dim.x, 15, 33), 300}, 15, WHITE);
  win->renderText("- 2 Games : Pacman and Snake",
		  {CENTER_X(this->dim.x, 15, 28), 340}, 15, WHITE);
  win->renderText("- 3 Libs : OpenGL | LibCaca | SFML",
		  {CENTER_X(this->dim.x, 15, 34), 380}, 15, WHITE);
  win->renderText("ARCADE WILL NEVER DIE", {CENTER_X(this->dim.x, 35, 21), 530}, 35, RED);
  win->renderText("TRUB Corp Industry Lt.",
		  {CENTER_X(this->dim.x, 15, 22), 660}, 15, WHITE);
  this->infoBox(win, 4);
}

void				arcade::Menu::infoBox(IGraphics *win, const int i) const
{
  win->renderTexture(this->menuInfo, {0, this->dim.y - 50},
		     {this->dim.x, 80}, arcade::Event::UP);
  win->renderText(this->main.at(i).info, {20, this->dim.y - 30}, 15,
		  WHITE);
}

void				arcade::Menu::selectorMenu(IGraphics *win) const
{
  for (int i = 0; i < 37; i++)
    win->renderText(this->selector.at(i).text, this->selector.at(i).pos, 25,
		    this->selector.at(i).color);
}
