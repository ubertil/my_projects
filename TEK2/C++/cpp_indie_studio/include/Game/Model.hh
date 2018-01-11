//
// Created by uberti_l on 5/27/17.
//

#pragma once
# include <string>
# include <stdint.h>

namespace Sprint
{
    namespace Game
    {
        static const std::string ModelName[] = { "ALL", "MARIO", "PEACH", "WARIO", "LUIGI", "BOWSER", "TOAD", "YOSHI", "LUIGI CIRCUIT", "REFEREE", "STATUE", "ZEPPELIN" };

        enum class Model : uint16_t
        {
            ALL = 0,
            MARIO_KART,
            PEACH_KART,
            WARIO_KART,
            LUIGI_KART,
            BOWSER_KART,
            TOAD_KART,
            YOSHI_KART,
            LUIGI_CIRCUIT,
            REFEREE,
            STATUE,
            ZEPPELIN
        };
    }
}
