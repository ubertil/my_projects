/*
** Server.cpp for plazza in /home/login_p/delivery/plazza/Server.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Wed Apr 26 11:28:01 2017 Alexis Papadimitriou
// Last update Sat Apr 29 17:58:25 2017 Lous-Emile Uberti-Ares
*/

#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include "Network/Server.hpp"

Plazza::Network::Server::Server(unsigned short port, int nb_client) :
  _sock_id(socket(AF_INET, SOCK_STREAM, 0)), _port(port), _nb_client(nb_client)
{
  struct sockaddr_in config;

  std::memset(&config, 0, sizeof(config));
  if (this->_sock_id == -1)
    throw SocketError("Failed to create server socket");
  config.sin_addr.s_addr = htonl(INADDR_ANY);
  config.sin_port = htons(this->_port);
  config.sin_family = AF_INET;
  while (bind(this->_sock_id, reinterpret_cast<struct sockaddr *>(&config), sizeof(config)) == -1 && this->_port < 50000)
    {
      this->_port += 1;
      config.sin_port = htons(this->_port);
    }
  if (this->_port == 50000)
    throw SocketError("Failed to bind config");
  if (listen(this->_sock_id, this->_nb_client) == -1)
    throw SocketError("Failed to listen");
}

Plazza::Network::Server::~Server()
{
  for (auto &client_sock_id : this->_client_sock_id_list)
    close(client_sock_id);
  close(this->_sock_id);
}

int Plazza::Network::Server::waitClient()
{
  int client_sock_id;

  if ((client_sock_id = accept(this->_sock_id, nullptr, nullptr)) == -1)
    throw SocketError("Failed to accept client connection");
  this->_client_sock_id_list.push_back(client_sock_id);
  return (client_sock_id);
}

unsigned short Plazza::Network::Server::getPort() const
{
  return (this->_port);
}
