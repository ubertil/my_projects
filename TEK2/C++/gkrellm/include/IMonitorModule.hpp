//
// IMonitorModule.hpp for IMonitorModule in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/include
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:00:07 2017 Lous-Emile Uberti-Ares
// Last update Sat Jan 21 23:32:49 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <exception>
# include <iomanip>
# include <string>
# include <sstream>
# include <iostream>

class			IMonitorModule
{
public:
  IMonitorModule() {};
  virtual ~IMonitorModule() {};
  virtual int		refresh() = 0;
  virtual void		dump() const = 0;
  virtual void		format() = 0;
  //virtual void		render() const = 0;
};
