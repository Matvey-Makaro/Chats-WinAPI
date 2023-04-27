#pragma once

#include <string>
#include <WinSock2.h>

class Client
{
public:
  Client(std::string name, std::string server_ip, int server_port);
  ~Client();

  Client(const Client& other) = delete;
  Client& operator=(const Client& other) = delete;

  Client(Client&& other) = delete;
  Client& operator=(Client&& other) = delete;

private:
  void winsock_init();

private:
  std::string _name;
  std::string _server_ip;
  int _server_port;
};

