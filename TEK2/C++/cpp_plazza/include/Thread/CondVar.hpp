/*
** CondVar.hpp for plazza in /home/uberti_p/delivery/plazza/CondVar.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. avr. 26 12:07:39 2017 Louis-Emile Uberti-Arès
** Last update mer. avr. 26 12:07:39 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <functional>
# include <condition_variable>
# include <memory>
# include <mutex>

namespace Plazza
{
    namespace Thread
    {
        class CondVar
        {
        public:
            CondVar()
            {
                this->condition = std::make_unique<std::condition_variable>();
            }
            ~CondVar() = default;
            CondVar(const CondVar& cpy) = delete;
            CondVar&    operator=(const CondVar& cpy) = delete;

            template <typename Predicate>
            void        waitOn(std::unique_lock<std::mutex> &lock, Predicate func)
            {
                this->condition->wait(lock, func);
            }

            void 	    wait(std::unique_lock<std::mutex> &lock) { this->condition->wait(lock); }

            template <typename Clock, typename Predicate>
            bool	waitFor(std::unique_lock<std::mutex> &lock, Clock timer, Predicate func)
            {
                return (this->condition->wait_for(lock, timer, func));
            }

            void        notifyOne() { this->condition->notify_one(); }
            void        wakeAll() { this->condition->notify_all(); }
        private:
            std::unique_ptr<std::condition_variable>    condition;
        };
    };
};
