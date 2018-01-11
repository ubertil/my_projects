/*
** Pool.hh for plazza in /home/login_p/delivery/plazza/Pool.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 11:43:44 2017 Alexis Papadimitriou
// Last update Mon Apr 24 22:01:46 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <atomic>
# include <functional>
# include <memory>
# include <string>
# include <vector>
# include "Information.hh"
# include "SafeQueue.hpp"
# include "Thread/Thread.hpp"
# include "Thread/CondVar.hpp"

namespace Plazza
{
    namespace Thread
    {
        class Pool
        {
        private:
            std::vector<std::pair<std::unique_ptr<Plazza::Thread::Thread>, bool> > 	                    workers;
            std::unique_ptr<Plazza::SafeQueue<std::pair<const std::string, const Information> > >       jobQueue;
            std::unique_ptr<Plazza::Thread::CondVar>                                	                condition;
            std::atomic<bool> 							                                                running;
            std::atomic<bool>                                                                           destruct;
            const std::size_t 							                                                _nb_workers;
            std::mutex                                                                                  lock;

            void    setThreadStatus(const std::size_t i, bool status);

        public:
            Pool(const size_t nb_worker);
            Pool(const Pool &cpy) = delete;
            ~Pool();
            Pool    &operator=(const Pool &cpy) = delete;

            void            stopWorking();
            bool            canAdd() const;
            std::size_t     getNbTask() const;
            int	            getNbWorking() const;
            bool 	        getStatus() const;
            bool            addJob(const std::string &file, const Information &type);
        };
    };
};
