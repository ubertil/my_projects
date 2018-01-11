/*
** Error.hpp for Hyper Sprint in /home/uberti_p/delivery/Sprint/Error.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. avr. 27 16:03:12 2017 Louis-Emile Uberti-Arès
** Last update jeu. avr. 27 16:03:12 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <string>
# include <stdexcept>

namespace Sprint
{
  namespace Error
  {
    class Error : public std::exception
    {
     public:
      Error(const std::string &error) :
       _error(error)
      {
      }

      ~Error() throw()
      {
      }

      const char *what() const throw()
      {
	return (_error.c_str());
      }

     protected:
      const std::string _error;
    };

    class GameError : public Error
    {
     public:
      GameError(const std::string &error) :
       Error(error)
      {
      };
    };

    class UtilError : public Error
    {
     public:
      UtilError(const std::string &error) :
       Error(error)
      {
      };
    };

    class SoundError : public Error
    {
     public:
      SoundError(const std::string &error) :
       Error(error)
      {
      };
    };
  }
}