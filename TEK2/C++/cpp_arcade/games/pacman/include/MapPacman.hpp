/*
** MapPacman.hpp for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/MapPacman.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  lun. avr. 03 14:51:26 2017 Louis-Emile Uberti-Arès
// Last update Tue Apr  4 15:23:59 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include "AMap.hpp"

class MapPacman : public AMap
{
public:
    MapPacman(const Vec2i &dim) :
            AMap(dim)
    {
        this->generateMap();
    };

    ~MapPacman() = default;

    void		generateMap() noexcept override final
    {
        std::vector<std::string> map;
        Vec2i	pos;
        Vec2i   pos_bis;

        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXO           XX           OXXXXXXX");
        map.push_back("XXXXXXX XXXX XXXXX XX XXXXX XXXX XXXXXXX");
        map.push_back("XXXXXXX XXXX XXXXX XX XXXXX XXXX XXXXXXX");
        map.push_back("XXXXXXX XXXX XXXXX XX XXXXX XXXX XXXXXXX");
        map.push_back("XXXXXXX                          XXXXXXX");
        map.push_back("XXXXXXX XXXX XX XXXXXXXX XX XXXX XXXXXXX");
        map.push_back("XXXXXXX XXXX XX XXXXXXXX XX XXXX XXXXXXX");
        map.push_back("XXXXXXX      XX    XX    XX      XXXXXXX");
        map.push_back("XXXXXXXXXXXX XXXXX XX XXXXX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XXXXX XX XXXXX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XX          XX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XX XX-----X XX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XX XX-----X XX XXXXXXXXXXXX");
        map.push_back("                XX-----X                ");
        map.push_back("XXXXXXXXXXXX XX XX-----X XX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XX XXXXXXXX XX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XX          XX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XX XXXXXXXX XX XXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXX XX XXXXXXXX XX XXXXXXXXXXXX");
        map.push_back("XXXXXXX            XX            XXXXXXX");
        map.push_back("XXXXXXX XXXX XXXXX XX XXXXX XXXX XXXXXXX");
        map.push_back("XXXXXXX XXXX XXXXX XX XXXXX XXXX XXXXXXX");
        map.push_back("XXXXXXX   XX                XX   XXXXXXX");
        map.push_back("XXXXXXXXX XX XX XXXXXXXX XX XX XXXXXXXXX");
        map.push_back("XXXXXXXXX XX XX XXXXXXXX XX XX XXXXXXXXX");
        map.push_back("XXXXXXX      XX    XX    XX      XXXXXXX");
        map.push_back("XXXXXXX XXXXXXXXXX XX XXXXXXXXXX XXXXXXX");
        map.push_back("XXXXXXX XXXXXXXXXX XX XXXXXXXXXX XXXXXXX");
        map.push_back("XXXXXXXO                        OXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        map.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

        pos.y = 0;
        pos.x = -1;
        while (++pos.x < this->_size.x)
            _map[pos] = arcade::BlockType::WALL;
        while (++pos.y < this->_size.y - 1)
        {
            pos.x = -1;
            while (++pos.x < this->_size.x)
                _map[pos] = (pos.x == 0 || pos.x == this->_size.x - 1) ?
                            (arcade::BlockType::WALL) : (arcade::BlockType::EMPTY);
        }
        pos.x = -1;
        while (++pos.x < this->_size.x)
            _map[pos] = arcade::BlockType::WALL;
        pos_bis.y = 0;
        for (auto &e : map)
        {
            pos_bis.x = 0;
            for (auto &c : e) {
                if (pos_bis.x < this->_size.x &&
                    pos_bis.y < this->_size.y)
                {
                    if (c == ' ')
                        _map[pos_bis] = arcade::BlockType::COIN;
                    else if (c == '-')
                        _map[pos_bis] = arcade::BlockType::EMPTY;
                    else if (c == 'O')
                        _map[pos_bis] = arcade::BlockType::POWERUP_1;
                    else
                        _map[pos_bis] = arcade::BlockType::WALL;
                }
                pos_bis.x++;
            }
            pos_bis.y++;
        }
        /*_map[{19, 18}] = arcade::BlockType::GHOST_1;
        _map[{19, 19}] = arcade::BlockType::GHOST_2;
        _map[{20, 19}] = arcade::BlockType::GHOST_3;
        _map[{20, 18}] = arcade::BlockType::GHOST_4;*/
    }
};
