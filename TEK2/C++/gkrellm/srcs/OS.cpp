//
// OS.cpp for OS in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 02:18:51 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:42:21 2017 Lous-Emile Uberti-Ares
//

#include <fstream>
#include "OS.hpp"

OS::OS(bool display) :
  AModule(display, "Operating System Informations :\n")
{
  _container = NULL;
  refresh();
}

OS::OS(bool display, Font &font) :
  AModule(display, "Operating System Informations :\n")
{
  _container = new ContainerGUI((Pos){500, 150}, 600, 200, _title, font);
  refresh();
}

OS::OS(const OS &cpy) :
  AModule(cpy)
{
  _os = cpy.getOS();
  _kernel = cpy.getKernel();
}

OS&		OS::operator=(const OS &cpy)
{
  _os = cpy.getOS();
  _kernel = cpy.getKernel();
  _display = cpy.getDisplay();
  _container = cpy.getContainer();
  _title = cpy.getTitle();
  _info = cpy.getInfo();
  return (*this);
}

void			OS::format()
{
  std::stringstream	ss;

  ss << "\tOperating System : " << _os << std::endl
     << "\tKernel : " << _kernel << std::endl;
  setInfo(ss.str());
  if (_container)
    _container->setInfo(ss.str(), (Pos){2, 2});
}

int		OS::refresh()
{
  std::ifstream	file;

  if (!_display)
    return (0);
  try
    {
      file.open("/proc/sys/kernel/version", std::ifstream::in);
      std::getline(file, _kernel);
      file.close();
      file.open("/proc/sys/kernel/ostype", std::ifstream::in);
      std::getline(file, _os);
      file.close();
      format();
    }
  catch(std::exception const &e)
    {
      std::cerr << "Module: OS: " << e.what() << std::endl;
      return (84);
    }
  return (0);
}

std::string const	&OS::getOS() const
{
  return (_os);
}

std::string const	&OS::getKernel() const
{
  return (_kernel);
}
