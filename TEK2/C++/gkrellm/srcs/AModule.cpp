//
// AModule.cpp for AModule in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 23:19:02 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 06:01:06 2017 Lous-Emile Uberti-Ares
//

#include "AModule.hpp"

AModule::AModule(bool display, const std::string &title) :
  _display(display), _title(title)
{
  _container = NULL;
  _info = "UNKNOWN";
}

AModule::AModule(const AModule &cpy) :
  _display(cpy.getDisplay()), _title(cpy.getTitle()), _info(cpy.getInfo()), _container(cpy.getContainer())
{
}

AModule			&AModule::operator=(const AModule &cpy)
{
  _display = cpy.getDisplay();
  _title = cpy.getTitle();
  _info = cpy.getInfo();
  _container = cpy.getContainer();
  return (*this);
}

void			AModule::dump() const
{
  if (_display)
    std::cout << _title << _info << std::endl;
}

void			AModule::setInfo(const std::string &info)
{
  _info = info;
}

void			AModule::setTitle(const std::string &title)
{
  _title = title;
}

bool			AModule::getDisplay() const
{
  return (_display);
}

std::string const	&AModule::getInfo() const
{
  return (_info);
}

std::string const	&AModule::getTitle() const
{
  return (_title);
}

ContainerGUI		*AModule::getContainer() const
{
  return (_container);
}

void			AModule::renderNcurses() const
{
  if (_display)
    {
      attrset(A_STANDOUT);
      printw(_title.c_str());
      attrset(A_NORMAL);
      printw(_info.c_str());
      printw("\n");
    }
}
