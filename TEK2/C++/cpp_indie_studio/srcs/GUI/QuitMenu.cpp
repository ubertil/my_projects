//
// Created by uberti_l on 5/29/17.
//

#include "GUI/QuitMenu.hh"

Sprint::GUI::QuitMenu::QuitMenu(irr::IrrlichtDevice &device, const std::string &font,
                                Sprint::Language &lang, const irr::core::dimension2du &dim) :
        device(device), ttf(font), language(lang), winDim(dim)
{

}

Sprint::GUI::MenuItem           Sprint::GUI::QuitMenu::getSelected()
{
    return (Sprint::GUI::MenuItem::CAR_SELECT);
}

void        Sprint::GUI::QuitMenu::render() const
{
}

void        Sprint::GUI::QuitMenu::move(irr::EKEY_CODE key)
{

}

void        Sprint::GUI::QuitMenu::reset()
{

}