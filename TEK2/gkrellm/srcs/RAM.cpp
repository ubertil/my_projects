//
// RAM.cpp for RAM in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 03:10:11 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:54:27 2017 Lous-Emile Uberti-Ares
//

#include <cmath>
#include <cstdlib>
#include <fstream>
#include "RAM.hpp"
#include "GraphContainerGUI.hpp"

RAM::RAM(bool display) :
  AModule(display, "RAM Monitor :\n")
{
  _container = NULL;
  refresh();
}

RAM::RAM(bool display, Font &font) :
  AModule(display, "RAM Monitor :\n")
{
  _container = new GraphContainerGUI((Pos){10, 400}, 750, 400, _title, font, 0);
  refresh();
}

RAM::RAM(const RAM &cpy) :
  AModule(cpy)
{
  _ram = cpy.getRAM();
}

RAM&		RAM::operator=(const RAM &cpy)
{
  _ram = cpy.getRAM();
  _display = cpy.getDisplay();
  _title = cpy.getTitle();
  _info = cpy.getInfo();
  _container = cpy.getContainer();
  return (*this);
}

void			RAM::format()
{
  if (!_ram.empty())
    {
      _info = "";
      _info += "\tMem  ";
      _info += showBar(100.0 * (_ram.at(1) - _ram.at(0)) / _ram.at(1),
		       (_ram.at(1) - _ram.at(0)), _ram.at(1));
      _info += "\tSwap ";
      _info += showBar(100.0 * _ram.at(2) / _ram.at(3), _ram.at(2),_ram.at(3));
      if (_container)
	{
	  _container->setInfo(_info.c_str(), (Pos){2, 2});
	  static_cast<GraphContainerGUI *>(_container)->setMax(_ram.at(1));
	  static_cast<GraphContainerGUI *>(_container)->pushData(_ram.at(1) - _ram.at(0));
	}
    }
}

int				RAM::refresh()
{
  std::string			line;
  std::ifstream			file;
  double			tmp;

  if (!_display)
    return (0);
  try
    {
      _ram.clear();
      file.open("/proc/meminfo", std::ifstream::in);
      while (file.good())
	{
	  std::getline(file, line);
	  if (line.substr(0, line.find(":")).compare("MemFree") == 0)
	    {
	      tmp = std::atof(line.substr(line.find(":") + 1, line.size() - 3).c_str())
		/ pow(1024, 2);
	      _ram[0] = tmp;
	    }
	  if (line.substr(0, line.find(":")).compare("MemTotal") == 0)
	    {
	      tmp = std::atof(line.substr(line.find(":") + 1, line.size() - 3).c_str())
		/ pow(1024, 2);
	      _ram[1] = tmp;
	    }
	  if (line.substr(0, line.find(":")).compare("SwapFree") == 0)
	    {
	      tmp = std::atof(line.substr(line.find(":") + 1, line.size() - 3).c_str())
		/ pow(1024, 2);
	      _ram[2] = _ram[3] - tmp;
	    }
	  if (line.substr(0, line.find(":")).compare("SwapTotal") == 0)
	    {
	      tmp = std::atof(line.substr(line.find(":") + 1, line.size() - 3).c_str())
		/ pow(1024, 2);
	      _ram[3] = tmp;
	    }
	}
      file.close();
      format();
    }
  catch(std::exception const &e)
    {
      std::cerr << "Module: RAM: " << e.what() << std::endl;
      return (84);
    }
  return (0);
}

std::map<int, double> const	&RAM::getRAM() const
{
  return (_ram);
}

std::string const		RAM::showBar(double progress, double usage, double total) const
{
  int barWidth = 40;
  int pos = barWidth * (progress / 100);
  std::stringstream		ss;

  ss << "[";
  for (int i = 0; i < barWidth; ++i)
    {
      if (i < pos)
	ss << "=";
      else
	ss << " ";
    }
  ss << "] " << std::setprecision(3) << usage << "G/"
     << total << "G" << std::endl;
  return (ss.str());
}
