/*
** Information.hh for plazza in /home/login_p/delivery/plazza/Information.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 11:34:53 2017 Alexis Papadimitriou
** Last update Mon Apr 24 11:34:53 2017 Alexis Papadimitriou
*/

#pragma once
# include <fstream>
# include <regex>
# include <iostream>

enum Information
{
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
};

inline std::ostream&	operator<<(std::ostream &os, const Information &info)
{
    switch (info)
    {
        case (Information::PHONE_NUMBER) :
            os << "PHONE_NUMBER";
            return (os);
        case (Information::EMAIL_ADDRESS) :
            os << "EMAIL_ADDRESS";
            return (os);
        case (Information::IP_ADDRESS) :
            os << "IP_ADDRESS";
            return (os);
    }
}

inline void		operator>>(const Information &type, const std::string &filename)
{
    std::ifstream	file(filename.c_str(), std::ifstream::in);
    std::regex	regex("");
    std::string	line;
    std::smatch	match;

    if (!file.good() && !filename.empty())
    {
        std::cerr << "File '" << filename.c_str() << "' not found" << std::endl;
        return ;
    }
    switch (type)
    {
        case (Information::EMAIL_ADDRESS) :
            regex = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
            break;
        case (Information::PHONE_NUMBER) :
            regex = "(\\s{0,1}[0-9]{2}){5}";
            break;
        case (Information::IP_ADDRESS) :
            regex = "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)";
            break;
    }
    while (std::getline(file, line))
    {
        while (std::regex_search(line, match, regex))
        {
            std::cout << match[0] << std::endl;
            line = match.suffix().str();
        }
    }
    file.close();
}