/*
** UI.hh for plazza in /home/uberti_p/delivery/plazza/UI.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. avr. 29 12:20:55 2017 Louis-Emile Uberti-Arès
** Last update sam. avr. 29 12:20:55 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <functional>
# include <string>
# include <unordered_map>
# include "Process/ProcessManager.hh"
# define GREEN "\e[32m"
# define DEFAULT "\e[0m"

namespace Plazza
{
    class UI
    {
    public:
        UI(const std::size_t nb_workers, const std::unordered_map<int, std::pair<pid_t, Process::Status>> &process_list);
        ~UI() = default;

        void            help() const;
        bool            getCommand(std::string &);
        void            listDir() const;
        void            displayStatus() const;
    private:
        std::unordered_map<std::string, std::function<void()> >                 m_commands;
        const std::unordered_map<int, std::pair<pid_t, Process::Status>>	    &m_process_list;
        std::string                                                             m_cmd;
        std::size_t                                                             m_nb_workers;
        std::size_t                                                             m_delim;
    };
};
