//
// Created by uberti_l on 5/29/17.
//

#pragma once
# include <deque>
# include <functional>
# include <unordered_map>
# include "Game/IGameObject.hh"
# include "Game/Model.hh"
# include "Irrlicht/IrrlichtDevice.h"
# include "Language.hpp"
# include "Irrlicht/dimension2d.h"
# include "GUI/IMenuItem.hh"

namespace Sprint
{
    namespace GUI
    {
        class CarMenu : public IMenuItem
        {
        public:
            CarMenu(irr::IrrlichtDevice &device, const std::string &font,
                    std::unordered_map<Sprint::Game::Model, std::unique_ptr<Sprint::Game::IGameObject> > &objs,
                    Sprint::Language &lang, const irr::core::dimension2du &dim, bool &inMenu, int &nbPlayers,
                    Sprint::Game::Model playersCar[4]);
            CarMenu(const CarMenu &cpy) = delete;
            CarMenu& operator=(const CarMenu &cpy) = delete;
            ~CarMenu();
            void                                reset() final;
            void                                render() const final;
            void                                move(irr::EKEY_CODE key) final;
            Sprint::GUI::MenuItem               getSelected();

        private:
            std::unordered_map<Sprint::Game::Model, std::unique_ptr<Sprint::Game::IGameObject> >    &objs;
            irr::IrrlichtDevice                                                                     &device;
            std::vector<irr::scene::ISceneNode *>                                                   clones;
            const std::string                                                                       ttf;
            std::unordered_map<Sprint::Game::Model, int>                                            playerChoice;
            Sprint::Language                                                                        &language;
            std::deque<std::pair<bool, irr::core::vector3df> >                                      positions;
            const irr::core::dimension2du                                                           &winDim;
            int                                                                                     curr_item;
            int                                                                                     curr_player;
            float                                                                                   spaceOut;
            int                                                                                     currPlayer;
            int                                                                                     &nbPlayers;
            bool                                                                                    &inMenu;
            Sprint::Game::Model                                                                     *playersCar;
        };
    }
}