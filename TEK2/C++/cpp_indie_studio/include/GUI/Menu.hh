//
// Created by uberti_l on 5/23/17.
//

#pragma once
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif
# include <list>
# include <unordered_map>
# include <memory>
# include <stdint.h>
# include "Input/Event.hh"
# include "Game/Model.hh"
# include "Game/IGameObject.hh"
# include "GUI/IMenuItem.hh"
# include "Utils/IniManager.hpp"
# include "Sound/Source.hh"
# include "Language.hpp"
# include "Irrlicht/irrlicht.h"

namespace Sprint
{
    namespace GUI
    {
        class Menu
        {
        public:
            Menu(irr::IrrlichtDevice &device, std::vector<std::unique_ptr<Sprint::Sound::Source>> &sounds,
                 std::unordered_map<Sprint::Game::Model, std::unique_ptr<Sprint::Game::IGameObject> > &objs,
                 Sprint::Utils::IniManager &manager, Sprint::Language &lang, const std::string &font, int &nbPlayers,
                 Sprint::Game::Model playersCar[4]);
            Menu(const Menu &cpy) = delete;
            Menu&   operator=(const Menu &cpy) = delete;
            ~Menu() = default;
            void    drawAll() const;
            void    setInMenu(bool state = true);
            void    reset();
            bool    quit() const;
            void    move(Sprint::Input::EventReceiver &receiver);
            bool    isInPause() const;
            bool    isInMenu() const;

        private:
            bool                                                                                    inMenu;
            bool                                                                                    inPause;
            bool                                                                                    quitRequest;
            const irr::core::dimension2d<irr::u32>                                                  &winDim;
            std::list<MenuItem>                                                                     old_menu;
            MenuItem                                                                                curr_menu;
            Sprint::Language                                                                        &language;
            std::vector<std::unique_ptr<Sprint::Sound::Source>>                                     &sounds;
            std::unordered_map<Sprint::Game::Model, std::unique_ptr<Sprint::Game::IGameObject> >    &objs;
            std::unordered_map<irr::EKEY_CODE, std::function<void()> >                              keyMap;
            std::unordered_map<MenuItem, std::unique_ptr<Sprint::GUI::IMenuItem> >                  menus;
        };


    }
}