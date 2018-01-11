/*
** nts::Error.hpp for cpp_nanotekspice in /home/uberti_p/delivery/cpp_nanotekspice/nts::Error.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. févr. 01 14:49:20 2017 Louis-Emile Uberti-Arès
** Last update mer. févr. 01 14:49:20 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <string>
# include <exception>
# define USAGE ("./nanotekspice file.nts [[INPUTS=x] [...]].")
# define BOLD "\e[1m"
# define GREEN "\e[30;48;5;82m"
# define BASIC "\e[0m"

namespace nts
{
    extern int timer;
    class Error : public std::exception
    {
    public:
        Error(const std::string &message) :
                _message(message) {}
        virtual ~Error() throw() {}
        const char *what() const throw() { return (_message.c_str()); }
    protected:
        const std::string _message;
    };

    class ComponentError : public Error
    {
    public:
        ComponentError(std::string const &message) :
            Error(message) {}
    };

    class CommandLineError : public Error
    {
    public:
        CommandLineError(std::string const &message) :
                Error(message) {}
    };

    class InputError : public nts::Error
    {
    public:
        InputError(std::string const &message) :
                Error(message) {}
    };

    class ExecError : public Error
    {
    public:
        ExecError(std::string const &message) :
                Error(message) {}
    };
}