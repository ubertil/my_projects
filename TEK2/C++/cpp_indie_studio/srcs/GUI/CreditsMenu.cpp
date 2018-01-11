//
// Created by uberti_l on 5/29/17.
//

#include "Font/CGUITTFont.hpp"
#include "GUI/CreditsMenu.hh"

Sprint::GUI::CreditsMenu::CreditsMenu(irr::IrrlichtDevice &device, const std::string &font,
                                      Sprint::Language &lang, const irr::core::dimension2du &dim) :
        device(device), language(lang), winDim(dim), ttf(font)
{
}

Sprint::GUI::MenuItem           Sprint::GUI::CreditsMenu::getSelected()
{
    return (Sprint::GUI::MenuItem::CREDITS);
}

void                                    Sprint::GUI::CreditsMenu::render() const
{
    irr::core::dimension2d<irr::u32>    dim = this->device.getVideoDriver()->getScreenSize();
    irr::gui::CGUITTFont                *tt_font;
    unsigned int                        font_size = (dim.Width * dim.Height) / 40000;
    irr::core::ustring                  info;

    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);

    info = "Credits";
    tt_font->draw(info.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 50 - ((info.size() * font_size) / 2)), (dim.Height / 100) * (10 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    tt_font->drop();
    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size / 2);
    info = "Alexis Papadimitriou";
    tt_font->draw(info.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 50 - ((info.size() * font_size / 2) / 2)), (dim.Height / 100) * (30 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    info = "Louis-Emile Uberti-Ares";
    tt_font->draw(info.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 50 - ((info.size() * font_size / 2) / 2)), (dim.Height / 100) * (40 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    info = "Come Grellard";
    tt_font->draw(info.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 50 - ((info.size() * font_size / 2) / 2)), (dim.Height / 100) * (50 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    info = "Nicolas Trognot";
    tt_font->draw(info.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 50 - ((info.size() * font_size / 2) / 2)), (dim.Height / 100) * (60 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    info = "Nicolas Wadel";
    tt_font->draw(info.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 50 - ((info.size() * font_size / 2) / 2)), (dim.Height / 100) * (70 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    tt_font->drop();
}

void        Sprint::GUI::CreditsMenu::move(irr::EKEY_CODE key)
{

}

void        Sprint::GUI::CreditsMenu::reset()
{

}