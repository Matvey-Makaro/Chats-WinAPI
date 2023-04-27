#pragma comment(lib, "ws2_32.lib")

#include "client.h"

#include <utility>
#include <stdexcept>
#include <WS2tcpip.h>
using namespace std;

Client::Client(std::string name, std::string server_ip, int server_port) :
  _name(move(name)), _server_ip(move(server_ip)), _server_port(server_port)
{
  winsock_init();
}

Client::~Client()
{
  WSACleanup();
}

void Client::winsock_init()
{
  WSAData wsaData;
  WORD DLLVersion = MAKEWORD(2, 1);
  if (WSAStartup(DLLVersion, &wsaData) != 0)
    throw runtime_error("WSAStartup failed!");
}
