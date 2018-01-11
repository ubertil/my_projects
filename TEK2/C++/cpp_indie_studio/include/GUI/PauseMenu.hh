//
// Created by uberti_l on 6/17/17.
//

#pragma once
# include <vector>
# include "Language.hpp"
# include "Irrlicht/dimension2d.h"
# include "GUI/IMenuItem.hh"

namespace Sprint
{
    namespace GUI
    {
        class PauseMenu : public IMenuItem
        {
        public:
            PauseMenu(irr::IrrlichtDevice &device, const std::string &font, Sprint::Language &lang, const irr::core::dimension2du &dim,
                      bool &inMenu, bool &inPause, bool &quitRequest);
            PauseMenu(const PauseMenu &cpy) = delete;
            PauseMenu& operator=(const PauseMenu &cpy) = delete;
            ~PauseMenu() = default;
            void                            reset() final;
            void                            render() const final;
            void                            move(irr::EKEY_CODE key) final;
            Sprint::GUI::MenuItem           getSelected();

        private:
            irr::IrrlichtDevice             &device;
            Sprint::Language                &language;
            const irr::core::dimension2du   &winDim;
            const std::string               ttf;
            int                             curr_item;
            bool                            &inMenu;
            bool                            &inPause;
            bool                            &quitRequest;
            std::vector<std::string>        textPack;
        };
    }
}