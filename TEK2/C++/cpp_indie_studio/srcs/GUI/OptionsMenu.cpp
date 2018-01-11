//
// Created by uberti_l on 5/29/17.
//

#include "Font/CGUITTFont.hpp"
#include "Font/CStringTable.hpp"
#include "GUI/OptionsMenu.hh"

Sprint::GUI::OptionsMenu::OptionsMenu(irr::IrrlichtDevice &device, const std::string &font,
                                      Sprint::Utils::IniManager &manager, Sprint::Language &lang, const irr::core::dimension2du &dim) :
    manager(manager), device(device), ttf(font), language(lang), winDim(dim), curr_item(11), max_item(11), volume(manager.getData<float>("settings", "volume", 0))
{
    this->resetConf();
}

Sprint::GUI::MenuItem           Sprint::GUI::OptionsMenu::getSelected()
{
    switch (this->curr_item)
    {
        case select::BACK:
            return Sprint::GUI::MenuItem::MAIN;
        case select::SAVE:
            this->saveConfig();
            return Sprint::GUI::MenuItem::MAIN;
        case select::RES_SMALL:
            this->config.at("res") = select::RES_SMALL;
            break;
        case select::RES_MEDIUM:
            this->config.at("res") = select::RES_MEDIUM;
            break;
        case select::RES_LARGE:
            this->config.at("res") = select::RES_LARGE;
            break;
        case select::FULLSCREEN_ENABLED:
            this->config.at("scr") = select::FULLSCREEN_ENABLED;
            break;
        case select::FULLSCREEN_DISABLED:
            this->config.at("scr") = select::FULLSCREEN_DISABLED;
            break;
        case select::VSYNC_ENABLED:
            this->config.at("vsync") = select::VSYNC_ENABLED;
            break;
        case select::VSYNC_DISABLED:
            this->config.at("vsync") = select::VSYNC_DISABLED;
            break;
        case select::LANG_FR:
            this->config.at("lang") = select::LANG_FR;
            break;
        case select::LANG_EN:
            this->config.at("lang") = select::LANG_EN;
            break;
    }
    return Sprint::GUI::MenuItem::OPTIONS;
}

void                                    Sprint::GUI::OptionsMenu::render() const
{
    std::vector<std::string>            languages = this->language.getAvailableLanguages();
    irr::core::dimension2d<irr::u32>    dim = this->device.getVideoDriver()->getScreenSize();
    irr::gui::CGUITTFont                *tt_font;
    unsigned int                        font_size = (this->winDim.Width == 800) ? ((dim.Width * dim.Height) / 50000) : ((dim.Width * dim.Height) / 40000);
    irr::core::ustring                  translated;

    if (font_size > 20)
        font_size = 20;
    tt_font = irr::gui::CGUITTFont::createTTFont(this->device.getGUIEnvironment(), this->ttf.c_str(), font_size);
    this->device.getGUIEnvironment()->getSkin()->setFont(tt_font);
    translated = this->language.getTranslation("Back");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 5) - (translated.size() / 10), (dim.Height / 100) * (45 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::BACK) ? (irr::video::SColor(255, 0, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    translated = this->language.getTranslation("Save");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 5) - (translated.size() / 10), (dim.Height / 100) * (60 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::SAVE) ? (irr::video::SColor(255, 0, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    for (auto const &conf : this->config)
        if (conf.second != select::NONE)
        {
            translated = this->language.getTranslation("Restart");
            tt_font->draw(translated.c_str(),
                          irr::core::rect<irr::s32>(((dim.Width / 100) * 5) - (translated.size() / 10), (dim.Height / 100) * (80 - (font_size / 10) + 1), 200, 200),
                          irr::video::SColor(255, 255, 0, 0), false, false);
        }

    // Resolution
    translated = this->language.getTranslation("Resolution");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 60) - (translated.size() / 10), (dim.Height / 100) * ((font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    tt_font->draw("800x800",
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 40), (dim.Height / 100) * (10 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::RES_SMALL) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("res") == select::RES_SMALL) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    tt_font->draw("1620x720",
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 60), (dim.Height / 100) * (10 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::RES_MEDIUM) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("res") == select::RES_MEDIUM) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    tt_font->draw("1920x1080",
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 80), (dim.Height / 100) * (10 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::RES_LARGE) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("res") == select::RES_LARGE) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);

    // Fullscreen
    translated = this->language.getTranslation("Fullscreen");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 60) - (translated.size() / 10), (dim.Height / 100) * (20 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    tt_font->draw(this->language.getTranslation("Yes").c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 40) - (translated.size() / 10), (dim.Height / 100) * (25 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item  == select::FULLSCREEN_ENABLED) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("scr") == select::FULLSCREEN_ENABLED) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    tt_font->draw(this->language.getTranslation("No").c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 80) - (translated.size() / 10), (dim.Height / 100) * (25 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::FULLSCREEN_DISABLED) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("scr") == select::FULLSCREEN_DISABLED) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);

    // Vsync
    translated = this->language.getTranslation("Vsync");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 60) - (translated.size() / 10), (dim.Height / 100) * (40 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    tt_font->draw(this->language.getTranslation("Yes").c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 40) - (translated.size() / 10), (dim.Height / 100) * (45 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::VSYNC_ENABLED) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("vsync") == select::VSYNC_ENABLED) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    tt_font->draw(this->language.getTranslation("No").c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 80) - (translated.size() / 10), (dim.Height / 100) * (45 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::VSYNC_DISABLED) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("vsync") == select::VSYNC_DISABLED) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);

    // Volume
    translated = this->language.getTranslation("Volume");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 60) - (translated.size() / 10), (dim.Height / 100) * (60 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);

    for (float vol = 0; vol <= this->volume * 4; vol += 0.01)
    {
        tt_font->draw("|", irr::core::rect<irr::s32>(((dim.Width / 100) * 50) + (vol * 100 + 6), (dim.Height / 100) * (65 - (font_size / 10) + 1), 200, 200),
                      (this->curr_item == select::VOLUME) ? (irr::video::SColor(255, 0, 255, 0)) :
                      (this->config.at("vol") == select::VOLUME) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    }

    // Languages
    translated = this->language.getTranslation("Language");
    tt_font->draw(translated.c_str(),
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 60) - (translated.size() / 10), (dim.Height / 100) * (80 - (font_size / 10) + 1), 200, 200),
                  irr::video::SColor(255, 255, 255, 255), false, false);
    tt_font->draw("Francais",
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 40) - (translated.size() / 10), (dim.Height / 100) * (85 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::LANG_FR) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("lang") == select::LANG_FR) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    tt_font->draw("English",
                  irr::core::rect<irr::s32>(((dim.Width / 100) * 80) - (translated.size() / 10), (dim.Height / 100) * (85 - (font_size / 10) + 1), 200, 200),
                  (this->curr_item == select::LANG_EN) ? (irr::video::SColor(255, 0, 255, 0)) :
                  (this->config.at("lang") == select::LANG_EN) ? (irr::video::SColor(255, 255, 255, 0)) : (irr::video::SColor(255, 255, 255, 255)), false, false);
    tt_font->drop();
}

void        Sprint::GUI::OptionsMenu::move(irr::EKEY_CODE key)
{
    switch (key)
    {
        case irr::EKEY_CODE::KEY_DOWN :
            this->curr_item = (this->curr_item == 0) ? (this->curr_item) : (this->curr_item - 1);
            break;
        case irr::EKEY_CODE::KEY_UP :
            this->curr_item = (this->curr_item == this->max_item) ? (this->curr_item) : (this->curr_item + 1);
            break;
        case irr::EKEY_CODE::KEY_LEFT:
            if (this->curr_item == select::VOLUME)
            {
                this->config.at("vol") = select::VOLUME;
                this->volume -= 0.05;
                if (this->volume < 0)
                    this->volume = 0;
            }
            break;
        case irr::EKEY_CODE::KEY_RIGHT:
            if (this->curr_item == select::VOLUME)
            {
                this->config.at("vol") = select::VOLUME;
                this->volume += 0.05;
                if (this->volume > 1)
                    this->volume = 1;
            }
            break;
        default :
            break;
    }
}

void        Sprint::GUI::OptionsMenu::reset()
{

}

void        Sprint::GUI::OptionsMenu::resetConf()
{
    this->config["res"] = select::NONE;
    this->config["scr"] = select::NONE;
    this->config["vsync"] = select::NONE;
    this->config["vol"] = select::NONE;
    this->config["lang"] = select::NONE;
}

void        Sprint::GUI::OptionsMenu::saveConfig()
{
    this->saveResolution();
    this->saveScreenMode();
    this->saveVSyncMode();
    this->saveVolume();
    this->saveLang();
    this->manager.save();
    this->resetConf();
}

void                            Sprint::GUI::OptionsMenu::saveResolution()
{
    switch (this->config.at("res"))
    {
        case select::NONE:
            return ;
        case select::RES_SMALL:
            this->manager.resetData("window", "width", "800");
            this->manager.resetData("window", "height", "800");
            break;
        case select::RES_MEDIUM:
            this->manager.resetData("window", "width", "1620");
            this->manager.resetData("window", "height", "720");
            break;
        case select::RES_LARGE:
            this->manager.resetData("window", "width", "1920");
            this->manager.resetData("window", "height", "1080");
            break;
    }
}

void                            Sprint::GUI::OptionsMenu::saveScreenMode()
{
    switch (this->config.at("scr"))
    {
        case select::NONE:
            return ;
        case select::FULLSCREEN_ENABLED:
            this->manager.resetData("window", "fullscreen", "1");
            break;
        case select::FULLSCREEN_DISABLED:
            this->manager.resetData("window", "fullscreen", "0");
            break;
    }
}

void                            Sprint::GUI::OptionsMenu::saveVSyncMode()
{
    switch (this->config.at("vsync"))
    {
        case select::NONE:
            return ;
        case select::VSYNC_ENABLED:
            this->manager.resetData("window", "vsync", "1");
            break;
        case select::VSYNC_DISABLED:
            this->manager.resetData("window", "vsync", "0");
            break;
    }
}

void                            Sprint::GUI::OptionsMenu::saveVolume()
{
    switch (this->config.at("vol"))
    {
        case select::NONE:
            return ;
        default :
            this->manager.resetData("settings", "volume", std::to_string(this->volume));
            break;
    }
}

void                            Sprint::GUI::OptionsMenu::saveLang()
{
    switch (this->config.at("lang"))
    {
        case select::NONE:
            return ;
        case select::LANG_FR:
            this->manager.resetData("settings", "language", "Francais");
            this->language.setCurrentLanguage("Francais");
            break;
        case select::LANG_EN:
            this->manager.resetData("settings", "language", "English");
            this->language.setCurrentLanguage("English");
            break;
    }
}