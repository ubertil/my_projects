//
// ComputerInfo.hpp for ComputerInfo in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/include
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:57:47 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:50:44 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <cstdlib>
# include "AModule.hpp"

class				OS : public AModule
{
private:
  std::string			_os;
  std::string			_kernel;
public:
  OS(bool);
  OS(bool, Font &);
  OS(const OS &);
  ~OS() {};
  OS&				operator=(const OS &);
  void				format();
  void				renderGUI() const;
  std::string const		&getOS() const;
  std::string const		&getKernel() const;
  int				refresh();
};
