//
// Created by uberti_l on 5/23/17.
//

#include "GUI/PauseMenu.hh"
#include "GUI/Menu.hh"
#include "GUI/MainMenu.hh"
#include "GUI/CreditsMenu.hh"
#include "GUI/CarMenu.hh"
#include "GUI/OptionsMenu.hh"
#include "GUI/QuitMenu.hh"

Sprint::GUI::Menu::Menu(irr::IrrlichtDevice &device, std::vector<std::unique_ptr<Sprint::Sound::Source>> &sounds,
                        std::unordered_map<Sprint::Game::Model, std::unique_ptr<Sprint::Game::IGameObject> > &objs,
                        Sprint::Utils::IniManager &manager, Sprint::Language &lang, const std::string &font, int &nbPlayers,
                        Sprint::Game::Model playersCar[4]) :
        inMenu(true), inPause(false), quitRequest(false), sounds(sounds), objs(objs),
        winDim(device.getVideoDriver()->getScreenSize()), curr_menu(MenuItem::MAIN), language(lang)
{
    this->old_menu.push_back(MenuItem::MAIN);
    this->sounds.at(Sprint::Sound::Song::MAIN_THEME)->setLooping(true);
    this->sounds.at(Sprint::Sound::Song::MAIN_THEME)->play();
    this->menus[MenuItem::MAIN] = std::make_unique<Sprint::GUI::MainMenu>(device, font, this->objs.at(Sprint::Game::Model::MARIO_KART).get()->getNode(), lang, winDim);
    this->menus[MenuItem::CREDITS] = std::make_unique<Sprint::GUI::CreditsMenu>(device, font, lang, winDim);
    this->menus[MenuItem::OPTIONS] = std::make_unique<Sprint::GUI::OptionsMenu>(device, font, manager, lang, winDim);
    this->menus[MenuItem::CAR_SELECT] = std::make_unique<Sprint::GUI::CarMenu>(device, font, objs, lang, winDim, this->inMenu, nbPlayers, playersCar);
    this->menus[MenuItem::QUIT] = std::make_unique<Sprint::GUI::QuitMenu>(device, font, lang, winDim);
    this->menus[MenuItem::PAUSE] = std::make_unique<Sprint::GUI::PauseMenu>(device, font, lang, winDim, this->inMenu, this->inPause, this->quitRequest);
    this->keyMap[irr::EKEY_CODE::KEY_KEY_P] = [this]() { this->menus.at(this->curr_menu)->move(irr::EKEY_CODE::KEY_KEY_P); };
    this->keyMap[irr::EKEY_CODE::KEY_KEY_M] = [this]() { this->menus.at(this->curr_menu)->move(irr::EKEY_CODE::KEY_KEY_M); };
    this->keyMap[irr::EKEY_CODE::KEY_LEFT] = [this]() { if (this->inMenu) this->sounds.at(Sprint::Sound::Song::MENU_MOVEMENT)->play(); this->menus.at(this->curr_menu)->move(irr::EKEY_CODE::KEY_LEFT); };
    this->keyMap[irr::EKEY_CODE::KEY_RIGHT] = [this]() { if (this->inMenu) this->sounds.at(Sprint::Sound::Song::MENU_MOVEMENT)->play(); this->menus.at(this->curr_menu)->move(irr::EKEY_CODE::KEY_RIGHT); };
    this->keyMap[irr::EKEY_CODE::KEY_UP] = [this]() { if (this->inMenu || this->inPause) this->sounds.at(Sprint::Sound::Song::MENU_MOVEMENT)->play(); this->menus.at(this->curr_menu)->move(irr::EKEY_CODE::KEY_UP); };
    this->keyMap[irr::EKEY_CODE::KEY_DOWN] = [this]() { if (this->inMenu || this->inPause) this->sounds.at(Sprint::Sound::Song::MENU_MOVEMENT)->play(); this->menus.at(this->curr_menu)->move(irr::EKEY_CODE::KEY_DOWN); };
    this->keyMap[irr::EKEY_CODE::KEY_RETURN] = [this]() { if (this->inMenu || this->inPause) this->sounds.at(Sprint::Sound::Song::MENU_ENTER)->play(); if (!this->old_menu.empty() && this->old_menu.back() != this->curr_menu && this->curr_menu != Sprint::GUI::MenuItem::PAUSE) this->old_menu.push_back(this->curr_menu);
                                                            this->curr_menu = this->menus.at(this->curr_menu)->getSelected(); };
    this->keyMap[irr::EKEY_CODE::KEY_ESCAPE] = [this]() { if (this->curr_menu == Sprint::GUI::MenuItem::PAUSE) {this->curr_menu = Sprint::GUI::MenuItem::NONE; this->inPause = !this->inPause; return ;} if (!this->inMenu) { this->curr_menu = Sprint::GUI::MenuItem::PAUSE; this->inPause = false; return ;} this->menus.at(this->curr_menu)->reset();
        if (!this->old_menu.empty()) { this->curr_menu = this->old_menu.back(); this->old_menu.pop_back(); } else (this->curr_menu = Sprint::GUI::MenuItem::MAIN); };
}

void    Sprint::GUI::Menu::drawAll() const
{
    if (!this->inPause)
    {
        for (auto const &obj : this->objs)
            obj.second->getNode().setVisible(false);
    }
    this->menus.at(this->curr_menu)->render();
}

void    Sprint::GUI::Menu::move(Sprint::Input::EventReceiver &receiver)
{
	static bool states[8] = { false };
    int i = 0;

    for (auto const &keyAction : this->keyMap)
    {
        if (receiver.isPressed(keyAction.first) && !states[i])
        {
            states[i] = true;
            keyAction.second();
        }
        else if (!receiver.isPressed(keyAction.first))
            states[i] = false;
        ++i;
    }
    switch (this->curr_menu)
    {
        case (Sprint::GUI::MenuItem::QUIT) :
            this->quitRequest = true;
            break;
        case (Sprint::GUI::MenuItem::PAUSE) :
            this->inPause = true;
            break;
        default :
            break;
    }
}

void    Sprint::GUI::Menu::reset()
{
    for (auto const &menu :this->menus)
        menu.second->reset();
    this->sounds.at(Sprint::Sound::Song::MAIN_THEME)->stop();
    this->sounds.at(Sprint::Sound::Song::MAIN_THEME)->play();
    this->inMenu = true;
    this->inPause = false;
    this->old_menu.clear();
    this->curr_menu = Sprint::GUI::MenuItem::MAIN;
    this->old_menu.emplace_back(Sprint::GUI::MenuItem::MAIN);
}

bool    Sprint::GUI::Menu::isInPause() const
{
    return (this->inPause);
}

bool    Sprint::GUI::Menu::isInMenu() const
{
    return (this->inMenu);
}

void    Sprint::GUI::Menu::setInMenu(bool state)
{
    this->inMenu = state;
}

bool    Sprint::GUI::Menu::quit() const
{
    return (this->quitRequest);
}