/*
** ProcessManager.hh for plazza in /home/login_p/delivery/plazza/ProcessManager.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 13:21:16 2017 Alexis Papadimitriou
// Last update Sun Apr 30 21:15:55 2017 Lous-Emile Uberti-Ares
*/
#pragma once
# include <queue>
# include <iostream>
# include <unistd.h>
# include <unordered_map>
# include "Information.hh"
# include "Network/Server.hpp"
# include "Thread/Thread.hpp"

namespace Plazza
{
    namespace Process
    {
	enum Status
	{
	    DEAD = 0,
	    AVAILABLE = 1,
	    OCCUPIED = 2,
	    WAITING = 3,
	    KILLME = 4
	};

	class Manager
	{
	private:
	    const std::size_t							_nb_workers;
	    Network::Server							    _server;
	    std::unordered_map<int, std::pair<pid_t, Status>>	_client_list;
	    std::vector<std::unique_ptr<Thread::Thread>>	    _observers;

	    int createProcess();

	public:
	    Manager(const std::size_t nb_workers);
	    Manager(const Manager &cpy) = delete;
	    ~Manager();

	    Manager &operator=(const Manager &cpy) = delete;

	    void killAll();
	    void sendCommand(std::queue<std::pair<std::string, Information> > &cmd_queue);
	    void sendData(int client_id, std::string const &filename, Information info);
	    const std::unordered_map<int, std::pair<pid_t, Status>>&  getClientList() const;
	};
    }
}

std::ostream&	operator<<(std::ostream &os, const Plazza::Process::Status &status);
