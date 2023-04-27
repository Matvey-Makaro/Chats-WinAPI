#pragma once

#include <WinSock2.h>

class Server
{
public:
  Server(int port);
  ~Server() = default;

  Server(const Server& other) = delete;
  Server& operator=(const Server& other) = delete;
  Server(Server&& other) = delete;
  Server& operator=(Server&& other) = delete;

  void run();


private:
  void winsock_init();
  void fill_addr();

private:
  int _port;
  SOCKADDR_IN _addr;
  SOCKET listener;
};

