//
// Created by uberti_l on 6/16/17.
//

#pragma once
# include <functional>
# include <vector>
# include <string>
# include "Irrlicht/ITimer.h"
# include "Irrlicht/IrrlichtDevice.h"
# include "Game/Model.hh"
# include "Language.hpp"

namespace Sprint
{
    namespace GUI
    {
        class ATH
        {
        public:
            ATH(irr::IrrlichtDevice &device, Sprint::Language &lang, const std::string &font);
            ATH(const ATH &cpy) = delete;
            ATH&    operator=(const ATH &cpy) = delete;
            ATH() = default;
            void    displayATH(const int nbLap, const int max, const float carSpeed) const;
            void    displayRanking(Sprint::Game::Model playerOne, const int nbPlayers,
                                   const std::vector<std::pair<Sprint::Game::Model, int>> &ranks) const;
            void    displayStart(irr::IrrlichtDevice *device) const;
        private:
            irr::IrrlichtDevice     &device;
            Sprint::Language        &language;
            const std::string       ttf;
        };
    }
}