//
// ComputerInfo.hpp for ComputerInfo in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/include
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:57:47 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:48:55 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <ctime>
# include <cstdlib>
# include <fstream>
# include "AModule.hpp"

class				Date : public AModule
{
private:
  std::string			_date;
  std::string			_uptime;
public:
  Date(bool);
  Date(bool, Font &);
  Date(const Date &);
  ~Date() {};
  Date&				operator=(const Date &);
  void				format();
  int				refresh();
  std::string const		&getDate() const;
  std::string const		&getUptime() const;
};
