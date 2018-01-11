/*
** Core.hh for plazza in /home/login_p/delivery/plazza/Core.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 11:26:35 2017 Alexis Papadimitriou
** Last update Mon Apr 24 11:26:35 2017 Alexis Papadimitriou
*/

#pragma once
# include <unordered_map>
# include <queue>
# include <regex>
# include <string>
# include <memory>
# include "Process/ProcessManager.hh"
# include "Information.hh"

namespace Plazza
{
    class Core
    {
    private:
        const std::size_t 					              _nb_workers;
        std::unordered_map<std::string, Information> 	  _info_type;
        std::queue<std::pair<std::string, Information> >  _cmd_queue;
        std::unique_ptr<Process::Manager> 			      _manager;
        std::regex						                  _sanitizer;
        std::regex						                  _separator;

        bool getCommand();
        void manageCommandList(const std::string &input);
        void processCommand(const std::string &command);

    public:
        Core(const std::size_t nb_workers);
        Core(const Core &cpy) = delete;
        ~Core() = default;

        Core &operator=(const Core &cpy) = delete;

        void run();
    };
}