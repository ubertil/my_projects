//
// Network.cpp for Network in /home/grella_f/piscine_c++/cpp_gkrellm/srcs
//
// Made by félix grellard
// Login   <grella_f@epitech.net>
//
// Started on  Sat Jan 21 10:02:06 2017 félix grellard
// Last update Sun Jan 22 05:52:50 2017 Lous-Emile Uberti-Ares

#include <fstream>
#include <cstdlib>
#include "Network.hpp"
#include "GraphContainerGUI.hpp"

Network::Network(bool display) :
  AModule(display, "Network Usage :\n")
{
  _container = NULL;
  _prev_data_in = 0;
  _prev_data_out = 0;
  refresh();
}

Network::Network(bool display, Font &font) :
  AModule(display, "Network Usage :\n")
{
  _prev_data_in = 0;
  _prev_data_out = 0;
  _container = new GraphContainerGUI((Pos){800, 450}, 400, 400, _title, font, 0);
  refresh();
}

Network::Network(const Network &cpy) :
  AModule(cpy)
{
  _data_out = cpy._data_out;
  _data_in = cpy._data_in;
  _data = cpy._data;
}

Network&	Network::operator=(const Network &cpy)
{
  _data_out = cpy._data_out;
  _data_in = cpy._data_in;
  _data = cpy._data;
  _display = cpy.getDisplay();
  _title = cpy.getTitle();
  _info = cpy.getInfo();
  return (*this);
}

int		Network::refresh()
{
  std::ifstream	file;

  if (!_display)
    return (0);
  try
    {
      file.open("/proc/net/dev", std::ifstream::in);
      _data = file.get();
      while (file.good())
	_data += file.get();
      getData();
      file.close();
      format();
    }
  catch (std::exception const &e)
    {
      std::cerr << "Module Network : " << e.what() << std::endl;
    }
  return (0);
}

void			Network::format()
{
  std::stringstream	ss;

  ss << "\tData received : " << _data_in - _prev_data_in
     << " Kb" << std::endl << "\tData sent : " << _data_out - _prev_data_out << " Kb" << std::endl;
  setInfo(ss.str());
  _prev_data_in = _data_in;
  _prev_data_out = _data_out;
  if (_container)
    {
      _container->setInfo(ss.str(), (Pos){2, 2});
      if (_data_in - _prev_data_in > static_cast<GraphContainerGUI *>(_container)->getMax())
	static_cast<GraphContainerGUI *>(_container)->setMax(_data_in - _prev_data_in);
      static_cast<GraphContainerGUI *>(_container)->pushData(_data_in - _prev_data_in);
    }
}

void		Network::getData()
{
   size_t	pos = 0;
   std::string	tmp;
   int		i;

   pos = _data.find("wlo1:");
   while (_data[pos] != ':')
     pos++;
   pos++;
   while (_data[pos] == ' ' || _data[pos] == '\t')
     pos++;
   while (_data[pos] != ' ' && _data[pos] != '\t')
     tmp += _data[pos++];
   _data_in = (std::atof(tmp.c_str())) / 1024;
   pos++;
   while (_data[pos] == ' ' || _data[pos] == '\t')
     pos++;
   tmp.clear();
   i = 0;
   while (i < 6)
     {
       while (_data[pos] != ' ' && _data[pos] != '\t')
	 pos++;
       while (_data[pos] == ' ' || _data[pos] == '\t')
	 pos++;
       pos++;
       i++;
     }
   while (_data[pos] == ' ' || _data[pos] == '\t')
     pos++;
   while (_data[pos] != ' ' && _data[pos] != '\t')
     tmp += _data[pos++];
   _data_out = (std::atof(tmp.c_str())) / 1024;
   tmp.clear();
}
