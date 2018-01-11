//
// CPU.hpp for CPU.hpp in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:06:24 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:48:38 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <map>
# include <vector>
# include "AModule.hpp"

class					CPU : public AModule
{
private:
  std::vector<double>			_cores;
  std::map<int, long double>		_usage;
  std::string				_cpu;
  std::string				_loadavg;
  int					_nb;
public:
  CPU(bool);
  CPU(bool, Font &);
  CPU(const CPU &);
  ~CPU() {};
  CPU&					operator=(const CPU &);
  void					format();
  int					refresh();
  std::string const			&getCPU() const;
  std::string const			&getLoad() const;
  std::vector<double> const		&getCores() const;
  void					getUsage();
  int					getNB() const;
};
