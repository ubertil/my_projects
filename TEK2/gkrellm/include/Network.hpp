//
// Network.hpp for Network in /home/grella_f/piscine_c++/cpp_gkrellm
//
// Made by félix grellard
// Login   <grella_f@epitech.net>
//
// Started on  Sat Jan 21 09:53:06 2017 félix grellard
// Last update Sun Jan 22 05:51:57 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include "AModule.hpp"

class			Network : public AModule
{
private :
  long double		_data_out;
  long double		_data_in;
  long double		_prev_data_out;
  long double		_prev_data_in;
  std::string		_data;

public :
  Network(bool);
  Network(bool, Font &);
  Network(const Network &);
  ~Network() {};
  Network&		operator=(const Network &);
  int			refresh();
  void			format();
  void			getData();
};
