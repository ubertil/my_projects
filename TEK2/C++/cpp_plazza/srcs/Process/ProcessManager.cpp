/*
** ProcessManager.cpp for plazza in /home/login_p/delivery/plazza/ProcessManager.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 13:43:34 2017 Alexis Papadimitriou
// Last update Sun Apr 30 21:14:51 2017 Lous-Emile Uberti-Ares
*/

#include <stdexcept>
#include <iostream>
#include "Process/ProcessManager.hh"
#include "Process/Process.hh"
#include "Process/Fork.hh"

Plazza::Process::Manager::Manager(const std::size_t nb_workers) :
  _nb_workers(nb_workers), _server(25565, 5)
{
}

Plazza::Process::Manager::~Manager()
{
  for (auto &observer : this->_observers)
    observer->join();
}

int Plazza::Process::Manager::createProcess()
{
    Plazza::Process::Process process(this->_nb_workers, this->_server.getPort());
    Plazza::Process::Fork forker(process);
    int client_id;
    int process_id;

    process_id = forker.launch();
    client_id = this->_server.waitClient();
    this->_client_list[client_id] = std::make_pair(process_id, AVAILABLE);
    this->_observers.emplace_back(std::make_unique<Thread::Thread>());
    this->_observers.back()->run([this, client_id]()
				 {
				     Status client_status;

				     while (this->_client_list[client_id].second != DEAD)
				     {
					 this->_server.receiveData<Status>(client_id, client_status, 4);
					 this->_client_list[client_id].second = client_status;
					 if (client_status == KILLME)
					     this->_server.sendData(client_id, 0, 4);
				     }
				 });
    return (client_id);
}

void Plazza::Process::Manager::killAll()
{
	for (auto const &e : this->_client_list)
		this->_server.sendData<int>(e.first, 0, 4);
}

void Plazza::Process::Manager::sendCommand(std::queue<std::pair<std::string, Information> > &cmd_queue)
{
    std::pair<std::string, Information> cmd;
    bool waiting = true;
    bool create = true;
    int client_id;

    for (auto const &client : this->_client_list)
	if (client.second.second == DEAD)
	    this->_client_list.erase(client.first);
    while (not cmd_queue.empty() and waiting)
    {
	cmd = cmd_queue.front();
	waiting = false;
	create = true;
	for (const auto &client : this->_client_list)
	{
	    if (client.second.second == AVAILABLE)
	    {
		this->sendData(client.first, cmd.first, cmd.second);
		waiting = true;
		create = false;
		cmd_queue.pop();
	    }
	    else if (client.second.second == WAITING)
	    {
		waiting = true;
		create = false;
	    }
	}
	if (create)
	{
	    client_id = this->createProcess();
	    this->sendData(client_id, cmd.first, cmd.second);
	    waiting = true;
	    cmd_queue.pop();
	}
    }
}

std::ostream&	operator<<(std::ostream &os, const Plazza::Process::Status &status)
{
    switch (status)
    {
	case (Plazza::Process::Status::DEAD) :
	    os << "Exiting...";
	    break;
	case (Plazza::Process::Status::KILLME) :
	    os << "Waiting to be destroyed...";
	    break;
	case (Plazza::Process::Status::AVAILABLE) :
	case (Plazza::Process::Status::WAITING) :
	    os << "Available";
	    break;
	case (Plazza::Process::Status::OCCUPIED) :
	    os << "Occupied";
	    break;
    }
    return (os);
}

const std::unordered_map<int, std::pair<pid_t, Plazza::Process::Status>>&    Plazza::Process::Manager::getClientList() const
{
    return (this->_client_list);
}

void Plazza::Process::Manager::sendData(int client_id, std::string const &filename, Information info)
{
    int size = filename.size();

    this->_client_list[client_id].second = WAITING;
    this->_server.sendData<int>(client_id, size, 4);
    this->_server.sendData<char>(client_id, filename[0], size);
    this->_server.sendData<Information>(client_id, info, 4);
}
