/*
** Snake.cpp for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Snake.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. mars 23 22:41:38 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 18:18:45 2017 Lous-Emile Uberti-Ares
*/

#include <iostream>
#include "Event.hh"
#include "ACharacter.hpp"
#include "Snake.hh"

IMap&		arcade::Snake::getMap() const
{
  return (*this->_map.get());
}

ICharacter&	arcade::Snake::getCharacter() const
{
  return (*this->_character.get());
}

arcade::Snake::Snake()
{
  Vec2i		size(40, 40);
  Vec2i		pos(15, 15);

  this->_map = std::make_unique<MapSnake>(size);
  this->_character = std::make_unique<Boa>(pos, 3, this->_map.get());
  this->_map->placePowerUp();
  this->_sprites[arcade::BlockType::EMPTY] = "ressources/snake/snake_background.jpg";
  this->_sprites[arcade::BlockType::SNAKE] = "ressources/snake/snake.jpg";
  this->_sprites[arcade::BlockType::WALL] = "ressources/snake/snake_wall.jpg";
  this->_sprites[arcade::BlockType::POWERUP_1] = "ressources/snake/powerup.png";
  this->_map->setBlockType({15, 15}, arcade::BlockType::SNAKE);
  this->_map->setBlockType({14, 15}, arcade::BlockType::SNAKE);
  this->_map->setBlockType({13, 15}, arcade::BlockType::SNAKE);
  this->_map->setBlockType({12, 15}, arcade::BlockType::SNAKE);
  this->_character->setDirection(arcade::Event::LEFT);
}

bool		arcade::Snake::update(const int sec, arcade::Event event)
{
  (void)sec;
  if (event != arcade::Event::NOTHING)
    {
      if (event != this->_character->getLastDir())
	this->_character->setDirection(event);
    }
  else
    return (this->_character->move());
  return (true);
}

int		arcade::Snake::getScore() const
{
  return (this->_character->getScore());
}

std::vector<std::string>	arcade::Snake::loadSprites() const
{
  std::vector<std::string>	ret;

  for (auto const &e : this->_sprites)
    ret.push_back(e.second);
  return (ret);
}

const std::string&		arcade::Snake::getSprite(arcade::BlockType type) const
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

static void		printPlayerPos(ICharacter &character)
{
  arcade::WhereAmI	*where;
  std::list<Vec2i>	pos;
  int			i = 0;
  size_t		size = sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * character.getPos().size();

  pos = character.getPos();
  where = new arcade::WhereAmI[sizeof(arcade::Position) * character.getPos().size()];
  where->lenght = character.getPos().size();
  where->type = arcade::CommandType::WHERE_AM_I;
  for (std::list<Vec2i>::reverse_iterator it = pos.rbegin(); it != pos.rend(); ++it)
    {
      where->position[i].x = static_cast<uint16_t>(it->x);
      where->position[i].y = static_cast<uint16_t>(it->y);
      ++i;
    }
  std::cout.write(reinterpret_cast<char *>(where), size);
}

extern "C"
{
  void			Play()
  {
    arcade::CommandType	cmd;
    char		c;
    arcade::Snake	game;

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
	    game.getCharacter().move();
	    break;
	  default:
	    break;
	  }
      }
  }

  arcade::IGame		*createGame()
  {
    return (new arcade::Snake());
  }
}
