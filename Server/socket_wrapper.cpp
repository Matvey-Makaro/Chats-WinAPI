#include "socket_wrapper.h"

#include <stdexcept>
#include <string>
using namespace std;

SocketWrapper::SocketWrapper(SOCKET socket) :
  _socket(socket)
{
  /*if (_socket == INVALID_SOCKET)
    throw runtime_error("Socket creation failed! " + std::to_string(WSAGetLastError()));*/
}

SocketWrapper::~SocketWrapper()
{
  closesocket(_socket);
}

SocketWrapper::SocketWrapper(SocketWrapper&& other) noexcept :
  _socket(other._socket)
{
  other._socket = INVALID_SOCKET;
}

SocketWrapper& SocketWrapper::operator=(SocketWrapper&& other) noexcept
{
  if (this == &other)
    return *this;

  _socket = other._socket;
  other._socket = INVALID_SOCKET;

  return *this;
}

SocketWrapper& SocketWrapper::operator=(SOCKET socket)
{
  if (_socket != INVALID_SOCKET)
    closesocket(_socket);

  _socket = socket;
  return *this;
}

SocketWrapper::operator SOCKET() const
{
  return _socket;
}
