#pragma comment(lib, "ws2_32.lib")

#include "server.h"

#include <stdexcept>
#include <string>
#include <WS2tcpip.h>
using namespace std;


Server::Server(int port) :
  _port(port)
{
  // TODO: Add a check for a valid port number.
  winsock_init();
  fill_addr();
  create_listener();
}

Server::~Server()
{
  // TODO: Implement destructor.
  WSACleanup();
}

void Server::run()
{
  
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
  if (InetPton(AF_INET, L"127.0.0.1", &_addr.sin_addr) == 0)
    throw runtime_error("InetPton failed!");
  _addr.sin_port = htons(_port);
  _addr.sin_family = AF_INET;
}

void Server::create_listener()
{
  _listener = socket(AF_INET, SOCK_STREAM, NULL);
  if (_listener == INVALID_SOCKET)
    throw runtime_error("Socket creation failed! Error: " + to_string(WSAGetLastError()));

  if(bind(_listener, reinterpret_cast<SOCKADDR*>(&_addr), sizeof(_addr)) != 0)
    throw runtime_error("Bind failed! Error: " + to_string(WSAGetLastError()));

  if(listen(_listener, SOMAXCONN) != 0)
    throw runtime_error("Listen failed! Error: " + to_string(WSAGetLastError()));
}
