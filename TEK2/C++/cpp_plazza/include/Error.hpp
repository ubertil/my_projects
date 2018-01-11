/*
** Error.hpp for plazza in /home/uberti_p/delivery/plazza/Error.hpp
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

namespace Plazza
{
    class Error : public std::exception
    {
    public:
        Error(const std::string &error) :
                _error(error) {}

        ~Error() throw() {}

        const char *what() const throw() { return (_error.c_str()); }

    protected:
        const std::string _error;
    };

    class SocketError: public Error
    {
    public:
        SocketError(const std::string &error) :
                Error(error) {};
    };

    class ThreadError : public Error
    {
    public:
        ThreadError(const std::string &error) :
                Error(error) {};
    };
};