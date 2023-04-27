#pragma once

#include <WinSock2.h>

class SocketWrapper
{
public:
  SocketWrapper(SOCKET socket);
  ~SocketWrapper();

  SocketWrapper(const SocketWrapper& other) = delete;
  SocketWrapper& operator=(const SocketWrapper& other) = delete;

  SocketWrapper(SocketWrapper&& other);
  SocketWrapper& operator=(SocketWrapper&& other);

  operator SOCKET() const;  // TODO: Или сделать метод get().

private:
  SOCKET _socket;
};

