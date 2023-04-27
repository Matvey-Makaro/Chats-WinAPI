#include "client.h"

#include <iostream>
using namespace std;

int main()
{
  cout << "Hello world!" << endl;
  Client client("client", "127.0.0.1", 8889);
  return 0;
}