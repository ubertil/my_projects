//
// Created by Nicolas on 09/04/17.
//

#include "Fuckman.hh"

void Fuckman::generateGhostRandomDirection()
{
    Vec2i tmp;

    tmp.x = (rand() % 3 - 1);
    tmp.y = (rand() % 3 - 1);
    while (this->_map->getBlockType({this->_pos.back().x + tmp.x, this->_pos.back().y + tmp.y}) == arcade::BlockType::WALL) {
        tmp.x = (rand() % 3 - 1);
        tmp.y = (rand() % 3 - 1);
    }
    if (tmp.x == -1 && tmp.y == 0)
        this->_dir = arcade::Event::LEFT;
    if (tmp.x == 1 && tmp.y == 0)
        this->_dir = arcade::Event::RIGHT;
    if (tmp.x == 0 && tmp.y == -1)
        this->_dir = arcade::Event::UP;
    if (tmp.x == 0 && tmp.y == 1)
        this->_dir = arcade::Event::DOWN;
}

void Fuckman::setPosition(int x, int y)
{
    Vec2i tmp;

    tmp.x = x;
    tmp.y = y;
    this->_pos.push_back(tmp);
    this->_pos.pop_front();
}

Fuckman::Fuckman(const Vec2i &pos, uint16_t lives, AMap *map, arcade::BlockType type) :
        ACharacter(pos, lives, map) {
    _smooth = arcade::Event::NOTHING;
    _type = type;
    _old = arcade::BlockType::WALL;
};

int		Fuckman::move()
{
    int     ret;
    Vec2i	lastPos;
    Vec2i	firstPos;
    Vec2i   tmp;

    ret = true;
    if (_smooth != arcade::Event::NOTHING)
        setDirection(_smooth);
    lastPos = this->_pos.back();
    firstPos = this->_pos.front();

    Vec2i   newPos;

    switch (this->_dir)
    {
        case (arcade::Event::UP) :
            if (this->_map->getBlockType({lastPos.x, lastPos.y - 1}) == arcade::BlockType::WALL) {
                if (_type != arcade::BlockType::PACMAN)
                    generateGhostRandomDirection();
                return (true);
            }
            else
            {
                newPos.x = lastPos.x;
                newPos.y = lastPos.y - 1;
            }
            break;
        case (arcade::Event::DOWN) :
            if (this->_map->getBlockType({lastPos.x, lastPos.y + 1}) == arcade::BlockType::WALL) {
                if (_type != arcade::BlockType::PACMAN)
                    generateGhostRandomDirection();
                return (true);
            }
            else
            {
                newPos.x = lastPos.x;
                newPos.y = lastPos.y + 1;
            }
            break;
        case (arcade::Event::RIGHT) :
            if (this->_map->getBlockType({lastPos.x + 1, lastPos.y}) == arcade::BlockType::WALL &&
                lastPos.x == this->_map->getWidth() - 1)
            {
                newPos.x = 0;
                newPos.y = lastPos.y;
            }
            else if (this->_map->getBlockType({lastPos.x + 1, lastPos.y}) == arcade::BlockType::WALL) {
                if (_type != arcade::BlockType::PACMAN)
                    generateGhostRandomDirection();
                return (true);
            }
            else
            {
                newPos.x = lastPos.x + 1;
                newPos.y = lastPos.y;
            }
            break;
        case (arcade::Event::LEFT) :
            if (this->_map->getBlockType({lastPos.x - 1, lastPos.y}) == arcade::BlockType::WALL &&
                lastPos.x == 0)
            {
                newPos.x = this->_map->getWidth() - 1;
                newPos.y = lastPos.y;
            }
            else if (this->_map->getBlockType({lastPos.x - 1, lastPos.y}) == arcade::BlockType::WALL) {
                if (_type != arcade::BlockType::PACMAN)
                    generateGhostRandomDirection();
                return (true);
            }
            else
            {
                newPos.x = lastPos.x - 1;
                newPos.y = lastPos.y;
            }
            break;
        default:
            return (true);
    }
    this->_pos.push_back({newPos.x, newPos.y});
    if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::COIN &&
        this->_type == arcade::BlockType::PACMAN) {
        this->score += 1;
    }
    if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::POWERUP_2 &&
        this->_type == arcade::BlockType::PACMAN) {
        this->score += 50;
    }
    if (this->_type == arcade::BlockType::PACMAN)
    {
        if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::POWERUP_1)
            ret = 2;
        if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::GHOST_1)
            ret = 3;
        if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::GHOST_2)
            ret = 4;
        if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::GHOST_3)
            ret = 5;
        if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::GHOST_4)
            ret = 6;
    }
    if (this->_map->getBlockType({newPos.x, newPos.y}) == arcade::BlockType::PACMAN)
    {
        if (this->_type == arcade::BlockType::GHOST_1)
            ret = 3;
        if (this->_type == arcade::BlockType::GHOST_2)
            ret = 4;
        if (this->_type == arcade::BlockType::GHOST_3)
            ret = 5;
        if (this->_type == arcade::BlockType::GHOST_4)
            ret = 6;
    }
    this->_pos.pop_front();
    if (this->getScore() % 100 == 0 && this->getScore() != 0)
        this->_map->placePowerUp();
    if (this->_type == arcade::BlockType::PACMAN)
        this->_map->setBlockType(firstPos, arcade::BlockType::EMPTY);
    else if (this->_old != arcade::BlockType::WALL)
        this->_map->setBlockType(firstPos, this->_old);
    if (this->_map->getBlockType(newPos) == arcade::BlockType::COIN ||
        this->_map->getBlockType(newPos) == arcade::BlockType::POWERUP_1 ||
        this->_map->getBlockType(newPos) == arcade::BlockType::EMPTY ||
	this->_map->getBlockType(newPos) == arcade::BlockType::POWERUP_2)
        this->_old = this->_map->getBlockType(newPos);
    else
        this->_old = arcade::BlockType::WALL;
    if (_type == arcade::BlockType::GHOST_1)
        this->_map->setBlockType({newPos.x, newPos.y}, arcade::BlockType::GHOST_1);
    else if (_type == arcade::BlockType::GHOST_2)
        this->_map->setBlockType({newPos.x, newPos.y}, arcade::BlockType::GHOST_2);
    else if (_type == arcade::BlockType::GHOST_3)
        this->_map->setBlockType({newPos.x, newPos.y}, arcade::BlockType::GHOST_3);
    else if (_type == arcade::BlockType::GHOST_4)
        this->_map->setBlockType({newPos.x, newPos.y}, arcade::BlockType::GHOST_4);
    else if (_type == arcade::BlockType::PACMAN)
        this->_map->setBlockType({newPos.x, newPos.y}, arcade::BlockType::PACMAN);
    else
        this->_map->setBlockType({newPos.x, newPos.y}, arcade::BlockType::GOD_MODE);
    return (ret);
}

void		Fuckman::setDirection(arcade::Event dir)
{
    switch (dir) {
        case (arcade::Event::UP) :
            if (this->_map->getBlockType({this->getPos().back().x, this->getPos().back().y - 1}) !=
                arcade::BlockType::WALL) {
                this->_dir = dir;
                this->_smooth = arcade::Event::NOTHING;
            }
            else
                this->_smooth = dir;
            break;
        case (arcade::Event::DOWN) :
            if (this->_map->getBlockType({this->getPos().back().x, this->getPos().back().y + 1}) !=
                arcade::BlockType::WALL) {
                this->_dir = dir;
                this->_smooth = arcade::Event::NOTHING;
            }
            else
                this->_smooth = dir;
            break;
        case (arcade::Event::LEFT) :
            if (this->_map->getBlockType({this->getPos().back().x - 1, this->getPos().back().y}) !=
                arcade::BlockType::WALL) {
                this->_dir = dir;
                this->_smooth = arcade::Event::NOTHING;
            }
            else
                this->_smooth = dir;
            break;
        case (arcade::Event::RIGHT) :
            if (this->_map->getBlockType({this->getPos().back().x + 1, this->getPos().back().y}) !=
                arcade::BlockType::WALL) {
                this->_dir = dir;
                this->_smooth = arcade::Event::NOTHING;
            }
            else
                this->_smooth = dir;
            break;
        default:
            break;
    }
}
