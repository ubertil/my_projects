/*
** Controller.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Controller.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mar. févr. 07 11:10:09 2017 Louis-Emile Uberti-Arès
** Last update mar. févr. 07 11:10:09 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <memory>
# include "Parser.hpp"

namespace nts
{
    class           Controller
    {
    public:
        Controller();
        ~Controller() {};
        int         usage() const;
        void        handleCMD(const std::string &cmd, bool verbose);
        void        readFeed(const std::string &file, bool error);
        void        run(int ac, const char **av);
        void        loop();
        void        load(const std::string &cmd);
    private:
        std::string                                                 _oldfile;
        std::unordered_map<std::string, std::function<void()> >     _actions;
        std::vector<std::string>                                    _content;
        std::unique_ptr<nts::Parser>                                _parser;
    };
};