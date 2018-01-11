/*
** Client.cpp for plazza in /home/login_p/delivery/plazza/Client.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Wed Apr 26 13:51:15 2017 Alexis Papadimitriou
// Last update Sat Apr 29 12:42:42 2017 Lous-Emile Uberti-Ares
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <netdb.h>
#include <iostream>
#include "Network/Client.hpp"

Plazza::Network::Client::Client(std::string const &hostname, unsigned short port) :
  _sock_id(socket(AF_INET, SOCK_STREAM, 0)), _hostname(hostname), _port(port)
{
  struct sockaddr_in config;
  struct hostent *hostinfo = nullptr;

  std::memset(&config, 0, sizeof(config));
  if ((hostinfo = gethostbyname(this->_hostname.c_str())) == nullptr)
    throw SocketError("Cannot find host :" + this->_hostname);
  config.sin_addr = *reinterpret_cast<struct in_addr *>(hostinfo->h_addr);
  config.sin_port = htons(this->_port);
  config.sin_family = AF_INET;
  if (connect(this->_sock_id, reinterpret_cast<struct sockaddr *>(&config), sizeof(config)) == -1)
    throw SocketError("Failed to connect to the server");
}

Plazza::Network::Client::~Client()
{
  close(this->_sock_id);
}
