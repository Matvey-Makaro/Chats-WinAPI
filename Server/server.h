#pragma once

#include "socket_wrapper.h"

#include <WinSock2.h>

class Server
{
public:
  Server(int port);
  ~Server();

  Server(const Server& other) = delete;
  Server& operator=(const Server& other) = delete;
  Server(Server&& other) = delete;  // TODO: Implement when it is clear what needs to be moved.
  Server& operator=(Server&& other) = delete; // TODO: Implement when it is clear what needs to be moved.

  void run();


private:
  void winsock_init();
  void fill_addr();
  void create_listener();

private:
  int _port;
  SOCKADDR_IN _addr;
  SocketWrapper _listener;
};

