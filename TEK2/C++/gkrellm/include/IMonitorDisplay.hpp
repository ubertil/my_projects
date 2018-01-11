//
// IMonitorDisplay.hpp for IMonitorDisplay in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/include
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:00:07 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:52:08 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <ncurses.h>

class			IMonitorDisplay
{
public:
  IMonitorDisplay() {};
  virtual ~IMonitorDisplay() {};
  virtual void		renderNcurses() const = 0;
  virtual bool		getDisplay() const = 0;
};
