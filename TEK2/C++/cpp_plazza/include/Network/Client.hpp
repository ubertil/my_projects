/*
** Client.hh for plazza in /home/login_p/delivery/plazza/Client.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Wed Apr 26 13:47:31 2017 Alexis Papadimitriou
// Last update Sun Apr 30 21:09:18 2017 Lous-Emile Uberti-Ares
*/
#pragma once
# include <string>
# include <sys/socket.h>
# include "Error.hpp"

namespace Plazza
{
    namespace Network
    {
	class Client
	{
	private:
	    int			_sock_id;
	    std::string	    _hostname;
	    unsigned short	_port;

	public:
	    Client(std::string const &hostname, unsigned short port);
	    Client(const Client &cpy) = delete;
	    ~Client();

	    Client &operator=(const Client &cpy) = delete;

	    template<typename T>
	    void sendData(const T &data, int size) const
	    {
		if (send(this->_sock_id, &data, size, 0) != size)
		    throw SocketError("Failed to send data");
	    }

	    template<typename T>
	    void receiveData(T &data, int size) const
	    {
		if (recv(this->_sock_id, &data, size, 0) != size)
		    throw SocketError("Failed to receive data");
	    }
	};
    }
}
