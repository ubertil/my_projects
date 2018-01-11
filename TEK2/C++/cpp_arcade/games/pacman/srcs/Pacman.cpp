/*
** Pacman.cpp for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Pacman.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. mars 23 22:41:38 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:23:38 2017 Lous-Emile Uberti-Ares
*/

#include <iostream>
#include "Event.hh"
#include "ACharacter.hpp"
#include "Pacman.hh"

IMap&		arcade::Pacman::getMap() const
{
  return (*this->_map.get());
}

ICharacter&	arcade::Pacman::getCharacter() const
{
  return (*this->_character.get());
}

arcade::Pacman::Pacman()
{
  Vec2i		size(40, 40);
  Vec2i		pos(20, 27);

  this->_map = std::make_unique<MapPacman>(size);
  this->_character = std::make_unique<Fuckman>(pos, 3, this->_map.get(), arcade::BlockType::PACMAN);
  pos = {19, 18};
  this->_ghost_1 = std::make_unique<Fuckman>(pos, 1, this->_map.get(), arcade::BlockType::GHOST_1);
  this->_ghost_1->setDirection(arcade::Event::UP);
  pos = {19, 19};
  this->_ghost_2 = std::make_unique<Fuckman>(pos, 1, this->_map.get(), arcade::BlockType::GHOST_2);
  this->_ghost_2->setDirection(arcade::Event::UP);
  pos = {20, 19};
  this->_ghost_3 = std::make_unique<Fuckman>(pos, 1, this->_map.get(), arcade::BlockType::GHOST_3);
  this->_ghost_3->setDirection(arcade::Event::UP);
  pos = {20, 18};
  this->_ghost_4 = std::make_unique<Fuckman>(pos, 1, this->_map.get(), arcade::BlockType::GHOST_4);
  this->_ghost_4->setDirection(arcade::Event::UP);
  this->_sprites[arcade::BlockType::EMPTY] = "ressources/pacman/empty.png";
  this->_sprites[arcade::BlockType::PACMAN] = "ressources/pacman/pacman.png";
  this->_sprites[arcade::BlockType::WALL] = "ressources/pacman/bg.png";
  this->_sprites[arcade::BlockType::COIN] = "ressources/pacman/coin.png";
  this->_sprites[arcade::BlockType::POWERUP_1] = "ressources/pacman/powerup_1.png";
  this->_sprites[arcade::BlockType::POWERUP_2] = "ressources/pacman/cherry.png";
  this->_sprites[arcade::BlockType::GHOST_1] = "ressources/pacman/ghost_1.png";
  this->_sprites[arcade::BlockType::GHOST_2] = "ressources/pacman/ghost_2.png";
  this->_sprites[arcade::BlockType::GHOST_3] = "ressources/pacman/ghost_3.png";
  this->_sprites[arcade::BlockType::GHOST_4] = "ressources/pacman/ghost_4.png";
  this->_sprites[arcade::BlockType::GOD_MODE] = "ressources/pacman/godmode.png";
  this->_godMode = 0;
  this->_checkCherry = false;
  this->_map->setBlockType({20, 27}, arcade::BlockType::PACMAN);
}

char			arcade::Pacman::getGodMode() const
{
  return (this->_godMode);
}
void			arcade::Pacman::setGodMode(const char v)
{
  this->_godMode = v;
}

bool			arcade::Pacman::checkReturn(const int ret)
{
  switch (ret)
    {
    case (3) :
      if (this->getGodMode() != 0)
	this->_ghost_1->setPosition(19, 18);
      else
	return (false);
      break;
    case (4) :
      if (this->getGodMode() != 0)
	this->_ghost_2->setPosition(19, 18);
      else
	return (false);
      break;
    case (5) :
      if (this->getGodMode() != 0)
	this->_ghost_3->setPosition(19, 18);
      else
	return (false);
      break;
    case (6) :
      if (this->getGodMode() != 0)
	this->_ghost_4->setPosition(19, 18);
      else
	return (false);
      break;
    default :
      break;
    }
  return (true);
}

void		arcade::Pacman::placePPowerUp()
{
  Vec2i		pos(0, 0);

  while (this->_map->getBlockType(pos) != arcade::BlockType::EMPTY &&
	this->_map->getBlockType(pos) != arcade::BlockType::COIN)
    pos.set(std::rand() % this->_map->getWidth(), std::rand() % this->_map->getHeight());
  this->_map->setBlockType(pos, arcade::BlockType::POWERUP_2);
}

bool		arcade::Pacman::update(const int sec, arcade::Event event)
{
  int		ret;
  Vec2i		tmp;

  if (event != arcade::Event::NOTHING)
    {
      if (event != this->_character->getLastDir()) {
	this->_character->setDirection(event);
      }
    }
  else {
    if (sec != 0 && sec % 10 == 0)
      {
	if (this->_checkCherry != true)
	  {
	    this->placePPowerUp();
	    this->_checkCherry = true;
	  }
      }
    else
      this->_checkCherry = false;
    if (sec >= 10)
      {
	this->_map->setBlockType({19, 18}, arcade::BlockType::EMPTY);
	this->_map->setBlockType({19, 19}, arcade::BlockType::EMPTY);
	this->_map->setBlockType({20, 19}, arcade::BlockType::EMPTY);
	this->_map->setBlockType({20, 18}, arcade::BlockType::EMPTY);
	if (checkReturn(this->_ghost_1->move()) == 0 ||
	    checkReturn(this->_ghost_2->move()) == 0 ||
	    checkReturn(this->_ghost_3->move()) == 0 ||
	    checkReturn(this->_ghost_4->move()) == 0)
	  return (false);
      }
    else if (sec < 10)
      {
	this->_map->setBlockType({19, 18}, arcade::BlockType::GHOST_1);
	this->_map->setBlockType({19, 19}, arcade::BlockType::GHOST_2);
	this->_map->setBlockType({20, 19}, arcade::BlockType::GHOST_3);
	this->_map->setBlockType({20, 18}, arcade::BlockType::GHOST_4);
      }
    if ((ret = this->_character->move()) == 2)
      this->setGodMode(sec);
    if (this->checkReturn(ret) == false)
      return (false);
    if (this->getGodMode() != 0)
      {
	tmp.x = 0;
	while (tmp.x < this->_map->getWidth())
	  {
	    tmp.y = 0;
	    while (tmp.y < this->_map->getHeight())
	      {
		if (this->_map->getBlockType(tmp) == arcade::BlockType::GHOST_1 ||
		    this->_map->getBlockType(tmp) == arcade::BlockType::GHOST_2 ||
		    this->_map->getBlockType(tmp) == arcade::BlockType::GHOST_3 ||
		    this->_map->getBlockType(tmp) == arcade::BlockType::GHOST_4)
		  this->_map->setBlockType(tmp, arcade::BlockType::GOD_MODE);
		tmp.y++;
	      }
	    tmp.x++;
	  }
	if (sec - this->getGodMode() >= 10)
	  this->setGodMode(0);
      }
    return (true);
  }
  return (true);
}

int		arcade::Pacman::getScore() const
{
  return (this->_character->getScore());
}

std::vector<std::string>	arcade::Pacman::loadSprites() const
{
  std::vector<std::string>	ret;

  for (auto const &e : this->_sprites)
    ret.push_back(e.second);
  return (ret);
}

const std::string&		arcade::Pacman::getSprite(arcade::BlockType type) const
{
  return (this->_sprites.at(type));
}

static void		printMap(IMap &map)
{
  arcade::GetMap	*new_map;
  arcade::BlockType	block;
  arcade::TileType	new_block;
  Vec2i			idx(-1, -1);
  size_t		size;

  new_map = new arcade::GetMap[sizeof(arcade::TileType) * (map.getWidth() * map.getHeight())];
  new_map->width = map.getWidth();
  new_map->height = map.getHeight();
  size = sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * (new_map->height * new_map->width));
  new_map->type = arcade::CommandType::GET_MAP;
  while (++idx.y < new_map->height)
    {
      idx.x = -1;
      while (++idx.x < new_map->width)
	{
	  block = map.getBlockType(idx);
	  switch (block)
	    {
	    case (arcade::BlockType::EMPTY) :
	      new_block = arcade::TileType::EMPTY;
	      break;
	    case (arcade::BlockType::SNAKE) :
	      new_block = arcade::TileType::EMPTY;
	      break;
	    case (arcade::BlockType::WALL) :
	      new_block = arcade::TileType::BLOCK;
	      break;
	    case (arcade::BlockType::POWERUP_1) :
	    case (arcade::BlockType::POWERUP_2) :
	    case (arcade::BlockType::POWERUP_3) :
	      new_block = arcade::TileType::POWERUP;
	    break;
	    default:
	      new_block = arcade::TileType::OTHER;
	      break;
	    }
	  new_map->tile[idx.y * new_map->width + idx.x] = new_block;
	}
    }
  std::cout.write(reinterpret_cast<char *>(new_map), size);
}

static void		printPlayerPos(ICharacter &fuckman)
{
  arcade::WhereAmI	*where;
  size_t		size = sizeof(arcade::WhereAmI) + sizeof(arcade::Position);

  where = new arcade::WhereAmI[sizeof(arcade::Position)];
  where->lenght = 1;
  where->type = arcade::CommandType::WHERE_AM_I;
  where->position[0].x = static_cast<uint16_t>(fuckman.getPos().front().x);
  where->position[0].y = static_cast<uint16_t>(fuckman.getPos().front().y);
  std::cout.write(reinterpret_cast<char *>(where), size);
}

extern "C"
{
  void			Play()
  {
    arcade::CommandType	cmd;
    char		c;
    int			i = 0;
    arcade::Pacman	game;

    while (std::cin.read(&c, sizeof(arcade::CommandType)))
      {
	cmd = static_cast<arcade::CommandType>(c);
	switch (cmd)
	  {
	  case (arcade::CommandType::GET_MAP) :
	    printMap(game.getMap());
	    break;
	  case (arcade::CommandType::WHERE_AM_I):
	    printPlayerPos(game.getCharacter());
	    break;
	  case (arcade::CommandType::GO_LEFT):
	    game.getCharacter().setDirection(arcade::Event::LEFT);
	    break;
	  case (arcade::CommandType::GO_RIGHT) :
	    game.getCharacter().setDirection(arcade::Event::RIGHT);
	    break;
	  case (arcade::CommandType::GO_UP) :
	    game.getCharacter().setDirection(arcade::Event::UP);
	    break;
	  case (arcade::CommandType::GO_DOWN) :
	    game.getCharacter().setDirection(arcade::Event::DOWN);
	    break;
	  case (arcade::CommandType::GO_FORWARD) :
	    break;
	  case (arcade::CommandType::PLAY) :
	    game.update(++i, arcade::Event::NOTHING);
	    break;
	  default:
	    break;
	  }
      }
  }

  arcade::IGame		*createGame()
  {
    return (new arcade::Pacman());
  }
}
