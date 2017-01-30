//
// RAM.hpp for RAM.hpp in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:06:24 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:51:00 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <map>
# include "AModule.hpp"

class					RAM : public AModule
{
private:
  std::map<int, double>			_ram;
public:
  RAM(bool);
  RAM(bool, Font &);
  RAM(const RAM &);
  ~RAM() {};
  RAM&					operator=(const RAM &);
  int					refresh();
  void					format();
  void					renderGUI() const;
  std::string const			showBar(double, double, double) const;
  std::map<int, double> const		&getRAM() const;
};
