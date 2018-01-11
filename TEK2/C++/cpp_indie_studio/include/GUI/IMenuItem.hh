//
// Created by uberti_l on 5/29/17.
//

#pragma once
# include "Irrlicht/IrrlichtDevice.h"
# include "Irrlicht/Keycodes.h"
# include "GUI/MenuItem.hh"

namespace Sprint
{
    namespace GUI
    {
        class IMenuItem
        {
        public:
            virtual ~IMenuItem() = default;
            virtual void                    render() const = 0;
            virtual void                    reset() = 0;
            virtual void                    move(irr::EKEY_CODE key) = 0;
            virtual Sprint::GUI::MenuItem   getSelected() = 0;
        };
    }
}
