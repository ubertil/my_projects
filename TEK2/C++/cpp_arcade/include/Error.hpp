/*
** Error.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Error.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. mars 18 21:30:58 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 16:09:51 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <exception>
# include <string>
# define USAGE ("./arcade /path/to/libgame.so")
# define BOLD "\e[1m"
# define BASIC "\e[0m"

namespace arcade
{
  class Error : public std::exception
  {
  public:
    Error(const std::string &error) :
      _error(error) {}
    ~Error() throw() {}
    const char		*what() const throw() { return (_error.c_str()); }
  protected:
    const std::string	_error;
  };


  class GameError: public Error
  {
  public:
    GameError(const std::string &error) :
      Error(error) {}
  };

  class LibError : public Error
  {
  public:
    LibError(const std::string &error) :
      Error(error) {}
  };

  class ExecError : public Error
  {
  public:
    ExecError(const std::string &error) :
      Error(error) {}
  };
};
