//
// Created by uberti_l on 5/29/17.
//

#include "Font/CGUITTFont.hpp"
#include "GUI/CarMenu.hh"

Sprint::GUI::CarMenu::CarMenu(irr::IrrlichtDevice &device, const std::string &font,
                              std::unordered_map<Sprint::Game::Model, std::unique_ptr<Sprint::Game::IGameObject> > &objs,
                              Sprint::Language &lang, const irr::core::dimension2du &dim, bool &inMenu, int &nbPlayers,
                              Sprint::Game::Model playersCar[4]) :
        objs(objs), device(device), ttf(font), language(lang), winDim(dim), curr_item(0), curr_player(1),
        spaceOut(12.5), currPlayer(1), nbPlayers(nbPlayers), inMenu(inMenu), playersCar(playersCar)
{
    if (this->winDim.Width == 800)
        this->spaceOut = 7;
    this->positions.emplace_back(std::make_pair<bool, irr::core::vector3df>(true, irr::core::vector3df(80, 2, 0)));
    this->positions.emplace_back(std::make_pair<bool, irr::core::vector3df>(false, irr::core::vector3df(0, 2, 8)));
	this->positions.emplace_back(std::make_pair<bool, irr::core::vector3df>(false, irr::core::vector3df(0, 2, 0)));
	this->positions.emplace_back(std::make_pair<bool, irr::core::vector3df>(false, irr::core::vector3df(0, 2, -8)));
    this->positions.emplace_back(std::make_pair<bool, irr::core::vector3df>(false, irr::core::vector3df(-10, -10, -10)));
    this->positions.emplace_back(std::make_pair<bool, irr::core::vector3df>(false, irr::core::vector3df(-10, -10, -10)));
    this->positions.emplace_back(std::make_pair<bool, irr::core::vector3df>(false, irr::core::vector3df(-10, -10, -10)));
}

Sprint::GUI::CarMenu::~CarMenu()
{
    for (auto const &clone : this->clones)
        clone->remove();
}

Sprint::GUI::MenuItem           Sprint::GUI::CarMenu::getSelected()
{
    irr::core::vector3df        tmp;

    if (this->clones.size() == 4)
    {
        this->inMenu = false;
        this->reset();
    }
    else if (this->clones.size() != 4)
    {
        for (auto const &obj : this->objs)
        {
            tmp = obj.second->getNode().getScale();
            if (tmp == irr::core::vector3df(0.3, 0.3, 0.3) && this->playerChoice.find(obj.first) == this->playerChoice.end())
            {
                this->clones.emplace_back(obj.second->getNode().clone());
                this->clones.back()->setVisible(true);
                this->clones.back()->setScale(irr::core::vector3df(0.1, 0.1, 0.1));
                this->clones.back()->setPosition(irr::core::vector3df(-5.5, -2, this->spaceOut));
                this->clones.back()->setRotation(irr::core::vector3df(0, 270, -20));
                this->clones.back()->grab();
                if (this->currPlayer < 4)
                    this->currPlayer += 1;
                this->playerChoice[obj.first] = this->curr_player;
                this->playersCar[this->curr_player - 1] = obj.first;
                ++this->curr_player;
                if (winDim.Width == 800)
                    this->spaceOut -= 4.5;
                else
                    this->spaceOut -= (this->currPlayer == 3) ? (9.5) : (7.5);
            }
        }
    }
    return (Sprint::GUI::MenuItem::CAR_SELECT);
}

void        Sprint::GUI::CarMenu::render() const
{
    static float            idx = 0;
    std::string             player;
    int                     i = 0;
    int                     ratio = 5;
    irr::core::ustring      translated;
    irr::gui::CGUITTFont    *tt_font;
    unsigned int            font_size = (winDim.Width * winDim.Height) / 40000;
    irr::core::vector3df    selected(0.3, 0.3, 0.3);

    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);
    if (idx > 360)
        idx = 0;
    for (uint16_t num = 1; num < static_cast<uint16_t >(Sprint::Game::Model::LUIGI_CIRCUIT); ++num)
    {
        this->objs.at(static_cast<Sprint::Game::Model>(num))->getNode().setVisible(true);
        this->objs.at(static_cast<Sprint::Game::Model>(num))->getNode().setPosition(this->positions.at(i).second);
        this->objs.at(static_cast<Sprint::Game::Model>(num))->getNode().setScale(this->positions.at(i).second == irr::core::vector3df(0, 2, 0) ? selected : selected / 3);
        this->objs.at(static_cast<Sprint::Game::Model>(num))->getNode().setRotation(irr::core::vector3df(0, idx, -20));
        i++;
    }
    // Render car miniatures
    for (auto const &clone : this->clones)
        clone->render();
    // Players numbers
    i = 1;
    while (i <= 4)
    {
        player = "P";
        tt_font->draw(((i > this->nbPlayers) ? ("IA") : (player.append(std::to_string(i)).c_str())),
                      irr::core::rect<irr::s32>((winDim.Width / 100 * ratio), (winDim.Height / 100) * (90 + (font_size / 10) + 1), 200, 200),
                      (i == this->currPlayer) ? (irr::video::SColor(255, 255, 0, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
        ratio += (i == 1) ? (25) : (30);
        i++;
    }
    if (this->clones.size() == 4)
    {
        translated = this->language.getTranslation("Ready");
        tt_font->draw(translated.c_str(),
                      irr::core::rect<irr::s32>((winDim.Width / 100 * 50) - ((translated.size() * font_size) / 2), (winDim.Height / 100) * (45 + (font_size / 10) + 1), 200, 200),
                      irr::video::SColor(255, 255, 0, 0), false, false);
    }
    tt_font->drop();
    idx += 0.5;
}

void        Sprint::GUI::CarMenu::move(irr::EKEY_CODE key)
{
    switch (key)
    {
        case (irr::EKEY_CODE::KEY_RIGHT) :
            this->positions.front().first = false;
            this->positions.push_front(std::make_pair<bool, irr::core::vector3df>(std::move(true), std::move(this->positions.back().second)));
            this->positions.pop_back();
            break;
        case (irr::EKEY_CODE::KEY_LEFT) :
            this->positions.push_back(std::make_pair<bool, irr::core::vector3df>(std::move(false), std::move(this->positions.front().second)));
            this->positions.pop_front();
            this->positions.front().first = true;
            break;
        case (irr::EKEY_CODE::KEY_KEY_P) :
#ifdef _WIN32
            this->nbPlayers += (this->nbPlayers == 4) ? (0) : (1);
#else
            this->nbPlayers += (this->nbPlayers == 3) ? (0) : (1);
#endif
            break;
        case (irr::EKEY_CODE::KEY_KEY_M) :
            this->nbPlayers -= (this->nbPlayers == 1) ? (0) : (1);
        default :
            break;
    }
}

void        Sprint::GUI::CarMenu::reset()
{
    for (auto const &clone : this->clones)
        clone->remove();
    this->curr_player = 1;
    if (this->inMenu)
        this->nbPlayers = 1;
    this->clones.clear();
    this->playerChoice.clear();
    this->spaceOut = ((this->winDim.Width == 800) ? (7) : (12.5));
    this->currPlayer = 1;
}