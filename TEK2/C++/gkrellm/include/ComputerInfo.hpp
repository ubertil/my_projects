//
// ComputerInfo.hpp for ComputerInfo in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/include
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 00:57:47 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:48:13 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <cstdlib>
# include "AModule.hpp"

class				ComputerInfo : public AModule
{
private:
  std::string			_hostName;
  std::string			_userName;
public:
  ComputerInfo(bool);
  ComputerInfo(bool, Font &);
  ComputerInfo(const ComputerInfo &);
  ~ComputerInfo() {};
  ComputerInfo&			operator=(const ComputerInfo &);
  void				format();
  int				refresh();
  std::string const		&getHostName() const;
  std::string const		&getUserName() const;
};
