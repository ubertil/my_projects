/*
** GameManager.cpp for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/GameManager.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. mars 18 21:55:46 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:46:09 2017 Lous-Emile Uberti-Ares
*/

#include <algorithm>
#include <cmath>
#include "GameManager.hh"

static const Vec2i	WIN = {800, 800};
static int		FPS = 10;

arcade::GameManager::GameManager(const std::string &path)
{
  bool		found = false;
  int		idx = 0;

  this->time = std::make_unique<Timer>();
  this->begin = std::chrono::steady_clock::now();
  this->graphicspath.insert(this->graphicspath.end(), "./lib/lib_arcade_opengl.so");
  this->graphicspath.insert(this->graphicspath.end(), "./lib/lib_arcade_sfml.so");
  this->graphicspath.insert(this->graphicspath.end(), "./lib/lib_arcade_libcaca.so");
  this->gamepath.insert(this->gamepath.end(), "./games/lib_arcade_pacman.so");
  this->gamepath.insert(this->gamepath.end(), "./games/lib_arcade_snake.so");
  this->current_game = 0;
  this->current_graphics = 0;
  this->game = nullptr;
  this->graphics = nullptr;
  this->menu = true;
  this->can_play = true;
  this->actions[arcade::Event::NOTHING] = [this]() { return ; };
  this->actions[arcade::Event::LEFT] = [this]() { if (this->let_play && this->alive && this->game != nullptr && !this->menu) this->alive = this->game->update(this->time->getTime(), this->event); };
  this->actions[arcade::Event::RIGHT] = [this]() { if (this->let_play && this->alive && this->game != nullptr && !this->menu) this->alive = this->game->update(this->time->getTime(), this->event); };
  this->actions[arcade::Event::UP] = [this]() { if (this->let_play && this->alive && this->game != nullptr && !this->menu) this->alive = this->game->update(this->time->getTime(), this->event); };
  this->actions[arcade::Event::DOWN] = [this]() { if (this->let_play && this->alive && this->game != nullptr && !this->menu) this->alive = this->game->update(this->time->getTime(), this->event); };
  this->actions[arcade::Event::QUIT] = [this]() { this->can_play = false; };
  this->actions[arcade::Event::PAUSE] = [this]() { if (this->let_play && this->alive && this->game != nullptr && !this->menu) { this->pause(); } else { this->let_play = true; } };
  this->actions[arcade::Event::MENU] = [this]() { if (!this->menu) this->mainMenu(); else if (this->game != nullptr) this->menu = false; };
  this->actions[arcade::Event::PLUS] = [this]() { if (FPS < 30) FPS++; };
  this->actions[arcade::Event::MINUS] = [this]() { if (FPS > 5) FPS--; };
  this->actions[arcade::Event::ENTER] = [this]() { return ; };
  this->actions[arcade::Event::BACK] = [this]() { return ; };
  this->actions[arcade::Event::NEXT_GAME] = [this]() { this->swapGame(true); };
  this->actions[arcade::Event::PREV_GAME] = [this]() { this->swapGame(false); };
  this->actions[arcade::Event::NEXT_LIB] = [this]() { this->swapGraphics(true); };
  this->actions[arcade::Event::PREV_LIB] = [this]() { this->swapGraphics(false); };
  this->actions[arcade::Event::RESTART] = [this]() { this->loadGame(); };
  for (auto const &e : this->graphicspath)
    {
      if (path.compare(e) == 0)
	{
	  found = true;
	  this->current_graphics = idx;
	}
      idx++;
    }
  if (!found)
    {
      std::cout << "Unknown lib path '" << path << "'" << std::endl;
      std::cout << "[*] Trying to retrieve a known library..." << std::endl;
    }
  this->gfxLoader = std::make_unique<arcade::LibLoader<IGraphics>>(this->graphicspath.at(this->current_graphics));
  this->gameLoader = std::make_unique<arcade::LibLoader<IGame>>(this->gamepath.at(this->current_game));
  this->highscore = std::make_unique<arcade::Highscore>();
  this->home = std::make_unique<arcade::Menu>(WIN, FPS);
  this->loadGraphics();
  this->mainMenu();
}

arcade::GameManager::~GameManager()
{
  if (this->game != nullptr)
    delete this->game;
  if (this->graphics != nullptr)
    delete this->graphics;
}

void			arcade::GameManager::loadGame()
{
  if (this->game != nullptr)
    delete this->game;
  gameLoader->loadLibrary(this->gamepath.at(this->current_game));
  this->game = gameLoader->getFunc(WIN, "Useless", "createGame");
  if (this->game == nullptr)
    throw arcade::GameError("Could not load game instance");
  std::cout << "[*] Game loaded !" << std::endl;
  this->time->reset();
  this->time->start();
  this->can_play = true;
  this->alive = true;
  this->menu = false;
  this->playGame();
}

void			arcade::GameManager::loadGraphics()
{
  if (this->graphics != nullptr)
    delete this->graphics;
  gfxLoader->loadLibrary(this->graphicspath.at(this->current_graphics));
  this->graphics = gfxLoader->getFunc(WIN, "Arcade TRUB", "createGraphics");
  if (graphics == nullptr)
    throw arcade::GameError("Could not load graphics instance");
  std::cout << "[*] Lib '" << this->graphicspath.at(this->current_graphics) << "' loaded !" << std::endl;
}

int		arcade::GameManager::timeDiff(int fps)
{
  std::chrono::steady_clock::time_point	end;
  int					ret;

  end = std::chrono::steady_clock::now();
  ret = std::chrono::duration_cast<std::chrono::milliseconds>(end - this->begin).count();
  if (ret > (1000 / fps))
    this->begin = std::chrono::steady_clock::now();
  return (ret);
}

void		arcade::GameManager::handleEvent() const
{
  this->actions.at(this->event)();
}

void		arcade::GameManager::displayHUD() const
{
  std::string	game = this->gamepath.at(this->current_game);
  std::string	timer("Time : ");
  std::string	maxscore("Top : ");
  std::string	score("Score : ");
  std::string	display(std::to_string(this->time->getTime()));

  game = game.substr(game.find_last_of("_") + 1, game.find_last_of("."));
  std::transform(game.begin(), game.end(), game.begin(), ::toupper);
  game = game.substr(0, game.find_last_of("."));
  timer.append(6 - display.length(), '0').append(display);
  display.clear();
  display = std::to_string(this->game->getScore());
  score.append(6 - display.length(), '0').append(display);
  display = std::to_string(this->highscore->getHighestScore(game));
  maxscore.append(6 - display.length(), '0').append(display);
  this->graphics->renderText(score, {WIN.x - (12 * 14) - 40, WIN.y - 40}, 12, WHITE);
  this->graphics->renderText(timer, {40, WIN.y - 40}, 12, WHITE);
  this->graphics->renderText(maxscore, {CENTER_X(WIN.x, 12, 12), WIN.y - 40}, 12, WHITE);
}

void		arcade::GameManager::mainMenu()
{
  int		selected;

  this->menu = true;
  this->home->setSelected(-1);
  while (this->menu && this->can_play)
    {
      this->event = this->graphics->getLastEvent();
      switch (this->event)
	{
	case (arcade::Event::UP):
	  this->home->moveUp();
	  break;
	case (arcade::Event::DOWN):
	  this->home->moveDown();
	  break;
	case (arcade::Event::RIGHT):
	  this->home->moveRight();
	  break;
	case (arcade::Event::LEFT):
	  this->home->moveLeft();
	  break;
	case (arcade::Event::ENTER):
	  selected = this->home->getSelected();
	  this->home->validateInput();
	  this->home->setSelected(selected);
	  switch (selected)
	    {
	    case (1):
	      this->menu = false;
	      this->current_game = 1;
	      this->loadGame();
	      break;
	    case (2):
	      this->menu = false;
	      this->current_game = 0;
	      this->loadGame();
	      break;
	    case (5):
	      this->can_play = false;
	      this->menu = false;
	      break;
	    default:
	      break;
	    }
	  break;
	case (arcade::Event::BACK):
	  this->home->setSelected(-1);
	  break;
	default:
	  this->handleEvent();
	  break;
	}
      this->home->render(this->graphics, this->highscore.get());
    }
}

void		arcade::GameManager::gameOver(const std::string &display)
{
  std::string	game = this->gamepath.at(this->current_game);
  bool		newscore = false;
  int		size;

  size = static_cast<int>(display.size());
  this->time->stop();
  game = game.substr(game.find_last_of("_") + 1, game.find_last_of("."));
  std::transform(game.begin(), game.end(), game.begin(), ::toupper);
  game = game.substr(0, game.find_last_of("."));
  if (this->highscore->getHighestScore(game) < this->game->getScore())
    {
      this->highscore->setHighscore(game, this->home->getName(), this->game->getScore());
      newscore = true;
    }
  while (this->can_play)
    {
      if (this->timeDiff(FPS) > (1000 / FPS))
	{
	  this->graphics->clearScreen();
	  this->drawMap();
	  this->displayHUD();
	  this->graphics->renderText(display, {CENTER_X(WIN.x, size, 40),
		CENTER_Y(WIN.y, 20)}, 40, WHITE);
	  if (newscore)
	    this->graphics->renderText("New Highscore !", {CENTER_X(WIN.x, 15, 40),
		  CENTER_Y(WIN.y, 20) + 60}, 40, WHITE);
	  this->graphics->updateScreen();
	}
      this->event = this->graphics->getLastEvent();
      this->handleEvent();
    }
}

void		arcade::GameManager::pause()
{
  std::string	pause("Game Paused");
  int		size;

  size = static_cast<int>(pause.size());
  this->let_play = false;
  this->time->stop();
  while (!this->let_play && this->can_play)
    {
      if (this->timeDiff(FPS) > (1000 / FPS))
	{
	  this->graphics->clearScreen();
	  this->drawMap();
	  this->displayHUD();
	  this->graphics->renderText(pause, {CENTER_X(WIN.x, size, 40),
		CENTER_Y(WIN.y, 20)}, 40, WHITE);
	  this->graphics->updateScreen();
	}
      this->event = this->graphics->getLastEvent();
      this->handleEvent();
    }
  this->time->start();
}

bool		arcade::GameManager::drawMap() const
{
  Vec2i		pos;
  Vec2i		dim;
  Vec2i		size;
  Vec2i		tmp;
  bool		coin = true;
  std::string	game = this->gamepath.at(this->current_game);
  std::string	sprite;

  pos.y = -1;
  game = game.substr(game.find_last_of("_") + 1, game.find_last_of("."));
  std::transform(game.begin(), game.end(), game.begin(), ::toupper);
  game = game.substr(0, game.find_last_of("."));
  if (game.compare("PACMAN") == 0)
    coin = false;
  dim.set(this->game->getMap().getWidth(), this->game->getMap().getHeight());
  size.set(static_cast<int>(std::round(static_cast<float>(WIN.x) / static_cast<float>(dim.x))),
	   static_cast<int>(std::round(static_cast<float>(WIN.y) / static_cast<float>(dim.y))));
  while (++pos.y < dim.y)
    {
      pos.x = -1;
      while (++pos.x < dim.x)
	{
	  tmp.set((pos.x * size.x), (pos.y * size.y));
	  if (game.compare("PACMAN") == 0 &&
	      this->game->getMap().getBlockType(pos) == arcade::BlockType::COIN)
	    coin = true;
	  sprite = this->game->getSprite(this->game->getMap().getBlockType(pos));
	if (this->game->getMap().getBlockType(pos) == arcade::BlockType::PACMAN)
	  {
	    if (this->game->getCharacter().getLastDir() == arcade::Event::LEFT)
	      this->graphics->renderTexture(sprite, tmp, size, arcade::Event::LEFT);
	    else if (this->game->getCharacter().getLastDir() == arcade::Event::DOWN)
	      this->graphics->renderTexture(sprite, tmp, size, arcade::Event::DOWN);
	    else if (this->game->getCharacter().getLastDir() == arcade::Event::RIGHT)
	      this->graphics->renderTexture(sprite, tmp, size, arcade::Event::RIGHT);
	    else
	      this->graphics->renderTexture(sprite, tmp, size, arcade::Event::UP);
	  }
	else
	  this->graphics->renderTexture(sprite, tmp, size, arcade::Event::UP);
	}
    }
  return (coin);
}

void		arcade::GameManager::playGame()
{
  this->graphics->deleteSpritesAndTextures();
  this->graphics->loadTexture(this->game->loadSprites());
  this->home->setSelected(-1);
  while (this->can_play)
    {
      this->let_play = true;
      if (this->timeDiff(FPS) > (1000 / FPS))
	{
	  this->graphics->clearScreen();
	  this->alive = this->game->update(this->time->getTime(), arcade::Event::NOTHING);
	  if (!this->drawMap())
	    {
	      this->gameOver("You Win !");
	      return ;
	    }
	  this->displayHUD();
	  this->graphics->updateScreen();
	}
      this->event = this->graphics->getLastEvent();
      this->handleEvent();
      if (!this->alive)
	{
	  this->gameOver("Game Over");
	  return ;
	}
    }
}

void		arcade::GameManager::swapGame(bool next)
{
  if (next)
    this->current_game = (this->current_game == 1) ? (0) : (1);
  else
    this->current_game = (this->current_game == 0) ? (1) : (0);
  this->loadGame();
}

void		arcade::GameManager::swapGraphics(bool next)
{
  if (next)
    this->current_graphics = (this->current_graphics == 2) ? (0) :
      (this->current_graphics + 1);
  else
    this->current_graphics = (this->current_graphics == 0) ? (2) :
      (this->current_graphics - 1);
  this->loadGraphics();
}
