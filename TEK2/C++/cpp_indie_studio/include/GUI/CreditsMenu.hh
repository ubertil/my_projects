//
// Created by uberti_l on 5/29/17.
//

#pragma once
# include "Language.hpp"
# include "Irrlicht/dimension2d.h"
# include "GUI/IMenuItem.hh"

namespace Sprint
{
    namespace GUI
    {
        class CreditsMenu : public IMenuItem
        {
        public:
            CreditsMenu(irr::IrrlichtDevice &device, const std::string &font, Sprint::Language &lang, const irr::core::dimension2du &dim);
            CreditsMenu(const CreditsMenu &cpy) = delete;
            CreditsMenu& operator=(const CreditsMenu &cpy) = delete;
            ~CreditsMenu() = default;
            void                            reset() final;
            void                            render() const final;
            void                            move(irr::EKEY_CODE key) final;
            Sprint::GUI::MenuItem           getSelected();

        private:
            irr::IrrlichtDevice             &device;
            Sprint::Language                &language;
            const irr::core::dimension2du   &winDim;
            const std::string               ttf;
        };
    }
}