//
// Created by uberti_l on 6/16/17.
//

#include <thread>
#include "Irrlicht/irrlicht.h"
#include "Font/CGUITTFont.hpp"
#include "GUI/ATH.hh"

Sprint::GUI::ATH::ATH(irr::IrrlichtDevice &device, Sprint::Language &lang, const std::string &font) :
        device(device), language(lang), ttf(font)
{
}

void                                        Sprint::GUI::ATH::displayATH(const int nbLap, const int max, const float carSpeed) const
{
    irr::gui::CGUITTFont                    *tt_font;
    const irr::core::dimension2d<irr::u32>  winDim = this->device.getVideoDriver()->getScreenSize();
    irr::core::ustring                      translated;
    unsigned int                            font_size = 20;

    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);
    translated = this->language.getTranslation("Lap");
    translated.append(std::to_wstring((nbLap < 0) ? (0) : (nbLap)));
    translated.append(" / ");
    translated.append(std::to_wstring(max));
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((winDim.Width / 100) * 85) - ((translated.size() * font_size) / 2), (winDim.Height / 100) * ((font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 0, 0), false, false);
    tt_font->draw(std::to_string(static_cast<int>(carSpeed + 1)).c_str(),
                  irr::core::rect<irr::s32>(((winDim.Width / 100) * 85) - ((2 * font_size) / 2), ((winDim.Height / 100) * 90) - (font_size / 2), 200, 200),
                  irr::video::SColor(255, 255, 0, 0), false, false);
    tt_font->drop();
}

void                                        Sprint::GUI::ATH::displayRanking(Sprint::Game::Model playerOne, const int nbPlayers,
                                                                             const std::vector<std::pair<Sprint::Game::Model, int>> &ranks) const
{
    irr::gui::CGUITTFont                    *tt_font;
    int                                     i = 0;
    int                                     pos = 4;
    int                                     ratio = 5;
    const irr::core::dimension2d<irr::u32>  winDim = this->device.getVideoDriver()->getScreenSize();
    irr::core::ustring                      translated;
    unsigned int                            font_size = 20;

    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);
    // Ranking
    translated = this->language.getTranslation("Ranking");
    for (auto const &rank : ranks)
    {
        if (nbPlayers != 1)
            tt_font->draw(Sprint::Game::ModelName[static_cast<int>(rank.first)].c_str(),
                          irr::core::rect<irr::s32>(((winDim.Width / 100) * 12) - ((translated.size() * font_size) / 2), (winDim.Height / 100) * (ratio * (font_size / 10) + 1), 200, 200),
                          irr::video::SColor(255, 255, 0, 0), false, false);
        if (rank.first == playerOne)
            pos = i + 1;
        ratio += 5;
        ++i;
    }
    if (nbPlayers == 1)
        translated.append(std::to_wstring(pos)).append(" / 4");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((winDim.Width / 100) * 12) - ((translated.size() * font_size) / 2), (winDim.Height / 100) * ((font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 0, 0), false, false);
    tt_font->drop();
}

void                                        Sprint::GUI::ATH::displayStart(irr::IrrlichtDevice *device) const
{
    irr::gui::CGUITTFont                    *tt_font;
    int                                     i = 3;
    const irr::core::dimension2d<irr::u32>  winDim = this->device.getVideoDriver()->getScreenSize();
    unsigned int                            font_size = 20;

    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);
    while (i != 0)
    {
        device->getVideoDriver()->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        device->getSceneManager()->drawAll();
        tt_font->draw(std::to_string(i).c_str(),
                      irr::core::rect<irr::s32>(((winDim.Width / 100) * 50) - (font_size / 2), ((winDim.Height / 100) * 50) - (font_size / 2), 200, 200),
                      irr::video::SColor(255, 255, 0, 0), false, false);
        device->getVideoDriver()->endScene();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        i--;
    }
    tt_font->drop();
}