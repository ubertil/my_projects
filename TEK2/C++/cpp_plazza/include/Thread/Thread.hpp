//
// Thread.hpp for Thread in /home/uberti_l/rendu/Prog_Elem/cpp_plazza
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Mon Apr 24 22:14:30 2017 Lous-Emile Uberti-Ares
// Last update Mon Apr 24 22:29:43 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <future>
# include <exception>
# include <functional>
# include <memory>
# include <thread>

namespace Plazza
{
    namespace Thread
    {
        class Thread
        {
        public:
            Thread() = default;
            ~Thread() = default;
            Thread(const Thread &) = delete;
            Thread &operator=(const Thread &) = delete;

            template<class F, class... Args>
            auto run(F &&f, Args &&... args) -> std::future<typename std::result_of<F(Args...)>::type>
            {
                auto task = std::packaged_task<typename std::result_of<F(Args...)>::type()>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
                std::future<typename std::result_of<F(Args...)>::type> ret;

                ret = task.get_future();
                this->thread = std::thread(std::move(task));
                this->running = true;
                return (ret);
            };

            void join()
            {
                if (this->running)
                    this->thread.join();
            }

            std::thread::id getId() const
            {
                return (this->thread.get_id());
            }

        private:
            bool running;
            std::thread thread;
        };
    }
}
