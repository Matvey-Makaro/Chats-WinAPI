#pragma comment(lib, "ws2_32.lib")

#include "server.h"

#include <stdexcept>
using namespace std;


Server::Server(int port) :
  _port(port)
{
}

void Server::run()
{
  winsock_init();
  fill_addr();
}

void Server::winsock_init()
{
  WSAData wsaData;
  WORD DLLVersion = MAKEWORD(2, 1);
  if (WSAStartup(DLLVersion, &wsaData) != 0)
    throw runtime_error("WSAStartup failed!");
}

void Server::fill_addr()
{
  /*if (InetPton(AF_INET, L"127.0.0.1", &_addr.sin_addr) == 0)
    throw runtime_error("InetPton failed!");*/
  //_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  _addr.sin_port = htons(_port);
  _addr.sin_family = AF_INET;
}
