//
// ComputerInfo.cpp for ComputerInfo in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:57:08 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 07:21:54 2017 Lous-Emile Uberti-Ares
//

#include "ComputerInfo.hpp"

ComputerInfo::ComputerInfo(bool display) :
  AModule(display, "Computer's Informations :\n")
{
  _container = NULL;
  refresh();
}

ComputerInfo::ComputerInfo(bool display, Font &font) :
  AModule(display, "Computer's Informations :\n")
{
  _container = new ContainerGUI((Pos){10, 200}, 400, 100, this->_title, font);
  refresh();
}

ComputerInfo::ComputerInfo(const ComputerInfo &cpy) :
  AModule(cpy)
{
  _hostName = cpy.getHostName();
  _userName = cpy.getUserName();
}

ComputerInfo&		ComputerInfo::operator=(const ComputerInfo &cpy)
{
  _hostName = cpy.getHostName();
  _userName = cpy.getUserName();
  _display = cpy.getDisplay();
  _title = cpy.getTitle();
  _info = cpy.getInfo();
  return (*this);
}

int			ComputerInfo::refresh()
{
  if (!_display)
    return (0);
  _userName = ((std::getenv("USER") != NULL) ? (std::getenv("USER")) : ("Unknown"));
  _hostName = ((std::getenv("HOSTNAME") != NULL) ? (std::getenv("HOSTNAME")) : ("Unknown"));
  format();
  return (0);
}

void			ComputerInfo::format()
{
  std::stringstream	ss;

  ss  << "\tComputer's name : " << _hostName << std::endl << "\tCurrent user : "
      << _userName << std::endl;
  setInfo(ss.str());
  if (_container)
    _container->setInfo(ss.str(), (Pos){2, 2});
}

std::string const	&ComputerInfo::getUserName() const
{
  return (_userName);
}

std::string const	&ComputerInfo::getHostName() const
{
  return (_hostName);
}
