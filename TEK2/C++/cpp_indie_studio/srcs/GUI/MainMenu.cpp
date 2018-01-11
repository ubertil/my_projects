//
// Created by uberti_l on 5/29/17.
//

#include "Font/CGUITTFont.hpp"
#include "Font/CStringTable.hpp"
#include "GUI/MainMenu.hh"
#include "GUI/Menu.hh"

Sprint::GUI::MainMenu::MainMenu(irr::IrrlichtDevice &device, const std::string &font,
                                irr::scene::IAnimatedMeshSceneNode &marioKart, Sprint::Language &lang, const irr::core::dimension2du &dim) :
    marioKart(marioKart), device(device), ttf(font), winDim(dim), language(lang), curr_item(3), max_item(3)
{
    Sprint::Utils::Dir          dir("../resources/misc/menu/box");
    std::vector<std::string>    files = dir.getFiles(1, "*.png");

    if (files.size() != 1)
        throw Sprint::Error::GameError("Error while loading file");
    this->textPack.emplace_back("Quit");
    this->textPack.emplace_back("Credits");
    this->textPack.emplace_back("Options");
    this->textPack.emplace_back("Quickgame");
}

Sprint::GUI::MainMenu::~MainMenu()
{
}

Sprint::GUI::MenuItem       Sprint::GUI::MainMenu::getSelected()
{
    Sprint::GUI::MenuItem   ret;

    switch (this->curr_item)
    {
        case (0) :
            ret = Sprint::GUI::MenuItem::QUIT;
            break;
        case (1) :
            ret = Sprint::GUI::MenuItem::CREDITS;
            break;
        case (2) :
            ret = Sprint::GUI::MenuItem::OPTIONS;
            break;
        case (3) :
            ret = Sprint::GUI::MenuItem::CAR_SELECT;
            break;
        default:
            ret = Sprint::GUI::MenuItem::NONE;
            break;

    }
    this->reset();
    return (ret);
}

void                                    Sprint::GUI::MainMenu::render() const
{
    static float                        idx = 0;
    irr::core::dimension2d<irr::u32>    dim = this->device.getVideoDriver()->getScreenSize();
    irr::gui::CGUITTFont                *tt_font;
    int                                 ratio = 105;
    unsigned int                        i = 0;
    unsigned int                        font_size = (dim.Width * dim.Height) / 40000;

    if (idx > 360)
        idx = 0;
    if (font_size > 30)
        font_size = 30;
    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);
    this->device.getGUIEnvironment()->getSkin()->setFont(tt_font);
    for (const std::string &text : this->textPack)
    {
        const irr::core::ustring translated = this->language.getTranslation(text.c_str());
        ratio -= 20;
        tt_font->draw(translated.c_str(),
                      irr::core::rect<irr::s32>(((dim.Width / 100) * 5) - (translated.size() / 10), (dim.Height / 100) * (ratio - (font_size / 10) + 1), 200, 200),
                      (i == this->curr_item) ? (irr::video::SColor(255, 0, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
        i += 1;
    }
    idx += 0.5;
    this->marioKart.setVisible(true);
    this->marioKart.setScale(irr::core::vector3df(0.4, 0.4, 0.4));
    this->marioKart.setPosition(irr::core::vector3df(0, -5, -4));
    this->marioKart.setRotation(irr::core::vector3df(0, idx, -20));
    tt_font->drop();
}

void    Sprint::GUI::MainMenu::reset()
{
    this->curr_item = this->max_item;
}

void    Sprint::GUI::MainMenu::move(irr::EKEY_CODE key)
{
    switch (key)
    {
        case (irr::EKEY_CODE::KEY_DOWN) :
            this->curr_item = (this->curr_item == 0) ? (this->curr_item) : (this->curr_item - 1);
            break;
        case (irr::EKEY_CODE::KEY_UP) :
            this->curr_item = (this->curr_item == this->max_item) ? (this->curr_item) : (this->curr_item + 1);
            break;
        default :
            break;
    }
}