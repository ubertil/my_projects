//
// Created by uberti_l on 5/29/17.
//

#pragma once
# include <memory>
# include <vector>
# include <unordered_map>
# include "Irrlicht/dimension2d.h"
# include "GUI/IMenuItem.hh"
# include "Game/Model.hh"
# include "Game/IGameObject.hh"
# include "Language.hpp"

namespace Sprint
{
    namespace GUI
    {
        class MainMenu : public IMenuItem
        {
        public:
            MainMenu(irr::IrrlichtDevice &device, const std::string &ttf,
                     irr::scene::IAnimatedMeshSceneNode &marioKart, Sprint::Language &lang, const irr::core::dimension2du &dim);
            MainMenu(const MainMenu &cpy) = delete;
            MainMenu &operator=(const MainMenu &cpy) = delete;
            ~MainMenu();

            void                                                    reset() final;
            void                                                    render() const final;
            void                                                    move(irr::EKEY_CODE key) final;
            Sprint::GUI::MenuItem                                   getSelected() final;
        private:
            irr::IrrlichtDevice                                     &device;
            irr::scene::IAnimatedMeshSceneNode                      &marioKart;
            const irr::core::dimension2du                           &winDim;
            Sprint::Language                                        &language;
            std::vector<std::string>                                textPack;
            int                                                     curr_item;
            const int                                               max_item;
            const std::string                                       ttf;
        };
    }
}
