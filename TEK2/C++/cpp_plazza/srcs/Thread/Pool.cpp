//
// Pool.cpp for Pool in /home/uberti_l/rendu/Prog_Elem/cpp_plazza
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Mon Apr 24 15:00:51 2017 Lous-Emile Uberti-Ares
// Last update Mon Apr 24 22:30:32 2017 Lous-Emile Uberti-Ares
//

#include <chrono>
#include "Thread/Pool.hh"

Plazza::Thread::Pool::Pool(const std::size_t nb_workers) :
  running(true), destruct(false), _nb_workers(nb_workers)
{
    this->condition = std::make_unique<Plazza::Thread::CondVar>();
    this->jobQueue = std::make_unique<Plazza::SafeQueue<std::pair<const std::string, const Information>>>();
    for (std::size_t i = 0; i <= this->_nb_workers; ++i)
        this->workers.emplace_back(std::make_pair<std::unique_ptr<Plazza::Thread::Thread>, bool>(std::make_unique<Plazza::Thread::Thread>(), false));
    for (std::size_t i = 0; i <= this->_nb_workers; ++i)
        this->workers.at(i).first->run([this, i]() {
            for (;;)
            {
                std::pair<std::string, Information> jobInfo;
                {
                    std::unique_lock<std::mutex> padlock(this->lock);
                    if (this->condition->waitFor(padlock, std::chrono::seconds(5), [this] { return (!this->jobQueue->empty() || this->getNbWorking() > 0 || !this->running); }))
                    {
                        if (!this->running)
                            return ;
                        if (!this->jobQueue->empty())
                        {
                            jobInfo = this->jobQueue->front();
                            this->jobQueue->pop();
                            padlock.unlock();
                            this->setThreadStatus(i, true);
                            jobInfo.second >> jobInfo.first;
                            this->setThreadStatus(i, false);
                        }
                    }
                    else
                    {
                        this->running = false;
                        return ;
                    }
                }
            }
        });
}

void    Plazza::Thread::Pool::setThreadStatus(const std::size_t i, bool status)
{
    this->workers.at(i).second = status;
}

bool    Plazza::Thread::Pool::canAdd() const
{
    return (this->jobQueue->size() <= 2 * this->_nb_workers);
}

bool    Plazza::Thread::Pool::addJob(const std::string &file, const Information &type)
{
    if (this->running && this->jobQueue->size() <= 2 * this->_nb_workers)
    {
        this->jobQueue->add(std::make_pair<std::string, Information>(static_cast<std::string>(file), static_cast<Information>(type)));
        this->condition->notifyOne();
        return (true);
    }
    return (false);
}

int     Plazza::Thread::Pool::getNbWorking() const
{
    int nb_workers = 0;

    for (auto const &worker : this->workers)
        if (worker.second)
            nb_workers++;
    return (nb_workers);
}

std::size_t     Plazza::Thread::Pool::getNbTask() const
{
    return (this->jobQueue->size());
}

bool 	Plazza::Thread::Pool::getStatus() const
{
  return (this->running);
}

void    Plazza::Thread::Pool::stopWorking()
{
    this->destruct = true;
    this->running = false;
    this->condition->wakeAll();
    for (auto const &worker : this->workers)
        worker.first->join();
}

Plazza::Thread::Pool::~Pool()
{
    if (!this->destruct)
        this->stopWorking();
}
