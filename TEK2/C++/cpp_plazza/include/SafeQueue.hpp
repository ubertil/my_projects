/*
** SafeQueue.hpp for plazza in /home/uberti_p/delivery/plazza/SafeQueue.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  ven. avr. 28 14:40:54 2017 Louis-Emile Uberti-Arès
** Last update ven. avr. 28 14:40:54 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <mutex>
# include <queue>

namespace Plazza
{
    template <typename T>
    class SafeQueue
    {
    public:
        SafeQueue() = default;
        ~SafeQueue() = default;
        SafeQueue(const SafeQueue &cpy) = delete;
        SafeQueue& operator=(const SafeQueue &cpy) = delete;

        T                    front()
        {
            std::unique_lock<std::mutex>    lock(this->queueMutex);
            return (this->queue.front());
        }

        void                    pop()
        {
            std::unique_lock<std::mutex>    lock(this->queueMutex);
            if (!this->queue.empty())
                this->queue.pop();
        }

        void                 add(const T &elem)
        {
            std::unique_lock<std::mutex>    lock(this->queueMutex);
            this->queue.emplace(elem);
        }

        bool                 empty()
        {
            std::unique_lock<std::mutex>    lock(this->queueMutex);
            return (this->queue.empty());
        }

        unsigned long        size()
        {
            std::unique_lock<std::mutex>    lock(this->queueMutex);
            return (this->queue.size());
        }
    private:
        std::queue<T>        queue;
        std::mutex           queueMutex;
    };
};