//
// CPU.cpp for CPU in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:02:28 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:28:57 2017 Lous-Emile Uberti-Ares
//

#include <thread>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include "CPU.hpp"
#include "GraphContainerGUI.hpp"

CPU::CPU(bool display) :
  AModule(display, "CPU Monitor :\n")
{
  _container = NULL;
  refresh();
}

CPU::CPU(bool display, Font &font) :
  AModule(display, "CPU Monitor :\n")
{
  _container = new GraphContainerGUI((Pos){1200, 10}, 700, 400, _title, font, 100);
  refresh();
}

CPU::CPU(const CPU &cpy) :
  AModule(cpy)
{
  _cores = cpy.getCores();
  _cpu = cpy.getCPU();
  _loadavg = cpy.getLoad();
  _usage = cpy._usage;
  _nb = cpy.getNB();
}

CPU&			CPU::operator=(const CPU &cpy)
{
  _cores = cpy.getCores();
  _cpu = cpy.getCPU();
  _loadavg = cpy.getLoad();
  _usage = cpy._usage;
  _nb = cpy.getNB();
  _container = cpy.getContainer();
  _display = cpy.getDisplay();
  _title = cpy.getTitle();
  _info = cpy.getInfo();
  return (*this);
}

int			CPU::refresh()
{
  std::ifstream		file;
  std::string		line;

  if (!_display)
    return (0);
  try
    {
      _nb = 0;
      file.open("/proc/loadavg", std::ifstream::in);
      std::getline(file, _loadavg);
      _loadavg = _loadavg.substr(0, 15);
      file.close();
      file.open("/proc/cpuinfo", std::ifstream::in);
      while (file.good())
	{
	  std::getline(file, line);
	  if (line.substr(0, line.find(":")).compare("model name\t") == 0)
	    _cpu = line.substr(line.find(":"), line.size());
	}
      file.close();
      file.open("/proc/cpuinfo", std::ifstream::in);
      _cores.clear();
      while (file.good())
	{
	  std::getline(file, line);
	  if (line.substr(0, line.find(":") + 1).compare("cpu MHz\t\t:") == 0)
	    {
	      _cores.push_back(atof(line.substr(line.find(":") + 1, line.size()).c_str()));
	      ++_nb;
	    }
	}
      file.close();
      getUsage();
      format();
    }
  catch(std::exception const &e)
    {
      std::cerr << "Module: CPU: " << e.what() << std::endl;
    }
  return (0);
}

void			CPU::getUsage()
{
  std::string		tmp;
  std::ifstream		file;
  long double		a[_nb][4];
  long double		b[_nb][4];
  int			i = 0;

  file.open("/proc/stat");
  std::getline(file, tmp);
  _usage.clear();
  while (i < 4)
    {
      std::getline(file, tmp);
      tmp = tmp.substr(tmp.find(" "),  tmp.size());
      a[i][0] = std::atoi(tmp.substr(tmp.find(" "),  tmp.size()).c_str());
      tmp = tmp.substr(tmp.find(" ") + 1, tmp.size());
      a[i][1] = std::atoi(tmp.substr(tmp.find(" "),  tmp.size()).c_str());
      tmp = tmp.substr(tmp.find(" ") + 1,  tmp.size());
      a[i][2] = std::atoi(tmp.substr(tmp.find(" "),  tmp.size()).c_str());
      tmp = tmp.substr(tmp.find(" ") + 1, tmp.size());
      a[i][3] = std::atoi(tmp.substr(tmp.find(" "), tmp.size()).c_str());
      ++i;
    }
  i = 0;
  file.close();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  file.open("/proc/stat");
  std::getline(file, tmp);
  while (i < 4)
    {
      std::getline(file, tmp);
      tmp = tmp.substr(tmp.find(" "), tmp.size());
      b[i][0] = std::atoi(tmp.substr(tmp.find(" "), tmp.size()).c_str());
      tmp = tmp.substr(tmp.find(" ") + 1, tmp.size());
      b[i][1] = std::atoi(tmp.substr(tmp.find(" "),  tmp.size()).c_str());
      tmp = tmp.substr(tmp.find(" ") + 1, tmp.size());
      b[i][2] = std::atoi(tmp.substr(tmp.find(" "),  tmp.size()).c_str());
      tmp = tmp.substr(tmp.find(" ") + 1, tmp.size());
      b[i][3] = std::atoi(tmp.substr(tmp.find(" "),  tmp.size()).c_str());
      _usage[i] = (((b[i][0]+b[i][1]+b[i][2]) - (a[i][0]+a[i][1]+a[i][2])) /
		    ((b[i][0]+b[i][1]+b[i][2]+b[i][3]) - (a[i][0]+a[i][1]+a[i][2]+a[i][3])))
	* 100;
      ++i;
    }
}

void			CPU::format()
{
  std::stringstream	ss;
  unsigned int		i = 1;

  ss << "\tModel : " << _cpu << std::endl;
  for (std::vector<double>::iterator it = _cores.begin(); it != _cores.end(); ++it)
    {
      ss << "\tCPU" << i << " : " << *it << " MHz" << " ("
	 << _usage.at(i - 1) << "%)" << std::endl;
      ++i;
    }
  ss << "\tLoad average: " << _loadavg << std::endl;
  _info = ss.str();
  if (_container)
    {
      _container->setInfo(ss.str(), (Pos){2, 2});
      static_cast<GraphContainerGUI *>(_container)->pushData(_usage.at(0));
    }
}

std::string const	&CPU::getCPU() const
{
  return (_cpu);
}

std::string const	&CPU::getLoad() const
{
  return (_loadavg);
}

std::vector<double> const	&CPU::getCores() const
{
  return (_cores);
}

int				CPU::getNB() const
{
  return (_nb);
}
