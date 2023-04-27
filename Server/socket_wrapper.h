#pragma once

#include <WinSock2.h>

class SocketWrapper
{
public:
  SocketWrapper(SOCKET socket = INVALID_SOCKET);
  ~SocketWrapper();

  SocketWrapper(const SocketWrapper& other) = delete;
  SocketWrapper& operator=(const SocketWrapper& other) = delete;

  SocketWrapper(SocketWrapper&& other) noexcept;
  SocketWrapper& operator=(SocketWrapper&& other) noexcept;

  SocketWrapper& operator=(SOCKET socket);



  operator SOCKET() const;  // TODO: Or make a get() method.

private:
  SOCKET _socket;
};

