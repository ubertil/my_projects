//
// Date.cpp for Date in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 02:11:27 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:31:29 2017 Lous-Emile Uberti-Ares
//

#include "Date.hpp"

Date::Date(bool display) :
  AModule(display, "Time :\n")
{
  _container = NULL;
  refresh();
}

Date::Date(bool display, Font &font) :
  AModule(display, "Time :\n")
{
  _container = new ContainerGUI((Pos){150, 10}, 360, 100, _title, font);
  refresh();
}

Date::Date(const Date &cpy) :
  AModule(cpy)
{
  _date = cpy.getDate();
  _uptime = cpy.getUptime();
}

Date&		Date::operator=(const Date &cpy)
{
  _date = cpy.getDate();
  _uptime = cpy.getUptime();
  _display = cpy.getDisplay();
  _title = cpy.getTitle();
  _info = cpy.getInfo();
  _container = cpy.getContainer();
  return (*this);
}

void			Date::format()
{
  std::stringstream	ss;

  ss << "\tCurrent : " << _date << std::endl
     << "\tUptime : " << _uptime << std::endl;
  _info = ss.str();
  if (_container)
    _container->setInfo(ss.str(), (Pos){2, 2});
}

int			Date::refresh()
{
  std::ifstream		file;
  std::string		tmp;
  std::stringstream	ss;
  int			idx;
  std::time_t		now = std::time(NULL);

  if (!_display)
    return (0);
  try
    {
      _date = std::ctime(&now);
      _date.erase(_date.size() - 1, _date.size());
      file.open("/proc/uptime", std::ifstream::in);
      std::getline(file, tmp);
      file.close();
      idx = std::atoi(tmp.substr(0, tmp.find(" ")).c_str()) / 3600;
      if (idx < 10)
	ss << "0" << idx << ":";
      else
	ss << idx << ":";
      idx = std::atoi(tmp.substr(0, tmp.find(" ")).c_str()) % 3600 / 60;
      if (idx < 10)
	ss << "0" << idx << ":";
      else
	ss << idx << ":";

      idx = std::atoi(tmp.substr(0, tmp.find(" ")).c_str()) % (3600) % 60;;
      if (idx < 10)
	ss << "0" << idx;
      else
	ss << idx;
      _uptime = ss.str();
      format();
    }
  catch(std::exception const &e)
    {
      std::cerr << "Module: Date: " << e.what() << std::endl;
      return (84);
    }
  return (0);
}


std::string const	&Date::getDate() const
{
  return (_date);
}

std::string const	&Date::getUptime() const
{
  return (_uptime);
}
