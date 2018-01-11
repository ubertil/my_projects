/*
** Server.hh for plazza in /home/login_p/delivery/plazza/Server.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Wed Apr 26 11:19:55 2017 Alexis Papadimitriou
// Last update Sun Apr 30 21:10:53 2017 Lous-Emile Uberti-Ares
*/
#pragma once
# include <vector>
# include <sys/socket.h>
# include "Error.hpp"

namespace Plazza
{
    namespace Network
    {
	class Server
	{
	private:
	    int                 _sock_id;
	    unsigned short      _port;
	    int                 _nb_client;
	    std::vector<int>    _client_sock_id_list;

	public:
	    Server(unsigned short port, int nb_client);
	    Server(const Server &cpy) = delete;
	    ~Server();

	    Server &operator=(const Server &cpy) = delete;

	    unsigned short getPort() const;

	    int  waitClient();

	    template<typename T>
	    void sendData(int sock_id, const T &data, int size) const
	    {
		if (send(sock_id, &data, size, 0) != size)
		    throw SocketError("Failed to send data");
	    }

	    template<typename T>
	    void receiveData(int sock_id, T &data, int size) const
	    {
		if (recv(sock_id, &data, size, 0) != size)
		    throw SocketError("Failed to receive data");
	    }
	};
    }
}
