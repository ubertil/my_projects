//
// Created by uberti_l on 5/29/17.
//

#pragma once
# include <map>
# include "Language.hpp"
# include "Irrlicht/dimension2d.h"
# include "Utils/IniManager.hpp"
# include "GUI/IMenuItem.hh"

namespace Sprint
{
    namespace GUI
    {
        class OptionsMenu : public IMenuItem
        {
        public:
            OptionsMenu(irr::IrrlichtDevice &device, const std::string &font,
                        Sprint::Utils::IniManager &manager, Sprint::Language &lang, const irr::core::dimension2du &dim);
            OptionsMenu(const OptionsMenu &cpy) = delete;
            OptionsMenu& operator=(const OptionsMenu &cpy) = delete;
            ~OptionsMenu() = default;
            void                            reset();
            void                            render() const;
            void                            move(irr::EKEY_CODE key);
            Sprint::GUI::MenuItem           getSelected();
            void                            saveConfig();

            enum select
            {
                NONE = -1,
                LANG_EN = 0,
                LANG_FR = 1,
                VOLUME = 2,
                VSYNC_DISABLED = 3,
                VSYNC_ENABLED = 4,
                FULLSCREEN_DISABLED = 5,
                FULLSCREEN_ENABLED = 6,
                RES_LARGE = 7,
                RES_MEDIUM = 8,
                RES_SMALL = 9,
                SAVE = 10,
                BACK = 11
            };

        private:
            const std::string               ttf;
            std::map<std::string, select>   config;
            irr::IrrlichtDevice             &device;
            Sprint::Utils::IniManager       &manager;
            Sprint::Language                &language;
            const irr::core::dimension2du   &winDim;
            int                             curr_item;
            int                             max_item;
            float                           volume;

            void                            resetConf();
            void                            saveResolution();
            void                            saveScreenMode();
            void                            saveVSyncMode();
            void                            saveVolume();
            void                            saveLang();
        };
    }
}