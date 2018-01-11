/*
** Process.cpp for plazza in /home/login_p/delivery/plazza/Process.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 11:39:18 2017 Alexis Papadimitriou
// Last update Sat Apr 29 17:58:37 2017 Lous-Emile Uberti-Ares
*/

#include "Process/Process.hh"
#include "Process/ProcessManager.hh"

Plazza::Process::Process::Process(const size_t nb_workers, unsigned short port) :
  _nb_workers(nb_workers), _client("localhost", port), _quit(false)
{
}

Plazza::Process::Process::~Process()
{
}

void	Plazza::Process::Process::run()
{
    std::shared_ptr<Thread::Pool> pool = std::make_shared<Thread::Pool>(this->_nb_workers);
    Thread::Thread listener;

    listener.run([this, pool]()
                 {
                     int            size;
                     std::string    cmd;
                     Information    info;

                     for (;;)
                     {
                         this->_client.receiveData<int>(size, 4);
                         if (size == 0)
                         {
                             this->_quit = true;
                             break;
                         }
                         cmd.resize(size);
                         this->_client.receiveData<char>(cmd[0], size);
                         this->_client.receiveData<Information>(info, 4);
                         pool->addJob(cmd, info);
                         if (pool->canAdd())
                             this->_client.sendData<int>(1, 4);
                         else
                             this->_client.sendData<int>(2, 4);
                     }
                 });
    for (;;)
    {
        if (!pool->getStatus() || this->_quit)
        {
            pool->stopWorking();
            this->_client.sendData<int>(4, 4);
            break;
        }
    }
    listener.join();
    this->_client.sendData<int>(0, 4);
}
