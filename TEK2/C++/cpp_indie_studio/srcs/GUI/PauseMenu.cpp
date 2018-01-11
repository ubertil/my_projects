//
// Created by uberti_l on 6/17/17.
//

#include "Font/CGUITTFont.hpp"
#include "GUI/PauseMenu.hh"

Sprint::GUI::PauseMenu::PauseMenu(irr::IrrlichtDevice &device, const std::string &font,
                                Sprint::Language &lang, const irr::core::dimension2du &dim, bool &inMenu, bool &inPause, bool &quitRequest) :
        device(device), ttf(font), language(lang), winDim(dim), curr_item(2), inMenu(inMenu), inPause(inPause), quitRequest(quitRequest)
{
    this->textPack.emplace_back("Pause");
    this->textPack.emplace_back("Resume");
    this->textPack.emplace_back("Back");
    this->textPack.emplace_back("Quit");
}

Sprint::GUI::MenuItem           Sprint::GUI::PauseMenu::getSelected()
{
    switch (this->curr_item)
    {
        case (2) :
            this->inMenu = false;
            this->inPause = false;
            this->reset();
            return (Sprint::GUI::MenuItem::NONE);
        case (3) :
            this->inMenu = true;
            this->inPause = false;
            this->reset();
            return (Sprint::GUI::MenuItem::MAIN);
        case (4) :
            this->inPause = false;
            this->quitRequest = true;
            break;
        default :
            break;
    }
    return (Sprint::GUI::MenuItem::PAUSE);
}

void        Sprint::GUI::PauseMenu::render() const
{
    irr::gui::CGUITTFont    *tt_font;
    irr::core::ustring      translated;
    int                     ratio = 20;
    int                     i = 1;
    unsigned int            font_size = (winDim.Width * winDim.Height) / 40000;

    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);
    for (const std::string &text : this->textPack)
    {
        translated = this->language.getTranslation(text);
        tt_font->draw(translated.c_str(),
                      irr::core::rect<irr::s32>((winDim.Width / 100 * 50) - ((translated.size() * font_size) / 2), (winDim.Height / 100) * (ratio + (font_size / 10) + 1), 200, 200),
                      (i == this->curr_item) ? (irr::video::SColor(255, 255, 0, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
        ++i;
        ratio += 20;
    }
    tt_font->drop();
}

void        Sprint::GUI::PauseMenu::move(irr::EKEY_CODE key)
{
    switch (key)
    {
        case (irr::EKEY_CODE::KEY_UP) :
            this->curr_item -= (this->curr_item == 2) ? (0) : (1);
            break;
        case (irr::EKEY_CODE::KEY_DOWN) :
            this->curr_item += (this->curr_item == 4) ? (0) : (1);
            break;
        default :
            break;
    }
}

void        Sprint::GUI::PauseMenu::reset()
{
    this->curr_item = 2;
}