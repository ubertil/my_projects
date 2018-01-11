/*
** Process.hh for plazza in /home/login_p/delivery/plazza/Process.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 11:39:18 2017 Alexis Papadimitriou
// Last update Sat Apr 29 17:10:39 2017 Lous-Emile Uberti-Ares
*/
#pragma once
# include <memory>
# include <atomic>
# include "Process/IForkable.hh"
# include "Thread/Pool.hh"
# include "Network/Client.hpp"

namespace Plazza
{
    namespace Process
    {
        class Process final : public IForkable
        {
        private:
            std::queue<std::pair<std::string, Information>>	_cmd_queue;
            const size_t					                _nb_workers;
            Network::Client					                _client;
            std::atomic<bool>                               _quit;

        public:
            Process(const size_t nb_workers, unsigned short port);
            Process(const Process &cpy) = delete;
            ~Process();

            Process &operator=(const Process &cpy) = delete;

            void run() override;
        };
    }
}
