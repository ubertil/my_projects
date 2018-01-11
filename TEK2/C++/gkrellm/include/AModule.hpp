//
// AModule.hpp for AModule in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sat Jan 21 23:11:18 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 05:21:53 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include "ContainerGUI.hpp"

class				AModule : public IMonitorModule,
					  public IMonitorDisplay
{
protected:
  bool				_display;
  std::string			_title;
  std::string			_info;
  ContainerGUI			*_container;
public:
  AModule(bool, const std::string &);
  AModule(const AModule &);
  ~AModule() {};
  AModule&			operator=(const AModule &);
  virtual void			format() = 0;
  void				dump() const;
  void				renderNcurses() const;
  virtual int			refresh() = 0;
  void				setInfo(const std::string &);
  void				setTitle(const std::string &);
  bool				getDisplay() const;
  std::string const		&getInfo() const;
  std::string const		&getTitle() const;
  ContainerGUI			*getContainer() const;
};
